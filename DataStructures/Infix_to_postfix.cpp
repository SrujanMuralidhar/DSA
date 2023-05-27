#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;

char* infix_to_postfix(char*);
int is_operand(char);
int precedence(char);
void push(char*,char,int*);
char pop(char*,int*);
char stackTop(char*,int);
int isEmpty(char*,int);

int main(){
    char infix[30];
    
    cout<<"Enter the infix expression:";
    cin>>infix;
    char* postfix = infix_to_postfix(infix);
    cout<<"The postfix expression is:  "<<postfix;


    return 0;

}

int precedence(char ch){
    switch(ch){
        case '#':return -1;
        case '+':
        case '-': return 1;
        case '*':
        case '/':return 2;
        case '^':
        case '$':return 3;

    }
    return 0;
}

int is_operand(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '$' ) return 0;
    else return 1;

}

char* infix_to_postfix(char* infix){
    int i = 0,j = 0;int top = -1;
    char *postfix = new char[strlen(infix)+2];
    char stack[30];
    push(stack,'#',&top);
    while(infix[i] != '\0'){
        if(is_operand(infix[i])){
            postfix[j++] = infix[i++];
        }
        else{
            if(precedence(infix[i]) >= precedence(stackTop(stack,top)))
            {
                push(stack,infix[i++],&top);
            }
            else{
                postfix[j++] = pop(stack,&top);
            }
        }
       
    }
    while(!isEmpty(stack,top)){
            postfix[j++] = pop(stack,&top);
        }
        postfix[j] = '\0';
    return postfix;

}
void push(char* stack,char ch,int* top){
    *(top)+=1;
    stack[*top] = ch;

}

char pop(char * stack,int* top){
    char ch = stack[*top];
    *(top)-=1;
    return ch;


}
int isEmpty(char* stack,int top){
   
   if(top == 0){
    return 1;
   }
   else {
    top--;
    return 0;
   }
}
char stackTop(char* stack,int top){
    return stack[top];
}