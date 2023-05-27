#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
using namespace std;

struct Node{
    int data;
    Node* next;

};

void enqueue(Node** front ,Node** rear,int data){

    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    if(*front == NULL && *rear == NULL){
        *front = *rear = temp;
    }
    else{
        (*rear)->next = temp;
        *rear = temp;
    }
  
}

int dequeue(Node** front ,Node** rear){
    int x = INT_MIN;
    if(*front == NULL && *rear == NULL){
        return x;
    }
    else{
        Node* temp = *front;
        *front = (*front)->next;
        x = temp->data;
        free(temp);
        temp = NULL;
        
    }
    return x;
}

void display(Node* front,Node* rear){
    Node* ptr = front;
    if(front == NULL && rear == NULL){
        printf("Queue is empty !");
        return ;
    }
    else
    while(ptr != NULL){
        printf("%d-",ptr->data);
        ptr = ptr->next;
    }
    
}

int front_element(Node* front,Node* rear){
    if(!front)
    return front->data;
   
}
int main(){
    Node* front = NULL;
    Node* rear = NULL;
    int choice,data;
     while(1){
        printf("\nEnter your choice:\n1.To enqueue element\n2.To dequeue element\n3.To display the elements\n4.To display the front element\n5.Exit\n----->");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                printf("Enter the data:");
                scanf("%d",&data);
                enqueue(&front,&rear,data);
                break;

            }
            case 2:{
                int ele = dequeue(&front,&rear);
                if(ele == INT_MIN){
                    printf("The queue is empty !");
                }
                else
                printf("The deleted element is :%d ",ele);
                break;

            }
            case 3:{
                display(front,rear);
                break;

            }

            case 4:{
                int ele = front_element(front,rear);
                printf("The front element is : %d",ele);
                break;

            }
            case 5:{
                exit(0);

            }
        }
     }
     return 0;
}


