#include<iostream>

using namespace std;


void insert_heap(int* heap,int index,int data){
    index+= 1;
    heap[index] = data;
    int i = index;
    while(i>1){
        int parent = i/2;
        if(heap[parent] < heap[i]){
            swap(heap[parent],heap[i]);
            i = parent;
        }
        else{
            return ;
        }

    }
}

void delete_heap(int* heap,int* index){
    if(*index == 0){
        cout<<"The heap is empty";
        return ;
    }

    int temp ,i,child;
    temp = heap[0];heap[1] = heap[*index];
    i = 1;
    child = 2*i;
    while(child < *index-1){
        if(heap[child+1]>heap[child]){
            child+=1;
        }
        if (heap[i] < heap[child]){
            swap(heap[i],heap[child]);
            i = child;
            child = 2*i;
        }
        else{
            return ;
        }
    }
    
    
}

void display(int* heap,int index){

    for(int i = 1; i <=index ; i++){
        cout<<heap[i]<<" "<<" index : "<<i<<endl;
    }

}
int main(){
    int heap[20];
    int data,choice,index = 0;
    while(1){
        cout<<"Enter your choice : \n1.Insert \n2.Delete \n3.Display \n4.Exit \n--------->";
        cin>>choice;
        switch(choice){
            case 1:{
                cout<<"Enter the data : ";
                cin>>data;
                insert_heap(heap,index,data);
                index++;
                break;
            }
            case 2:{
                delete_heap(heap,&index);
                index--;
                break;

            }
            case 3:{
                display(heap,index);
                break;
            }
            case 4:{
                exit(0);
            }
        }
    }
    return 0;

}
