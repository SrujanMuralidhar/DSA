#include<iostream>

using namespace std;

int evaluate_postfix(char*);
int is_operand(char);
void push(char*,int*,char);
char pop(char*,int*);
char stackTop(char*,int);


int main(){
    cout<<"Enter the postfix expression:";
    char postfix[30];
    cin>>postfix;
    int result = evaluate_postfix(postfix);
    cout<<"The result is : "<<result;
    return 0;
}

int evaluate_postfix(char* postfix){
    char stack[strlen(postfix)+1];int res;
    int i = 0, top = -1;
    while(postfix[i]){
        if(is_operand(postfix[i])){
            push(stack,&top,postfix[i]);
        }
        else{
            int operand2 = pop(stack,&top)-48;
            int operand1 = pop(stack,&top)-48;
            switch(postfix[i]){
                case '+':res =(operand1+operand2);
                push(stack,&top,res+'0');
                break;
                case '-': res = (operand1-operand2);
                push(stack,&top,res+'0');
                break;
                case '*': res = (operand1*operand2);
                push(stack,&top,res+'0');
                break;
                case '/': res = (operand1/operand2);
                push(stack,&top,res+'0');
                break;

            }
            
        }
        i++;

    }
    return pop(stack,&top)-48;
    
   
}
void push(char* stack,int* top,char ch){
    (*top)++;
    stack[*top] = ch;

}
char pop(char *stack,int* top){
    char ch = stack[*top];
    (*top)--;
    return ch;
}
int is_operand(char ch){
    if(ch >= '0' && ch <= '9'){
        return 1;
    }
    return 0;
}

char stackTop(char *stack,int top){
    return stack[top];
}
