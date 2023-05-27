#include<iostream>
using namespace std;

void distributionSort(int* arr,int n,int lower,int upper){
    int* freqArr = new int[upper - lower];
    for(int i = 0;i<n;i++){
        freqArr[arr[i] - lower]++;
    }
    
    int count = 0;
    int i = 0;
    while(count <= upper - lower){
        while(freqArr[count]){
            arr[i] = count + lower;
            i++;
            freqArr[count]--;
        }
        count++;
    }

}


int main(){
    int n,lower,upper;
    time_t current_time;clock_t start , end;
    cout<<"Enter the number of elements : ";
    cin>>n;
    cout<<"Enter the lower and upper bound : ";
    cin>>lower>>upper;

    int *arr = new int[n];
    srand(time(&current_time));
    for(int i = 0 ;i<n;i++){
        arr[i] = rand() % (upper - lower + 1) + lower ;
    }
    cout<<"The array elements before sorting are :\n";
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n--------------------------------------------------------------------------------"<<endl;

    start = clock();
    distributionSort(arr,n,lower,upper);
    end = clock();
   
    cout<<"The time taken for sorting is : "<<double(end-start)/CLOCKS_PER_SEC;

    cout<<"\n--------------------------------------------------------------------------------"<<endl;
    cout<<"The array elements after sorting are :\n";
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";

    }


    return 0;
}