#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

struct node{
    bool is_end ;
    struct node * child[10] ;
}  ;

struct node *initialise(){
    struct node *t  ;
    t = new node()  ;
    t -> is_end = false;
    for(int i = 0; i < 10; i++)
        t->child[i] = NULL;
    return t    ;
}

bool inserting(char *str, int n, struct node *root){
    struct node *traverse   ;
    traverse = root ;
    for(int i = 0; i < n; i++){
    if (traverse -> child[*str - '0'] == NULL){
        struct node *new_node = new node()   ;
        new_node = initialise() ;
        traverse -> child[*str - '0'] = new_node    ;
        traverse = traverse -> child[*str - '0']    ;
        if (i == n - 1){
            new_node -> is_end = true;
            return true ;
        }
    }
    else{
        traverse = traverse -> child[*str - '0']    ;
        if (i == n - 1)
        	return false	;
        if (traverse -> is_end == true){
            return false    ;
        }
    }
    str++   ;
    }
}


int main(){
    int t, n   ;
    char str[11]    ;
    cin >> t    ;
    while(t--){
    bool flag = true   ;
    struct node *root   ;
    root = initialise() ;
        cin >> n    ;
        for (int i = 0; i < n; i++){
            scanf("%s", str)    ;
            int size_of_str = strlen(str)    ;
            if (!inserting(str, size_of_str, root))
                flag = false    ;
        }

    if (flag)
        cout << "YES\n" ;
    else
        cout << "NO\n"  ;
    }
     return 0    ;
}
