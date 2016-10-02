#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<bits/stdc++.h>
using namespace std ;
char str[35]    ;
struct node{
    int pos ;
    struct node * edge[26] ;
    bool flag    ;
    struct node *parent ;
}   ;

struct node *root   ;
struct node *initialise(){
    struct node *t  ;
    t = new node()  ;
    t -> pos = -1    ;
    for (int i = 0; i < 26; i++)
        t -> edge[i] = NULL ;
    t -> flag = false;
    t -> parent = NULL  ;
    return t    ;
}

void inserting(char *str, int n, struct node *root, int ans){
    struct node *traverse   ;
    traverse = root ;
    for(int i = n - 1; i >= 0; i--){
        if (traverse -> edge[str[i] - 'a'] == NULL){
            cout << "inserting " << str[i] << endl  ;
            struct node *new_node   ;
            new_node = new node()   ;
            new_node = initialise() ;
            if (i == 0){
                new_node -> flag = true ;
                new_node -> pos = ans   ;
            }
            new_node -> parent = traverse   ;
            traverse -> edge[str[i] - 'a'] = new_node   ;
            traverse = traverse -> edge[str[i] - 'a']   ;
        }
        else
            traverse = traverse -> edge[str[i] - 'a']   ;
            ;
    }
}
int  query(char *word, int n, struct node *root){
    struct node * traverse  ;
    traverse = root ;
    for(int i = n - 1; i >= 0; i--){
        if (traverse -> edge[str[i] - 'a'] != NULL){
            if (i != 0)
                traverse = traverse -> edge[str[i] - 'a']   ;
                if (traverse -> flag)
                    return traverse -> pos  ;
            else{

            }

        }
        else{
            while(1){
            for(int i = 0; i < 26; i++){
                if (traverse -> edge[i] != NULL){
                    traverse = traverse -> edge[str[i] - 'a']   ;
                    if (traverse -> flag = true)
                        return traverse -> pos
                    }
                }
            }
        }
    }
}
int main(){
    int length,t,p   ;
    cin >> t    ;
    root = initialise() ;
    while(t--){
        cin >> str  ;
        length = strlen(str)    ;
        inserting(str, length, root)    ;
    }
    printf("enter query word %d", p)    ;
    while(p--){
        cin >> str  ;
        int len;
        int j = query(str, len, root)   ;
        cout << j << endl   ;

    }
    return 0    ;
}
