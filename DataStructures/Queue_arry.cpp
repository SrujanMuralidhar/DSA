#include<iostream>
#include<stdio.h>
#include<stdlib.h>

void enqueue(int* queue,int* rear,int* front,int data,int size){
    if((*rear) == size-1){
        printf("Queue overflow");
        return ;
    }
    else{
        (*rear) += 1;
        queue[*rear] = data;
    
    }
}

   
int dequeue(int *queue,int* front,int *rear){
    int x;
    if(*front == *rear){
        *front = 0;
        *rear = -1;
        printf("\nQueue underflow\n");
        return 0 ;
    }
    else{
        x = queue[*front];
        *front+=1;
    }
    return x;
}
void display(int* queue,int rear,int front){
    if(rear  < front){
        printf("The queue is empty !");
        return ;
    }
    
    for(int i = front;i<=rear;i++){
        printf("%d->",queue[i]);
    }
}
int front_element(int* queue,int front){
    return queue[front];

}

int main(){
    printf("Enter the size of the queue:");
    int size,data,choice;
    int rear = -1 ,front = 0;
    scanf("%d",&size);
    int *queue = (int*)malloc(size*sizeof(int));
    while(1){
        printf("\nEnter your choice:\n1.To enqueue element\n2.To dequeue element\n3.To display the elements\n4.To display the front element\n5.Exit\n----->");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                printf("Enter the data:");
                scanf("%d",&data);
                enqueue(queue,&rear,&front,data,size);
                break;

            }
            case 2:{
                int ele = dequeue(queue,&front,&rear);
                printf("The deleted element is :%d ",ele);
                break;

            }
            case 3:{
                display(queue,rear,front);
                break;

            }
            case 4:{
                int ele = front_element(queue,front);
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