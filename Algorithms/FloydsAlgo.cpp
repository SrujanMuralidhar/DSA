#include<iostream>
#include<vector>
using namespace std;

int min(int a,int b){
    return a < b ? a:b;
}

void readMatrix(vector<vector<int> >& graph,int vertices){
    for(int i = 0;i<vertices;i++){
        for(int j = 0;j<vertices;j++){
            cin>>graph[i][j];
        }
    }
}

void Floyds(vector<vector<int> >&graph,int vertices){
    for(int k = 0;k<vertices;k++){
        for(int i = 0;i<vertices;i++){
            for(int j = 0;j<vertices;j++){
                graph[i][j] = min(graph[i][j],graph[i][k] + graph[k][j]);
            }
        }
    }
}

void printMatrix(vector<vector<int> > &graph,int vertices){
    for(int i = 0;i<vertices;i++){
        for(int j = 0;j<vertices;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int vertices;
  
    cout<<"Enter the number of vertices :";
    cin>>vertices;
    vector<vector<int> > graph(vertices,vector<int>(vertices,0));
    cout<<"Enter the weight matrix :\n";
    readMatrix(graph,vertices);
    cout<<"The shortest path to all pairs is :\n";
    Floyds(graph,vertices);

    printMatrix(graph,vertices);

    return 0;

}