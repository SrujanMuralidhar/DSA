#include<iostream>
#include<limits.h>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
    Node(int x){
        data = x;
        prev = NULL;
        next = NULL;
    }
};

struct que{
    Node* front;
    Node* rear;
    que(){
        front = rear = NULL;
    }
};

void rear_enqueue(que *Q,int data){
    Node* temp = new Node(data);
    if(Q->front == NULL){
        Q->front = Q->rear = temp;
    }
    else{
        Q->rear->next = temp;
        temp->prev = Q->rear;
        Q->rear = Q->rear->next;
    }
   
   
}

void front_enqueue(que *Q,int data){
    Node* temp = new Node(data);
    if(Q->front == NULL){
        Q->front = Q->rear = temp;
    }
    else{
        temp->next = Q->front;
        Q->front->prev = temp;
        Q->front = temp;
    }
    
}

int front_dequeue(que *Q){
    int x = INT_MIN;
    if(Q->front == NULL){
        printf("The DEque is empty !\n");
        
    }
    if(Q->front == Q->rear){
        Node* temp = Q->front;
        free(temp);
        Q->front = Q->rear = NULL;
    }
    else{
        Node* temp = Q->front;
        Q->front = Q->front->next;
        if(Q->front){
            Q->front->prev = NULL;
        }
        x = temp->data;
        free(temp);

    }
    return x;
}

int rear_dequeue(que *Q){
     int x = INT_MIN;
    if(Q->front == NULL){
        printf("The DEque is empty !\n");
       
    }
     if(Q->front == Q->rear){
        Node* temp = Q->front;
        free(temp);
        Q->front = Q->rear = NULL;
    }
    else{
        Node* temp = Q->rear;
        Q->rear = Q->rear->prev;
        if(Q->rear){
            Q->rear->next = NULL;
        }
        x = temp->data;
    }
    return x;

   
}

void display(que Q){
    if(Q.front == NULL){
        printf("The Deque is empty !");
        return ;
    }
    Node* ptr = Q.front;
    while(ptr != NULL){
        printf("%d-",ptr->data);
        ptr = ptr->next;
    }
   
}

int main(){
    que DEque;
    
    int choice,data;
     while(1){
        printf("\nEnter your choice:\n1.Insert element at rear\n2.Insert element at front\n3.Delete element at rear\n4.Delete element at front\n5. Display the elements\n6.Exit\n----->");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                printf("Enter the data:");
                scanf("%d",&data);
                rear_enqueue(&DEque,data);
                break;
               

            }
            case 2:{
                printf("Enter the data:");
                scanf("%d",&data);
                front_enqueue(&DEque,data);
                break;
               

            }
            case 3:{
                int result = rear_dequeue(&DEque);
                if(result > INT_MIN){
                    printf("The deleted element is : %d",result);
                }
                break;
            }

            case 4:{
                int result = front_dequeue(&DEque);
                if(result > INT_MIN){
                    printf("The deleted element is : %d",result);
                }
                break;
            }
            case 5:{
                display(DEque);
                break;


            }
            case 6:{
                exit(0);

            }
        }
     }
     return 0;
}





