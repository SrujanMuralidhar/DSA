#include<iostream>
using namespace std;

struct  Node{
    int key;
    Node* next;
    Node(int x = 0){
        key = x;
        next = NULL;

    }
};

struct HashTable{
    Node* head;
    int count;
    HashTable(){
        count = 0;
    }
};

void frontInsert(HashTable *Hash,int key){
    Node *temp = new Node(key);
    Node *ptr = Hash->head;

    temp->next = Hash->head;
    Hash->head = temp;

}

void endInsert(HashTable *Hash,int key){
    Node *temp = new Node(key);
    Node *ptr = Hash->head;

    while(ptr != NULL){
        if(! ptr->next )
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    ptr->next = temp;
}


void sortedInsert(HashTable *Hash,int key){
    Node *temp = new Node(key);
    Node *ptr = Hash->head;

   while(ptr != NULL && ptr->next != NULL &&ptr->next->key <= key){
        ptr = ptr->next;

    }
    if(ptr == Hash->head){
        temp->next = Hash->head;
        Hash->head = temp;
    }
    else{
        temp->next = ptr->next;
        ptr->next = temp;
    }
    
}

void createHash(HashTable *HashTb,int size,int key){
    int hashFunc = key % size;
    Node* temp = new Node(key);
    if(HashTb[hashFunc].count == 0){
        HashTb[hashFunc].head = temp;
        HashTb[hashFunc].count++;
    }
    else{
        frontInsert(&HashTb[hashFunc],key);
        HashTb[hashFunc].count++;
    }

}

void display(HashTable * hash,int size){
    for(int i = 0 ;i < size;i++){
        Node *ptr = hash[i].head;
        while(ptr != NULL){
            cout<<ptr->key<<"->";
            ptr = ptr->next;
        }
        cout<<endl;

    }
    
}

void deleteHash();

void searchHash();

int main(){
    int choice,size,key;
    cout<<"Enter the size of the Hash Table : ";
    cin>>size;
    HashTable *HashTb = new HashTable[size];
    while(true){
        cout<<"Enter your choice : \n1.Insert a key \n2.Delete a key\n3.Search a key\n4.Display the Hash Table\n5.Exit\n--------->";
        cin>>choice;
        switch(choice){
            case 1:{
                cout<<"Enter the key value :";
                cin>>key;
                createHash(HashTb,size,key);
                break;
            }
            case 2:{
                cout<<"Enter the key to be deleted : ";
                cin>>key;
                //deleteHash();
                break;
            }
            case 3:{
                cout<<"Enter the key to be searched : ";
                cin>>key;
                //searchHash();
                break;

            }
            case 4:{
                display(HashTb,size);
                break;
            }
            case 5:{
                exit(0);
            }
        }

        
    }
    return 0;


}