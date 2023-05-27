#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
   
    Node(int x=0){
        data = x;
        next = NULL;
    }
};
class Stack{
    Node* TOP;
public:
    Stack(){
        TOP = NULL;
    }
    void push(int data);
    void pop();
    void display();
    int peek();
};
void Stack :: push(int data){
    Node *temp = new Node(data);
    if(TOP == NULL){
        TOP = temp;
    }
    else{
        temp->next = TOP;
        TOP = temp;
       
    }
}

void Stack :: pop(){
    if(TOP == NULL){
        cout<<"Stack undeflow";
        return ;
    }
    else{
        Node* temp = TOP;
        TOP = TOP->next;
        delete temp;
    }
}

void Stack :: display(){
    if(TOP == NULL){
        cout<<"Stack is empty";
        return ;
    }
    Node* ptr = TOP;
    while(ptr){
        cout<<ptr->data<<"->";
        ptr = ptr->next;
    }
}

int Stack :: peek(){
    if(TOP == NULL){
        cout<<"Empty !";
        return ;
    }
    return TOP->data;
}

int main(){
    int data,choice;
    Stack mystack;
    while(1){
        cout<<"\nEnter your choice:\n1.To push an element\n2.To pop an element\n3.Display the stack elements\n4.To display the top element\n5. Exit\n---------->";
        cin>>choice;
        switch(choice){
            case 1:{
                cout<<"Enter the data:";
                cin>>data;
                mystack.push(data);
                break;

            }
            case 2:{
                mystack.pop();
                break;

            }
            case 3:{
                mystack.display();
                break;

            }
            case 4:{
                int peek = mystack.peek();
                cout<<"The top element is:"<<peek;
                break;

            }
            case 5:
                exit(0);
        }
    }
    return 0;
}