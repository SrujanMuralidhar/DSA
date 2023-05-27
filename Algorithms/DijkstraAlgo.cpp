#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

void readGraph(vector<vector<int> >& graph){
    cout<<"Enter the weights : \n";
    for(int i = 0; i< graph.size();i++){
        for(int j = 0;j < graph[0].size();j++){
            cin>>graph[i][j];
        }
    }
}

vector<int> dijkstra(vector<vector<int> > graph,int source){
    vector<int> visited(graph.size(),0);
    vector<int> distance(graph.size(),-1);
    queue<int> Q;
    visited[source] = 1;
    Q.push(source);
    distance[source] = 0;

    while(!Q.empty()){
        int vertex = Q.front();Q.pop();

        for(int i = 0;i<graph.size();i++){
            if(graph[vertex][i] != 0 && !visited[i]){
             
            }
        }

    }

}

int main(){
    int vertices;
    cout<<"Enter the number of vertices : ";
    cin >> vertices;

    vector<vector<int> > graph(vertices,vector<int>(vertices,0));

    readGraph(graph);

    int source;
    cout<<"Enter the source vertex :";
    cin >> source;

    vector<int> distance = dijkstra(graph,source);









}