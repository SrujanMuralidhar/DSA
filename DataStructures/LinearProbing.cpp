#include<iostream>
using namespace std;

struct element{
    int key;
    char name[20];
    int mark;
    element(){
        //key = 0;
        mark = 0;
    }
};

void createHash(element *hash,int size,int key,char* name,int hashFunc){

    if(hashFunc == size){
        cout<<"The Hash Table is Full !";
        return ;
    }
    if(hash[hashFunc].mark == 0){
        hash[hashFunc].key = key;
        strcpy(hash[hashFunc].name,name);
        hash[hashFunc].mark = 1;
        return ;
    }
    else{
        hashFunc = (hashFunc + 1) % size;
        createHash(hash,size,key,name,hashFunc);
    }
}

void createHash(element *hash,int size,int key,char *name){
    int hashFunc = key % size;
    static int count = 0;int i = 0;
    if(count == size){
        cout<<"The hash table is full !";
        return ;
    }
    
    else{
        while(true){
            if(hash[hashFunc + i].mark == 0){
                hash[hashFunc + i].key = key;
                strcpy(hash[hashFunc+i].name,name);
                hash[hashFunc+i].mark = 1;
                count++;
                break;
            }
            else{
                i++;
                
            }
            if(i == size){
                cout<<"The key "<<key<<" cannot be inserted !";
                return ;
            }
        }
    }
}

void deleteHash(element *hash,int size,int key,int hashFunc){
    static int count = 0;
    if(count == size){
        cout<<"The element is not found !"<<endl;
        return;
    }
    if(hash[hashFunc].key == key){
        hash[hashFunc].mark = 0;
        cout<<"The key "<<key<<" is deleted"<<endl;
        return ;
    }
    else{
        count++;
        hashFunc = (hashFunc + 1) % size;
        deleteHash(hash,size,key,hashFunc);
    }
}

void displayHash(element *hash,int size){
   for(int i = 0;i<size;i++){
    cout<<i<<":";
    if(hash[i].key != 0){
        cout<<hash[i].key<<" "<<hash[i].name<<endl;
    }
    else cout<<endl;
   }
}

void searchHash(element *hash,int size,int key,int hashFunc){
    static int check = 0;
    if(check == size){
        cout<<"The element is not present !"<<endl;
        return ;
    }
    if (hash[hashFunc].key == key){
        cout<<"The key is present at index "<<hashFunc<<endl;
        return ;
    }
    else{
        check++;
        hashFunc = (hashFunc + 1) % size;
        searchHash(hash,size,key,hashFunc);
    }
}

int main(){
    int size;
    cout<<"Enter the size of the Hash Table : ";
    cin>>size;
    int choice,key;char name[20];
    element *HashTb = new element[size];
    while(true){
        cout<<"Enter your choice : \n1.Insert a key \n2.Delete a key \n3.Display the key\n4.Search an element/key\n5.Exit\n---------->";
        cin>>choice;
        switch(choice){
            case 1:{
                cout<<"Enter the key : ";
                cin >> key;
                cout<<"Enter the name : ";
                cin>>name;
                int hashFunc = key % size;
                //createHash(HashTb,size,key,name,hashFunc);
                createHash(HashTb,size,key,name);
                break;
            }
            case 2:{
                cout<<"Enter the key to be deleted : ";
                cin>>key;
                int hashFunc = key % size;
                deleteHash(HashTb,size,key,hashFunc);
                break;

            }
            case 3:{
                displayHash(HashTb,size);
                break;
            }
            case 4:{
                cout<<"Enter the key to be searched : ";
                cin>>key;
                int hashFunc = key % size;
                searchHash(HashTb,size,key,hashFunc);
                break;

            }
            case 5:{
                exit(0);
            }
        }
        
    }
    return 0;
    
}