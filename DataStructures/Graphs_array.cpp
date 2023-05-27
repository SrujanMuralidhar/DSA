#include<iostream>
using namespace std;

int arr[100][100],queue[100],front,rear;
int visited[100];


void createGraph(){
    int source,dest;
    while(1){
        cout<<"\nEnter the source and destination : ";
        cin>>source>>dest;
        if(source == 0 && dest == 0){
            break;
        }
        arr[source][dest] = 1;// for directed graph
        //arr[source][dest] = arr[dest][source] = 1 for undirected graph
    }

}

void q_insert(int x){
    rear += 1;
    queue[rear] = x;
    if(front == -1){
        front = 0;
    }
}

int q_delete(){
    int x ;
    x = queue[front];
    if(front == rear){
        front = rear = -1;
    }
    else{
        front++;
        return x;
    }
    return 0;
        
}

int isEmpty(){
    if(front == -1){
        return 1;
    }
    return 0;
}

void BFS(int i,int n){
    int u;
    cout<<i<<" ";
    visited[i] = 1;
    q_insert(i);
    while(isEmpty()){
        u = q_delete();
        for(int v = 1;v <= n;v++){
            if(arr[u][v] == 1 && visited[v] == 0){
                cout<<v<<" ";
                visited[v] = 1;
                q_insert(v);
            }
        }
    }

}
void DFS(int u,int n){
    if(visited[u] == 0){
        cout<<u<<" ";
        visited[u] = 1;
    }
    for(int v = 1;v<=n;v++){
        if(arr[u][v] == 1 && visited[v] == 0){
            DFS(v,n);
        }

    }
}

void DFS_stack(int u,int n){
    int x;
    int stack[30],top = -1;
    visited[u] = 1;
    printf("%d ",u);
    stack[++top] = u;
    while(top != -1){
        x = stack[top--];
        for(int i = 0;i<=n;i++){
            if(arr[x][i] == 1 && visited[i] == 0){
                visited[i] = 1;
                stack[++top] = i;
                printf("%d ",i);
            }
            
        }
    }

}

int main(){
    front = -1,rear = -1;
    int size,vertex;
    cout<<"Enter the number of nodes : ";
    cin>>size;

    createGraph();
    cout<<"Enter the source vertex : ";
    cin>>vertex;
    cout<<"The DFS traversal is : ";
    DFS_stack(vertex,size);
    cout<<"The BFS travesal is : ";
    BFS(vertex,size);
    return 0;
}