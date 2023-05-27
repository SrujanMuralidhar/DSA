#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* right,*left;
    bool lthread,rthread;
    Node(int x = 0){
        data = x;
        right = left = NULL;
        lthread = rthread = true;

    }
};

Node* insert(Node* tree,int data){
    Node* temp = new Node(data);
    Node* current = tree;
    bool flag = true;
    if(tree == NULL){
        return temp;
        
    }
    while(flag){
        if(data < current->data){
            if(current->lthread == false){
                current = current->left;
            }
            else break;
        }
        else{
             if(current->rthread == false){
                current = current->right;
            }
            else break;
        }
    }
    if(data < current->data){
        current->left = temp;
        temp->right = current;
        current->lthread = false;
    }
    else{
        current->right = temp;
        temp->left = current;
        current->rthread = false;
    }
    return tree;
    

}

Node* InOrder_Succ(Node* tree){
    if(tree->rthread == true){
        return tree->right;
    }
    tree = tree->right;
    while(tree->lthread == false){
        tree = tree->left;
    }
    return tree;
}

void InOrder(Node* tree){
    Node* current = tree;
    if(current == NULL){
        cout<<"The tree is empty";
        return ;
    }
    while(current->lthread == false){
        current = current->left;
    }
    while(current != NULL){
        cout<<current->data<<" ";
        current = InOrder_Succ(current);

    }   
}


int main(){
    int choice,data;
    Node* tree = NULL;
    while(1){
        cout<<"\nEnter your choice:\n1.Insert\n2.InOrder traversal\n3.Exit\n--------->";
        cin>>choice;
        switch(choice){
            case 1:{
                cout<<"Enter the data : ";
                cin>>data;
                tree = insert(tree,data);
                break;
            }
            case 2:{
                InOrder(tree);
                break;
            }
            case 3:{
                exit(0);
            }
            
        }
    }
    return 0;
}