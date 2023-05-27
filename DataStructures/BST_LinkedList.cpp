#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x=0){
        data = x;
        left = NULL;
        right = NULL;
    }
};

void insert(Node* BST_TREE,int data){
  
    Node* temp = new Node(data);
    Node* prev,*current;
    current = prev = BST_TREE;
    while(current != NULL){
        prev = current;
        if(current->data <= data){
            
            current = current->right;
        }
        else{
            current = current->left;
            
        }
    }
    if(data < prev->data){
            prev->left = temp;
        }
        else{
            prev->right = temp;
        }
  

}

Node* recursive_insert(Node* tree_node,int data){
    Node* temp = new Node(data);
    if(tree_node == NULL){
        return temp;
    }
    else if(tree_node->data < data){
        tree_node->right = recursive_insert(tree_node->right,data);
    }
    else{
        tree_node->left = recursive_insert(tree_node->left,data);

    }
    return tree_node;
}

void PreOrder(Node *BST_TREE){

    if(BST_TREE != NULL){
        cout<<BST_TREE->data<<" ";
        PreOrder(BST_TREE->left);
        PreOrder(BST_TREE->right);
    }
}

void InOrder(Node *BST_TREE){

    if(BST_TREE != NULL){
        InOrder(BST_TREE->left);
        cout<<BST_TREE->data<<" ";
        InOrder(BST_TREE->right);
    }
}

void PostOrder(Node *BST_TREE){

    if(BST_TREE != NULL){
        PostOrder(BST_TREE->left);
        PostOrder(BST_TREE->right);
        cout<<BST_TREE->data<<" ";
    }

}

Node* search_tree(Node* BST_TREE,int search_ele){
   
    if(BST_TREE == NULL) return NULL;
    if(search_ele == BST_TREE->data){
        return BST_TREE;
    }
    else{
        if(BST_TREE->data < search_ele)
            return search_tree(BST_TREE->right,search_ele);
        else 
            return search_tree(BST_TREE->left,search_ele);
        }
    }
    
int Height(Node* root){
    int left,right;
    left = right = 0;
    if(root == NULL){
        return 0;
    }
    
    left = Height(root->left);
    right = Height(root->right);
    return left>right ? left+1:right+1;

}

int noNodes(Node* root){
    if(root == NULL){
        return 0;

    }
    else
        return 1 + noNodes(root->left) + noNodes(root->right);
}

int leafNodes(Node* root){
    if(root == NULL){return 0;}
    if(root->left == NULL && root->right == NULL) return 1;
    return leafNodes(root->left)+leafNodes(root->right);
}

Node* InOrderSucc(Node* root){
    while(root && root->left){
        root = root->left;
    }
    return root;
}

Node* InOrderPre(Node* root){
    while(root && root->right){
        root = root->right;
    }
    return root;
}

Node* recursive_delete(Node* root,int key){
    if (root == NULL) return root;

    if(key < root->data){
            root->left = recursive_delete(root->left,key);
    }
    else if(key > root->data){
        root->right = recursive_delete(root->right,key);
    }
    else{
        if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = InOrderPre(root->left);
        root->data = temp->data;

        root->left = recursive_delete(root->left,temp->data);
       
    }
    return root;
}

int main(){
    
    Node* BST_TREE = NULL;
    cout<<"Enter the data of the root node:";
    int root_data;
    cin>>root_data;
    BST_TREE = new Node(root_data);
    Node* head = NULL;
    int choice,data;
    while(1){
        cout<<"\nEnter your choice:\n1.Insert element\n2.PreOrder Display\n3.InOrder Display\n4.PostOrder Display\n5.To search an element\n6.Delete a node\n7.Height of the tree and No of nodes\n8.Exit\n----------->";
        cin>>choice;
        switch(choice){
            case 1:{
                cout<<"Enter the data:";
                cin>>data;
                insert(BST_TREE,data);
                break;
            }
            case 2:{
                PreOrder(BST_TREE);
                break;
            }
            case 3:{
                InOrder(BST_TREE);
                break;
            }
            case 4:{
                PostOrder(BST_TREE);
                break;
            }
            case 5:{
                cout<<"Enter the data to searched : ";
                int search;
                cin>>search;
                Node* ptr = search_tree(BST_TREE,search);
                ptr ? cout<<"The search element is present in the Tree":cout<<"The element is not present in the tree";
                break;
            }
            case 6:{
                cout<<"Enter the key to be deleted : ";int key;cin>>key;
                Node* temp = recursive_delete(BST_TREE,key);
                temp ? cout<<"The node has been deleted":cout<<"The tree is empty";
                break;
                
            }
            case 7:{
                cout<<"The height of the tree is : "<<Height(BST_TREE);
                cout<<"The number of nodes are : "<<leafNodes(BST_TREE);
                break;
            }
            case 8:{
                exit(0);
            }

        }

    }
    return 0;
}