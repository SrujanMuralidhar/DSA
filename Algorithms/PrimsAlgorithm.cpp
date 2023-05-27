#include<iostream>
#include<vector>
#include<string>
using namespace std;

void readGraph(vector<vector<int> >& graph){
    cout<<"Enter the weights : \n";
    for(int i = 0; i< graph.size();i++){
        for(int j = 0;j < graph[0].size();j++){
            cin>>graph[i][j];
        }
    }
}

vector<vector<int> > Prims(vector<vector<int> >& graph,vector<int>& TreeVertex){
    TreeVertex[0] = 1;
    int distance = 999;
    int vertex1,vertex2;
    vector<vector<int> > result;
    vector<int> temp;
    int i,j;
    for(i = 0;i<graph.size();i++){
        for(j = 0;j<graph[0].size();j++){
            if(i!=j && graph[i][j] != 0 && TreeVertex[j] == 0){
                if(distance > graph[i][j]){
                    distance = graph[i][j];
                    vertex1 = i;
                    vertex2 = j;
                }
            }
        }
        TreeVertex[vertex1] = 1;
        if(distance != 999){
            temp.push_back(distance);temp.push_back(vertex1);temp.push_back(vertex2);
            result.push_back(temp);
            distance = 999;
            temp.clear();
        }
        
    }
    return result;
}

int main(){
    int vertices = 0;
    cout<<"Enter the number of vertices :";
    cin>>vertices;
    vector<vector<int> > WeightedGraph(vertices,vector<int>(vertices,0));
    vector<int> TreeVertex(vertices,0);

    readGraph(WeightedGraph);

    vector<vector<int> > result = Prims(WeightedGraph,TreeVertex);

    cout<<"Edge"<<"\t\tWeight"<<endl;
    int totalWeight = 0;
    for(int i =0;i<result.size();i++){
        cout<<result[i][1]<<" - "<<result[i][2]<<"\t\t"<<result[i][0]<<endl;
        totalWeight+=result[i][0];

        
    }
    cout<<"The total weight of the minimum spanning tree is : "<<totalWeight<<endl;

    return 0;
}

