#include <stdio.h>
#include <stdlib.h>

typedef struct trienode{
    int endofword;
    struct trienode* next[255];
}node;

void insertion(node* t , char* c){
    for(int i=0;c[i]!='\0';i++){
        int index = c[i];
        if(t->next[index]==NULL){
            node* temp = (node*)malloc(sizeof(node));
            temp->endofword = 0;
            t->next[index] = temp;
        }
        t = t->next[index];
    }
    t->endofword = 1;
}

void display(node* t,char word[1000] , int word_index){
    if(t->endofword == 1){
        for(int i=0;i<word_index;i++){
            printf("%c",word[i]);
        }
        printf("\n");
    }
    for(int i=0;i<255;i++){
        if(t->next[i] !=NULL){
            word[word_index] = (char)(i);
            display(t->next[i],word,word_index+1);
        }
    }
}

int check(node* t){
    int flag = 0;
    if (t->endofword == 1) return 1;
    for(int i=0;i<255;i++){
        if(t->next[i] != NULL){
            flag = 1;
            break;
        }
    }
    return flag;
}

node* deletion(node* t,char word[1000] , int i){
    if(t->endofword == 1 && word[i]=='\0'){
        t->endofword = 0;
        int flag = check(t);
        if(!flag) {
            free(t);
            t=NULL;
        }
    }

    else if(t->next[(int)word[i]] == NULL || word[i]=='\0'){
        printf("word not found :(\n");
    }
    else{
        t->next[(int)(word[i])] = deletion(t->next[(int)word[i]],word,i+1);
        if(!check(t)){
            free(t);
            t=NULL;
        }
    }
    return t;
}

int main(){
    node* trie = (node*)malloc(sizeof(node));
    for(int i=0;i<=255;i++){
        trie->next[i] = NULL;
    }
    char a[1000] = "Apple";
    insertion(trie,a);
    char b[1000] = "Apricot";
    insertion(trie,b);
    char c[1000] = "Banana";
    insertion(trie,c);
    char d[1000] = "App";
    insertion(trie,d);
    display(trie,c,0);
    deletion(trie,b,0);

    display(trie,c,0);
    return 0;
}