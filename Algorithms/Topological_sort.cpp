#include<iostream>
#define MAX_SIZE 10
using namespace std;

void readGraph(int arr[][MAX_SIZE],int n){

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>arr[i][j];
        }
    }
}

void TopologicalSort(int arr[][MAX_SIZE],int n,int visited[],int topo[],int* index,int source){
    
    visited[source] = 1;
    

    for(int i =0;i<n;i++){
        if(arr[source][i] == 1 && visited[i] == 0 ){
            TopologicalSort(arr,n,visited,topo,index,i);
            topo[*index] = i;
            (*index)++;
        }
    }
}

int main(){
    int n;
    cout<<"Enter the number of verticies";
    cin>>n;
    int arr[MAX_SIZE][MAX_SIZE];
    int visited[MAX_SIZE] = {0};
    int topo[MAX_SIZE] = {0};
    int index = 0;

    readGraph(arr,n);

    for(int i = 0;i<n;i++){
        if(visited[i] == 0){
            TopologicalSort(arr,n,visited,topo,&index,i);
            topo[index]=i;
            index++;
        }
    }
    cout<<"The Topological sort for the graph is :\n";
    for(int i=n-1;i>=0;i--){
        cout<<topo[i]<<" ";
    }
    cout<<endl;
    return 0;




}