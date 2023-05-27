#include<iostream>
using namespace std;

struct Node{
    char data;
    Node *left,*right;
};

int is_operator(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' ||ch == '^' ){
        return 1;
    }
    return 0;
}

Node* create_exp_tree(char *exp){
   
    Node* stack[20];static int top = -1;
    int index = 0;char ch;
    
    while(exp[index]){
        ch = exp[index];
        Node* temp = new Node;
        temp->data = ch;
        temp->left = temp->right = NULL;
        if(is_operator(ch)){
            temp->right = stack[top--];
            temp->left =  stack[top--];
            stack[++top] = temp;
        }
        else{
            stack[++top] = temp;
            
        }
        index++;
    }
    return stack[top];
   
}
void PreOrder(Node *EXP_TREE){

    if(EXP_TREE != NULL){
        cout<<EXP_TREE->data<<" ";
        PreOrder(EXP_TREE->left);
        PreOrder(EXP_TREE->right);
    }
}

void InOrder(Node *EXP_TREE){

    if(EXP_TREE != NULL){
        InOrder(EXP_TREE->left);
        cout<<EXP_TREE->data<<" ";
        InOrder(EXP_TREE->right);
    }
}

void PostOrder(Node *EXP_TREE){

    if(EXP_TREE != NULL){
        PostOrder(EXP_TREE->left);
        PostOrder(EXP_TREE->right);
        cout<<EXP_TREE->data<<" ";
    }

}

int evaluate(Node* root){
    int result;
    switch (root->data){
        case '+':   result = (evaluate(root->left) + evaluate(root->right));
                    break;
        case '-':   result = (evaluate(root->left) - evaluate(root->right));
                    break;
        case '*':   result = (evaluate(root->left) * evaluate(root->right));
                    break;
        case '/':   result =  (evaluate(root->left) / evaluate(root->right));
                    break;
        default :   return root->data - '0';
        
    }
    return result;
}

int main(){
    cout<<"Enter the postfix expression : ";
    char exp[50];
    cin>>exp;

    Node* root = create_exp_tree(exp);

    
    cout<<"The infix expression is : ";
    InOrder(root);cout<<endl;

    cout<<"The prefix expression is : ";
    PreOrder(root);cout<<endl;

    cout<<"The postfix expression is : ";
    PostOrder(root);cout<<endl;
    
    cout<<"The result of the expression is : "<<evaluate(root);

    return 0;
    
}