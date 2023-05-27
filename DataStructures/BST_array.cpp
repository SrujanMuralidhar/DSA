#include<iostream>
#include<limits.h>
using namespace std;

void insert(int *BST_TREE,int data){
    int pos = 0;
    if(BST_TREE[0] == INT_MIN){
        BST_TREE[0] = data;

    }
    else{
        while(BST_TREE[pos] != INT_MIN){
            if(BST_TREE[pos] <= data){
                pos = 2*pos + 2;//right child 

            }
            else{
                pos = 2*pos + 1;//left child
            }
        }
        BST_TREE[pos] = data;  
    }
}

void PreOrder(int *BST_TREE, int pos){          //Root-Left_Right
    if(BST_TREE[pos] != INT_MIN){
        cout<<BST_TREE[pos]<<" ";
        PreOrder(BST_TREE,2*pos+1);
        PreOrder(BST_TREE,2*pos+2);

    }
}

void InOrder(int *BST_TREE, int pos){           //Left-Root-Right
     if(BST_TREE[pos] != INT_MIN){
        InOrder(BST_TREE,2*pos+1);
        cout<<BST_TREE[pos]<<" ";
        InOrder(BST_TREE,2*pos+2);
    }
    
}

void PostOrder(int *BST_TREE, int pos){           // Left-Right-Root
     if(BST_TREE[pos] != INT_MIN){
        PostOrder(BST_TREE,2*pos+1);
        PostOrder(BST_TREE,2*pos+2);
        cout<<BST_TREE[pos]<<" ";
    }
}

void LevelOrder(int *BST_TREE){
    for(int i=0;i<100;i++){
        if(BST_TREE[i] != INT_MIN){
            cout<<BST_TREE[i]<<" ";

        }
    }
}

int main(){
    int BST_TREE[100];
    for(int i=0;i<100;i++){
        BST_TREE[i] = INT_MIN;
    }
    int choice,data;
    while(1){
        cout<<"\nEnter your choice:\n1.Insert element\n2.PreOrder Display\n3.InOrder Display\n4.PostOrder Display\n5.Level Order Display\n6.Exit\n----------->";
        cin>>choice;
        switch(choice){
            case 1:{
                cout<<"Enter the data:";
                cin>>data;
                insert(BST_TREE,data);
                break;
            }
            case 2:{
                PreOrder(BST_TREE,0);
                break;
            }
            case 3:{
                InOrder(BST_TREE,0);
                break;
            }
            case 4:{
                PostOrder(BST_TREE,0);
                break;
            }
            case 5:{
                LevelOrder(BST_TREE);
                break;
            }
            case 6:{
                exit(0);
            }

        }

    }
    return 0;
}