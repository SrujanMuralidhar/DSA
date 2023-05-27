#include<iostream>
using namespace std;

void push(int *stack,int* t,int data,int size){
    if((*t) == size-1){
        cout<<"Stack overflow!";
        return ;
    }
    else{
        (*t)++;
        stack[(*t)] = data;
    }

}   

void pop(int *stack,int* t){
    if(*t == -1){
        cout<<"Stack underflow";
        return ;
    }
    else{
        (*t)--;
        cout<<"The top element has been successfully removed ";
    }
    
}

void display(int * stack,int top){
    for(int i = top;i>-1;i--){
        cout<<stack[i]<<"\t";
    }
}

int main(){
    cout<<"Enter the size of the stack:";
    int size,data,choice,top = -1;
    cin>>size;
    int *stack ;
    stack = new int[size];
    while(1){
        cout<<"\nEnter your choice:\n1.To push an element\n2.To pop an element\n3.Display the stack elements\n4. Exit\n---------->";
        cin>>choice;
        switch(choice){
            case 1:{
                cout<<"Enter the data:";
                cin>>data;
                push(stack,&top,data,size);
                break;

            }
            case 2:{
                pop(stack,&top);
                
                break;

            }
            case 3:{
                display(stack,top);
                break;

            }
            case 4:
                exit(0);
        }
    }
    return 0;
   
}