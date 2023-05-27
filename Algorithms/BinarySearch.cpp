#include<iostream>
#include<algorithm>
using namespace std;

int BinarySearch(int arr[],int low,int high,int ele){
    if(low > high) return -1;
    int mid = (low + high)/2;
    if(arr[mid] == ele) return mid;
    else if(arr[mid] < ele) return BinarySearch(arr,0,mid-1,ele);
    else return BinarySearch(arr,mid+1,high,ele);
}

int main(){
    int n;
    time_t current_time;clock_t start,end;
    cout<<"Enter the number of elements : ";
    cin>>n;
    srand(time(&current_time));
    int *arr = new int[n];
    for(int i = 0;i<n;i++){
        arr[i] = rand() % 100;
    }
    
    
    sort(arr,arr+n);
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<",";
    }
    cout<<endl;
    cout<<"Enter the search element : ";
    int ele;cin>>ele;

    start = clock();
    int pos = BinarySearch(arr,0,n-1,ele);
    end = clock();
    
    if(pos >= 0){
        cout<<"The element is found at position "<<pos<<endl;
    }
    else{
        cout<<"The element is not found in the array !"<<endl;
    }
    cout<<"The time taken for Binary Search to execute is :"<<(end - start)/CLOCKS_PER_SEC<<endl;


    return 0;

}
