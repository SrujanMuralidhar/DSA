#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* next;
    public:
    Node(){
        data = 0;
        next=NULL;
    }
    Node(int x){
        data = x;
        next = NULL;
    }
};
class LinkedList{
    Node* head;
    public:
    LinkedList(){head = NULL;}
    void append_first(int);
    void append_end(int);
    void display();
    int delete_list(int );
    void reverse_list(Node*);
};

void LinkedList :: append_first(int data)
{
    Node* temp;
    temp=new Node(data);
   
    if (head == NULL){
        head =  temp;
    }
    else {
        temp->next = head->next;
        head = temp;
    }
}

void LinkedList::append_end(int data)
{
    Node* temp;
    temp=new Node;
    temp->data = data;
    if (head == NULL){
        head =  temp;
    }
    else{
        Node* ptr = head;
        while(ptr->next)
        {
            ptr = ptr->next;
        }
        temp->next = ptr->next ;
        ptr->next = temp;
    }
}

void LinkedList:: display()
{
    Node *ptr = head;
    while(ptr)
    {
        cout<<ptr->data<<"->";
        ptr = ptr->next;
    }
}

int LinkedList:: delete_list(int  index)
{
    int x;
    Node* ptr= head;int length=0;
    while(ptr){
        ptr=ptr->next;
        length++;
    }
    
    if (head ==  NULL){cout<<"No elements "; return 0;}
    if(index > length){ cout<<"Index out of range !!"; return 0;}
    Node* pt = head;
    if (index == 1){
        head = pt->next;
         x = pt->data;
        delete pt;
    }
    else{
        for(int i=1;i<index;i++)
        {
            pt = pt->next;
        }
        Node* q = pt->next;
        pt->next = q->next;
         x = q->data;
        delete q;
    }
    return x;
}

void LinkedList :: reverse_list(Node* x = NULL){
    static Node* tail = NULL;static Node* cur = head;
    if(head != NULL){
        tail = cur;
        reverse_list(cur->next);
        cur->next = tail;
    }
    else{
        head = tail;
    }
}

int main()
{
    int choice;
    LinkedList mylist;
    int data,index;
   
  
    while(1){
        cout<<"\nEnter your choice:\n1. Insert element at first \n2. Insert element at end\n3. Delete element at any index \n4. Display elements\n5. To reverse the linked list\n6.Exit \n----->";
        cin>>choice;
        switch(choice){
            case 1:{
                cout<<"Enter the data:";
                cin>>data;
                mylist.append_first(data);
                break;
            }
            case 2:{
                cout<<"Enter the data:";
                cin>>data;
                mylist.append_end(data);
                break;
            }
            case 3:{
                cout<<"Enter the index:";
                cin>>index;
                int res = mylist.delete_list(index);
                cout<<res<<" heas been deleted !";
                break;

            }
            case 4:{
                mylist.display();
                break;

            }
            case 5:{
                mylist.reverse_list();
                cout<<"\nSuccesfully reversed\n";
                break;
            }
            case 6:{
                exit(0);
            }
        }
       

    }
     return 0;
}
