#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;
    Node(){
        data = 0;
        prev  = next = nullptr;
    }
    Node(int x){
        data = x;
        prev  = next = nullptr;
    }
};
class LinkedList{
    Node* head;
    public:
    LinkedList(){
        head = nullptr;
    }
        void insert_first(int);
        void insert_last(int );
        void display();
        void delete_first();

};
void LinkedList :: insert_first(int x){
    Node* temp = new Node(x);
    if(head == nullptr){
        head = temp;
        head->prev = head->next = temp;
    }
    else{
        temp->next = head->next;
        if(head->next)
        head->next->prev = temp;
        head->next  = temp;
        temp->prev = head;
    }   
}

void LinkedList :: insert_last(int x){
    Node* temp  = new Node(x);
    if(head == nullptr){
        head = temp;
        head->prev = head->next = temp;
    }
    else {
        Node* ptr = head;
       while(ptr->next!=head){
        ptr = ptr->next;
        }
        temp->next = ptr->next;
        temp->prev = ptr;
        ptr->next = temp;
        head->prev = temp;
    }
}

void LinkedList :: display(){
    if(head == nullptr){
        cout<<"No elements";
        return ;
    }
    Node* ptr = head;
    do{
        cout<<"-<"<<ptr->data<<"->";
        ptr = ptr->next;
    }while(ptr!=head);
    cout<<"\n";

}

void LinkedList :: delete_first(){
    if(head == nullptr){
        cout<<"No elements";
        return ;
    }
    else{
       
            head = head->next;
            Node* temp = head->prev;
            head->prev = head ->prev->prev;
            delete temp;
        }
        
        
    
}
int main(){
    int num,choice;LinkedList mylist;
    while(1){
        cout<<"\nEnter your choice:\n1. To insert a new node at begining \n2. To insert node at end\n3. To display the list\n4. To delete node from begining\n5. Exit\n-------->";
        cin>>choice;
        switch(choice){
            case 1:{
                cout<<"Enter the data:";
                cin>>num;
                mylist.insert_first(num);
                break;
            }
            case 2:{
                cout<<"Enter the data:";
                cin>>num;
                mylist.insert_last(num);
                break;
                }

            case 3:{
                mylist.display();
                break;
            }
            case 4:{
                mylist.delete_first();
                break;
            }
            
            case 5:{
                exit(0);
            }

        }
}
return 0;

}


