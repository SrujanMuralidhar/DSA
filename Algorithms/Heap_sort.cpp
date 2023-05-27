#include<iostream>
#include<time.h>
using namespace std;

// Bottom - up Approach : First create the binary tree and then perform HEAPIFY
// Top - down Approach : As and when we insert the nodes we perform HEAPIFY

void Heapify(int arr[],int n){
    int parent,child,vertex;
    for(int i = n/2-1;i>=0;i--){
        bool heap = false;
        parent  = i;
        vertex = arr[parent];
        while(!heap && 2*parent+1 < n){
            child = 2*parent+1;
            if(child+1 < n && arr[child + 1] > arr[child]){     //comparing the left and the right child 
                child = child+1;
            }
            if(vertex < arr[child]){                // comparing the parent and the child value
                arr[parent] = arr[child];
                parent = child;
            }
            else{
                heap = true;
            }
        }
        arr[parent] = vertex;
    }

}

void HeapSort(int arr[],int n){
    if(n == 1) return ;
    int temp = arr[n-1];
    arr[n-1] = arr[0];
    arr[0] = temp;
    Heapify(arr,n-1);
    HeapSort(arr,n-1);
}


int main(){
    int n;
    time_t current_time;clock_t start , end;
    cout<<"Enter the number of elements : ";
    cin>>n;
    int *arr = new int[n];
    srand(time(&current_time));
    for(int i = 0 ;i<n;i++){
        arr[i] = rand() % 1000;
    }
    cout<<"The array elements before sorting are :\n";
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n--------------------------------------------------------------------------------"<<endl;

    start = clock();
    Heapify(arr,n);
    HeapSort(arr,n); // array , n
    end = clock();

    cout<<"The time taken for sorting is : "<<double(end-start)/CLOCKS_PER_SEC;

    cout<<"\n--------------------------------------------------------------------------------"<<endl;
    cout<<"The array elements after sorting are :\n";
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";

    }


    return 0;

}


