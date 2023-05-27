#include<iostream>
using namespace std;

class Node{
    public:
        char data;
        Node* next;
        Node(char x=0){
            data = x;
            next = NULL;
        }
};

class Stack{
    Node * TOP;
    public:
        Stack(){
        TOP = NULL;
        }
        void push(char);
        void pop();
        int check_matching(Stack*,char*);
        char stackTop();
        

};
void Stack :: push(char ch){
     Node *temp = new Node(ch);
    if(TOP == NULL){
        TOP = temp;
    }
    else{
        temp->next = TOP;
        TOP = temp;
       
    }
}

void Stack :: pop(){
        Node* temp = TOP;
        TOP = TOP->next;
        delete temp;
}

int Stack :: check_matching(Stack *s1,char *exp){
    for(int i=0;i<strlen(exp);i++){
    if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{'){
        s1->push(exp[i]);
    }
    else if((exp[i] == ')'&& s1->stackTop() )||(exp[i] == ']'&& s1->stackTop() )|| (exp[i] == '}'&& s1->stackTop())){
        if(TOP == NULL) return -1;
        s1->pop();
    }

    }
    return  TOP == NULL?  1:-1;
}

char Stack :: stackTop(){
    if(TOP == NULL){
        return -1;
    }
    return TOP->data;
}

int main(){
    Stack mystack;
    cout<<"Enter the expression:";
    char expression[100];
    cin>>expression;
    int res = mystack.check_matching(&mystack,expression);
    if (res == 1){
        cout<<"The paranthesis are matching";
    }
    else{
        cout<<"The paranthesis are not matching";
    }
   

    return 0;

}