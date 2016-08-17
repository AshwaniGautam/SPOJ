#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<errno.h>
#include<string>
#include<string.h>
#include<unistd.h>
#include<unordered_map>

#define SUCCESS 1
#define FAILURE 0
#define conf_file "Initial.conf"                    // Configuration File

using namespace std;

int sock, cli                     ;
unsigned int len                  ;
struct sockaddr_in server, client ;
char file[50]   ;
int status_code = 200;
char root[200], extra[200]    ;
char Connection_type;
unordered_map <int, const char *>   status_dict ;
unordered_map <string, const char *> media_dict;

void chores(){

    status_dict[200] = " 200 OK\r\n"                     ;
    status_dict[400] = " 400 Bad Request\r\n"            ;
    status_dict[404] = " 404 Not Found\r\n"              ;
    status_dict[500] = " 500 Internal Server Error\r\n"  ;
    status_dict[501] = " 501 Not Implemeted\r\n"         ;

    media_dict["html"] = "text/html\r\n"     ;
    media_dict["htm"]  = "text/html\r\n"      ;
    media_dict["txt"]  = "text/plain\r\n"     ;
    media_dict["jpeg"] = "image/jpeg\r\n"    ;
    media_dict["jpg"]  = "image/jpeg\r\n"     ;
    media_dict["gif"]  = "image/gif\r\n"      ;
    media_dict["pdf"]  = "Application/pdf\r\n";
    media_dict["other"] = "Application/octet-stream\r\n";

}

void send_file(FILE *fp, int client){

    char buffer[8192]   ;
    while(!feof(fp)){
        //memset(buffer, 0, sizeof(buffer))    ;
        bzero(buffer, sizeof(buffer))   ;
        fread(buffer, 1, sizeof(buffer), fp);
        send(client, buffer, sizeof(buffer), 0)  ;
        //write(client, buffer, sizeof(buffer))   ;
    }
}



int Send_Headers(int status_code, char * type, int length, int client){

    char  http_version[] = "HTTP/1.1"          ;
    char  cont_length[]  = "Content-Length: "  ;
    char  cont_type[]    = "Content-Type: "    ;
    char  connection[]   = "Connection: "      ;
    char Whitespace[]    = "\r\n"              ;
    char buf[20], Headers[4024] ;

    memset(buf, '\0', sizeof(buf))  ;
    memset(Headers, '\0', sizeof(Headers))
              ;
    sprintf(buf, "%i\r\n", length)                      ;
    strcat(Headers, http_version)                   ;
    strcat(Headers, (status_dict[status_code]))     ;
    strcat(Headers, cont_length)                    ;
    strcat(Headers, buf)                            ;
    strcat(Headers, cont_type)                      ;
    strcat(Headers, media_dict[type])               ;
    strcat(Headers, connection)                     ;
    if (Connection_type == 'k')
        strcat(Headers, "Keep-Alive\r\n")           ;
    else
        strcat(Headers, "close\r\n")                ;
    //strcat(Headers, Whitespace)                     ;
    //strcat(Headers, Whitespace)                     ;
    cout << Headers << endl;
    send(client, Headers, sizeof(Headers), 0)       ;

    return SUCCESS;
}

char * get_file_type(char * filename){
    cout << "in file type" << filename <<endl;
    int i = 0, j = 0   ;
    for (i = 0; i < strlen(filename); i++)
        if(filename[i] == '.')
            break;
    i++ ;

    if (i == strlen(filename)){
        status_code = 400   ;
        memset(file, '\0', sizeof(file))    ;
            //cout << "Bad Request"    << endl;
        return file;
        }

    else{
        while(i < strlen(filename)){
            file[j] = filename[i] ;
              //  cout << i << " " << j << endl;
            j++    ;
            i++    ;
        }
            //cout << file << endl;
        if (media_dict.count(file)){
                //cout << "fuck" << endl  ;
            return file;
            }
        strcpy(file, "others")  ;
            //cout << "other" << endl;
        return file;
        }
    //cout << media_dict[file]    ;
    //cout << file << " " << media_dict.count(file) << endl;
}

int get_file_length(FILE * fp){
    cout << "fetched the file length" << endl;

    int length = 0;

	fseek(fp, 0, SEEK_END);
	length = ftell(fp);
	rewind(fp);
    return length;

}

void get_one_word(char *out, char *inp, int start_position){
    cout << "In one word" << endl;
    int position = 0    ;
    for (int i = start_position; i < strlen(inp); i++)
        if (inp[i] != ' '){
            out[position] = inp[i]  ;
            position ++ ;
        }
        else
            break;

    }


int process_GET(char * buffer, int client){

    char filename[512]    ;
    int status_code = 200   ;
    memset(extra, '\0', sizeof(extra)) ;
    memset(filename, '\0', sizeof(filename)) ;
    get_one_word(extra, buffer, 4) ;
//    cout << extra << endl;
//    cout << extra[strlen(extra)-1] << endl ;

    if ((extra[strlen(extra)-1] == '/'))                                // if the last character is / then append "index.html" to the filename
        sprintf(filename, "%s%s%s", root, extra, "index.html")  ;
    else
        sprintf(filename, "%s%s", root, extra)   ;

    cout << "got the filename" << endl;
    cout << filename << endl;
    char * file_type    ;
    FILE *fp    ;

    fp = fopen(filename, "rb")   ;
    if (fp == NULL){
        printf("Could not open File\n") ;
        status_code = 404;
    }
    int file_length = get_file_length(fp)       ;
    cout << "Got file length" << endl   ;

    file_type  = get_file_type(filename)   ;

    cout << "Got file type" << endl ;
    cout << file_type << endl;
    if(!file_length){
        printf("File Empty\n")  ;
        return SUCCESS  ;
        }

    int header_status = Send_Headers(status_code, file_type, file_length, client)  ;
    send_file(fp, client)  ;
    //exit(1) ;

}

int process_HEAD(char * buffer, int client){
    printf("HEAD\n")    ;
    return SUCCESS  ;
}

int process_POST(char * buffer, int client){
    printf("POST\n")    ;
    return SUCCESS  ;
}

void connection_type(char * buffer){
    string buf(buffer);
    int index = buf.find("Connection:")   ;
    cout << index << endl;
    cout << buf[index+strlen("Connection: ")] << endl;

    if (buf[index+strlen("Connection: ")] == 'k')
        Connection_type = 'k'    ;
    else
        Connection_type = 'c'    ;

}

int query_type(char * buffer){

    char inp[512]   ;
    memset(inp, '\0', sizeof(inp))  ;
    printf("%slllllfffff\n", buffer)  ;
    get_one_word(inp, buffer, 0)    ;
    printf("%s\n", inp) ;

    if (strcmp("GET", inp) == 0)
        return 1    ;

    if (strcmp("HEAD", inp) == 0)
        return 2    ;

    if (strcmp("POST", inp) == 0)
        return 3    ;

    status_code = 501   ;

    return FAILURE       ;

}

int process_client(int client){

    int type;
    char buffer[512]    ;
    memset(buffer, '\0', sizeof (buffer))   ;

    int query_length = recv(client, buffer, sizeof(buffer), 0) ;  // Recieving request from client
    if (query_length <= 0){
        status_code = 400   ;
        return FAILURE  ;
        }

    type = query_type(buffer) ;
    connection_type(buffer) ;
    cout << "Got the type " << endl;

    if (type == 1)
        return process_GET (buffer, client)   ;

    if (type == 2)
        return process_HEAD(buffer, client)    ;

    if (type == 3)
        return process_POST(buffer, client)    ;

    else
        status_code = 501   ;
        return FAILURE;
}

void Socket(){
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1 ){  /*Establishing a Socket for Server Process*/
        perror("Failed to establish Socket :(\n") ;
        exit(-1)    ;
    }
}

void Bind(int server_port){

    server.sin_family = AF_INET                 ;
    server.sin_port = htons(server_port)      ; // Server Port
    server.sin_addr.s_addr = INADDR_ANY         ;
    bzero(&server.sin_zero, 8)                  ;
    len = sizeof(struct sockaddr_in)            ;

    if ((bind (sock, (struct sockaddr *)&server, len)) == -1){                 /*Trying to Bind to the Socket*/
        perror("Failed to bind to Socket :(\n" );
        exit(-1)  ;
        }
}

void listen(){
    if (listen(sock, 1) == -1){                                   /*server process listening on the established Socket*/
        perror("Failed to Listen to client(s)\n") ;
        exit(-1)    ;
    }
}

void Connecting(){
    if ((cli = accept(sock, (struct sockaddr *)&client, &len)) == -1){
        perror("Failed to accept any client Connection\n")    ;
        exit(-1)    ;
    }

    while (1){

        int response = process_client(cli)    ;
        //cout << "got response" << endl;
        break;
        if (Connection_type == 'c')
            close(cli)  ;
        else if (response == FAILURE){
                printf("Unable to Read from Client\n")  ;
                close(cli)  ;
            }
        }
    //exit_client(cli)       ;
}

void init(int server_port){


    Socket()   ;
    Bind(server_port)     ;
    listen()   ;
    while(1)
        Connecting()  ;

}

int main(int argc, char * argv[]){

    char port[7]    ;
    FILE *fhandle   ;

    fhandle = fopen(conf_file, "r")     ;
    if (fhandle == NULL){
        printf("Error in openining Configuration File\n")   ;
        exit(1) ;
    }

    if (fscanf(fhandle, "%s %s",extra, root )  != 2)
        printf("Error reading Base Directory from configuration file.\n") ;

    /*if (fscanf(fhandle, "%s %s", extra, port ) != 2)
        printf("Error reading port number from configuration file.\n")  ;*/

    int server_port = atoi(argv[1])    ;
    /*cout << server_port << endl;
    cout << root << endl << port << endl;*/
    chores()  ;
    init(server_port);
    return 0    ;

}
