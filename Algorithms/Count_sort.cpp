#include<iostream>
using namespace std;

struct countSortArray{
    int val;
    int count;
};

void countSort(countSortArray *arr,int n){
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(arr[i].val > arr[j].val){
                arr[i].count++;
            }
            else{
                arr[j].count++;
            }
        }
    }

    int auxArr[n];
    for(int i =0;i<n;i++){
        auxArr[arr[i].count] = arr[i].val;
    }

    for(int i=0;i<n;i++){
        arr[i].val = auxArr[i];
    }
}


int main(){
    int n;
    time_t current_time;clock_t start , end;
    cout<<"Enter the number of elements : ";
    cin>>n;
    countSortArray *arr = new countSortArray[n];
    srand(time(&current_time));
    for(int i = 0 ;i<n;i++){
        arr[i].val = rand() % 1000;
        arr[i].count = 0;
    }
    cout<<"The array elements before sorting are :\n";
    for(int i = 0;i<n;i++){
        cout<<arr[i].val<<" ";
    }
    cout<<"\n--------------------------------------------------------------------------------"<<endl;

    start = clock();
    
    end = clock();
    countSort(arr,n);
    cout<<"The time taken for sorting is : "<<double(end-start)/CLOCKS_PER_SEC;

    cout<<"\n--------------------------------------------------------------------------------"<<endl;
    cout<<"The array elements after sorting are :\n";
    for(int i = 0;i<n;i++){
        cout<<arr[i].val<<" ";

    }


    return 0;
}