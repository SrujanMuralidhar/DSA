#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void bubble_sort(int* a,int n){
    int i,j;
    int flag = 1;
    for(i = 0;i< n - 1;i++){
        for(j = 0;j < n - i -1;j++){
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = 0;
            }
        }
    if(flag == 1){
        return ;
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
    bubble_sort(a,n);
    end = clock();

    printf("The time taken for selection sort to sort  %d elemenets is %lf seconds\n" ,n,(double)(end-start)/CLOCKS_PER_SEC);
    printf("\n-------------------------------------------------------------------\n");
    printf("The array after sorting is : \n");
    for(i = 0;i<n;i++){
        printf("%d ",a[i]);
    }

    return 0;

}