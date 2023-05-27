#include<iostream>
#define MAXSIZE 1000000
using namespace std;

void Merge(int arr[],int low ,int mid,int high){
    int brr[MAXSIZE];
    int i = low;
    int j = mid+1;
    int k = low;
    while(i <= mid && j <= high){
        if(arr[i] < arr[j]){
            brr[k++] = arr[i];
            i++;
        }
        else{
            brr[k++] = arr[j];
            j++;
        }
    }
    while(i <= mid){
        brr[k++] = arr[i++];
    }
    while(j <= high){
        brr[k++] = arr[j++];
    }
    
    for(int i = low;i <= high;i++){
        arr[i] = brr[i];
    }
   


}

void MergeSort(int arr[],int low,int high){
    if(low < high){
        int mid = (low + high)/2;
        MergeSort(arr,low,mid);
        MergeSort(arr,mid + 1 , high);
        Merge(arr,low,mid,high);

    }
    
}


int main(){
    int n;
    time_t current_time;clock_t start , end;
    cout<<"Enter the number of elements : ";
    cin>>n;
    int *arr = new int[n];
    srand(time(&current_time));
    for(int i = 0 ;i<n;i++){
        arr[i] = rand() % 1000;
    }
    cout<<"The array elements before sorting are :\n";
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n--------------------------------------------------------------------------------"<<endl;

    start = clock();
    MergeSort(arr,0,n-1);
    end = clock();

    cout<<"The time taken for sorting is : "<<double(end-start)/CLOCKS_PER_SEC;

    cout<<"\n--------------------------------------------------------------------------------"<<endl;
    cout<<"The array elements after sorting are :\n";
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";

    }


    return 0;


}