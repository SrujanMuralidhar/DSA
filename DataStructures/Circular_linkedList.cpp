#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(){
        data = 0;
        next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
class LinkedList{
    Node* head;
public:
    LinkedList(){
        head = NULL;
    }
    void append(int );
    void display();
    int length();
    void delete_node(int);


};

void LinkedList :: append(int x){
    Node* temp;static Node* last = NULL;
    temp = new  Node(x);
    if(head == NULL){
        head = last = temp;
        temp->next = head;
    }
    else{
        /*Node* ptr = head;
        do{
            ptr = ptr->next;

        }while(ptr->next!= head);
        temp-> next = ptr->next;
        ptr->next=temp;*/
        temp ->next = last->next;
        last->next = temp;
        last = temp;
    }
}
void LinkedList :: display(){
    Node* ptr = head;
    do{
        cout<<ptr->data<<"->";
        ptr = ptr->next;
    }while(ptr!= head);
}
int LinkedList :: length(){
    Node* ptr = head;
    int length = 0;
    if(head == NULL){return 0;}
    do{
        ptr = ptr->next;
        length++;
    }while(ptr!= head);
    return length;
}
void LinkedList :: delete_node(int pos){
        Node* ptr = head;
        if (pos == 1){
            while(ptr ->next !=head){
                ptr = ptr->next;

            }
            ptr->next = head->next ;
            Node* temp = head;
            head = head->next;
            delete temp;
            temp = NULL;
            
        }
        else{
            for(int i =1 ;i<pos-1;i++){
                ptr = ptr->next;
            }
            Node* t = ptr->next;
            ptr->next = t->next;
            delete t;
            t = NULL;
        }
}
int main(){
    LinkedList mylist;int num;
    while(1){
        cout<<"\n1.To add element to the list\n2. To display the list\n3. To display length of the list\n4. To delete element from a given index\n5. Exit\n------------>";
        int choice ;
        cin>>choice;
        switch(choice){
            case 1:{
                cout<<"Enter the data:";
                cin>>num;
                mylist.append(num);
                mylist.display();
                break;
            }
            case 2:{
                mylist.display();
                break;
            }
            case 3:{
                int res = mylist.length();
                cout<<"The length is :"<<res<<endl;
                break;
            }
            case 4:{
                cout<<"Enter the position:";
                int pos;cin>>pos;
                mylist.delete_node(pos);
                break;
            }
            case 5:
            exit(0);
        }

    }
    return 0;

    
}