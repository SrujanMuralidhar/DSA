#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* prev;Node* next;
    Node(){
        data = 0;
        prev = next = NULL;
    }
    Node(int x){
        data = x;
        prev = next = NULL;
    }
};
class LinkedList{
    Node* head ,*last;
    public:
    LinkedList(){
        head = last = NULL;
    }
    void append_node(int);
    void display();
    void delete_node(int);
    void reverse_list();
};

void LinkedList :: append_node(int x){
    Node* temp = new Node(x);
    if( head == NULL){
        head = last = temp;
    }
    else{
        temp->prev = last;
        last->next = temp;
        last = temp;
    }
    
}

void LinkedList :: display(){
    Node* ptr = head;
    if(head == NULL){cout<<"No elements !";}
    while(ptr!=NULL){
        cout<<"<-"<<ptr->data<<"->";
        ptr = ptr->next;
    }
}

void LinkedList :: delete_node(int pos){
   
    if(head == NULL){cout<<"No elements !\n";}
   
    if(pos == 1){
        Node* temp = head;
        head = head->next;
        if (head){
            head->prev = NULL;
        }
        delete temp;
    }
    else{
        Node* ptr = head ;
        for(int i = 1;i<pos;i++){
            ptr = ptr ->next;
        }
        ptr->prev->next = ptr->next;
        if(ptr->next){
            ptr->next->prev = ptr->prev;
            
        }
        delete ptr;
        

    }

}

void LinkedList :: reverse_list(){
    Node* cur  = head;
    Node* temp = nullptr;
    while(cur->next){
        temp = cur->next;
        cur->next = cur->prev;
        cur->prev = temp;
        cur = cur->prev;
        if (cur->next == NULL){         // for the last node
            cur->next = cur->prev;
            cur->prev = nullptr;
            head = cur;
            break;

        }
    }
}

int main(){
    int num,choice;LinkedList mylist;
    while(1){
        cout<<"Enter your choice:\n1. To insert a new node\n2. To display the list\n3. To delete node from a given position\n4. To reverse the list\n5. To exit\n----->";
        cin>>choice;
        switch(choice){
            case 1:{
                cout<<"Enter the data:";
                cin>>num;
                mylist.append_node(num);
                break;
            }
            case 2:{
                mylist.display();
                break;
            }
            case 3:{
                cout<<"Enter the position:";
                int pos;cin>>pos;
                mylist.delete_node(pos);
                break;
            }
            case 4:{
                mylist.reverse_list();
                break;
            }
            case 5:{
                exit(0);
            }

        }
    }
    return 0;

}