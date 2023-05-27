#include<iostream>
using namespace std;


void createHash(int* hash,int key,int size,int *count){
    int h1 = key % size;
    //int h2 = (size - 3) -( key % (size - 4));
    int h2 = 1 + (key % 11);
    int flag = 1, i = 0;
    if(*count == size){
        cout<<"The Hash tabel is full !";
        return ;
    }
    while(flag){
        if(hash[(h1 + i * h2) % size] == 0){
            hash[(h1 + i * h2) % size] = key;
            *count += 1;
            flag = 0;
        }
        else{
            i++;
        }
    }
}

void deleteHash(int * hash,int key,int size,int *count){
    int h1 = key % size;int check = 0;
    int h2 = 5 - (key%5);
    int flag = 1,i = 0;

    if(*count == 0){
        cout<<"The Hash table is Empty!";
        return ;
    }
    while(flag){
        if(check == size){
            cout<<"The key is not present in the Hash table !"<<endl;
            return ;
        }
        check++;
        if(hash[(h1 + i * h2) % size] == key){
            hash[(h1 + i * h2) % size] = 0;
            *count -= 1;
            flag = 0;
        }
        else{
            i++;
        }
    }

}

void display(int *hash,int size){
    for(int i = 0;i<size;i++){
        cout<<i<<":";
        if(hash[i] != 0){
            cout<<hash[i]<<endl;
        }
        else cout<<endl;
    }

}

int main(){
    cout<<"Enter the size of the Hash Table : ";
    int size,choice,key,count = 0;
    cin>>size;
    int *hash = new int[size];
    while(true){
        cout<<"Enter your choice : \n1.Insert a key\n2.Delete a key\n3.Display the Hash Table\n4.Exit\n--------->";
        cin>>choice;
        switch(choice){
            case 1:{
                cout<<"Enter the key : ";
                cin>> key;
                createHash(hash,key,size,&count);
                break;

            }
            case 2:{
                cout<<"Enter the key to be deleted : ";
                cin >> key;
                deleteHash(hash,key,size,&count);
                break;
            }
            case 3:{
                display(hash,size);
                break;

            }
            case 4:{
                exit(0);
            }

        }

    }
    return 0;

}