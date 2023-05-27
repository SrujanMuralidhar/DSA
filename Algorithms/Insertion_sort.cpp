#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int BinarySearch(int arr[],int low,int high,int ele){
    if (high <= low) return (ele > arr[low]) ?(low + 1) : low;
    int mid = (low + high)/2;
    if(arr[mid] == ele) return mid+1;
    else if(arr[mid] < ele) return BinarySearch(arr,0,mid-1,ele);
    else return BinarySearch(arr,mid+1,high,ele);
}

void insertion_sort(int arr[],int n){
    int temp,i,j ;
    for(i = 1;i < n;i++){
        temp = arr[i];
        j = i - 1;
        while(j >=0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void BinaryInsertionSort(int arr[],int n){
    int temp,i,j ;
    for(i = 1;i < n;i++){
        temp = arr[i];
        int pos = BinarySearch(arr,0,j,temp);
        j = i - 1;
        while(j>= pos){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
       
    }
}

int main(){
    int *a,n,i;
    time_t current_time;
    clock_t start ,end;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    a = (int*)calloc(n,sizeof(int));
    srand(time(&current_time));
    for(i = 0 ;i<n;i++){
        a[i] = rand() % 1000;
    }
    printf("The array before sorting : \n");
    for(i = 0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n-------------------------------------------------------------------\n\n");
    start = clock();
    //insertion_sort(a,n);
    BinaryInsertionSort(a,n);
    end = clock();
    printf("The time taken for selection sort to sort  %d elemenets is %lf seconds\n" ,n,(double)(end-start)/CLOCKS_PER_SEC);
    printf("\n-------------------------------------------------------------------\n");
    printf("The array after sorting is : \n");
    for(i = 0;i<n;i++){
        printf("%d ",a[i]);
    }
    
    
    return 0;

}