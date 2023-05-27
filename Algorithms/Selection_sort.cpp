#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void selection_sort(int* a,int n){
    int i,j,min;
    for(i = 0; i < n -1 ; i++){
        min = i;
        for(j = i+1;j<n;j++){
            if(a[min] > a[j]) min = j;
        }
        if(min != i){           // swap the min and the ith element
            a[min] = a[min] + a[i];
            a[i] = a[min] - a[i];
            a[min] = a[min] - a[i];
        }
    }
}

int main(){
    int n,i,*a;
    time_t current_time;
    clock_t start,end;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    a = (int*)malloc(n*sizeof(int));
    srand(time(&current_time));
    for(i = 0 ; i < n ; i++){
        a[i] = rand() % 1000;
    }
    printf("The array before sorting : \n");
    for(i = 0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n-------------------------------------------------------------------\n\n");
    start = clock();
    selection_sort(a,n);
    end = clock();
    printf("The time taken for selection sort to sort  %d elemenets is %lf seconds\n" ,n,(double)(end-start)/CLOCKS_PER_SEC);
    printf("\n-------------------------------------------------------------------\n");
    printf("The array after sorting is : \n");
    for(i = 0;i<n;i++){
        printf("%d ",a[i]);
    }

    return 0;

}