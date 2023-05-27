#include<iostream>
#include<limits.h>
using namespace std;

struct Node{
    int data;
    int priority;
    Node(int d = INT_MIN,int p = INT_MIN){
        data = d;
        priority = p;
    }
};

void Q_insert(Node* heap, Node key,int *count){
    int index , parent;
    index = *count;
    ++(*count);
    heap[index] = key;
    parent = (index - 1)/2;
    while(index > 0 && key.priority > heap[parent].priority){
        heap[index] = heap[parent];
        index = parent;
        parent = (index - 1)/2;
        
    }
    heap[index] = key;
}

void heapify(Node* heap,int count){
    Node key;
    int index,parent;
    parent = 0;
    key = heap[parent] ;
    index = 2* parent + 1;
    while(index <= count){
        if((index+1) <= count){
            if(heap[index+1].priority > heap[index].priority)
            index++;
        }
        if(key.priority < heap[index].priority){
            heap[parent] = heap[index];
            parent = index;
            index = 2 * parent +1;
        }
        else{
            break;
        }
    }
    heap[parent] = key;
}

Node Q_delete(Node* heap,int *count){
    Node temp;
    temp = heap[0];
    heap[0] = heap[*count - 1];
    --(*count);
    heapify(heap,*count-1);
    return temp;

}

void display(Node* heap,int count){
    if(count == 0){
        cout<<"The Q is empty";
        return ;
    }
    for(int i = 0;i < count ; i++){
        cout<<"Data : "<<heap[i].data<<" Priority : "<<heap[i].priority<<endl;
    }
}

int main(){
    int choice,count = 0;
    Node heap[100],key;
    while(1){
        cout<<"\nEnter your choice : \n1.Insert \n2.Delete \n3.Display \n4.Exit\n--------->";
        cin>>choice;
        switch(choice){
            case 1:{
                cout<<"Enter the data and the priority : ";
                cin>>key.data>>key.priority;
                Q_insert(heap,key,&count);
                break;
            }
            case 2:{
                Q_delete(heap,&count);
                break;

            }
            case 3:{
                display(heap,count);
                break;

            }
            case 4:{
                exit(0);
            }
        }
    }
    return 0;

}
