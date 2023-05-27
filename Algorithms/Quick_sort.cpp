#include<iostream>

using namespace std;


int partition(int arr[],int low,int high){
    int i = low;
    int j = high;
    int pivot = arr[low];         // considering the first element to be the pivot
    while(i < j){
        while(i<=high && arr[i] <= pivot){
            i++;
        }
        while(j>=low && arr[j] > pivot){
            j--;
        }
        if(i<j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp =  arr[j];         // here the jth postion is the right pos for the pivot element
    arr[j] = pivot;
    arr[low] = temp;
    
    return j;
    
}

void QuickSort(int arr[],int low,int high){
    int pivot_pos;
    if(low < high){
        pivot_pos = partition(arr,low,high);
        QuickSort(arr,low,pivot_pos-1);
        QuickSort(arr,pivot_pos+1,high);
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
    QuickSort(arr,0,n-1); // array , low , high
    end = clock();

    cout<<"The time taken for sorting is : "<<double(end-start)/CLOCKS_PER_SEC;

    cout<<"\n--------------------------------------------------------------------------------"<<endl;
    cout<<"The array elements after sorting are :\n";
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";

    }


    return 0;


}