#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define RtoL 0
#define LtoR 1

int factorial(int n){
    if(n==0|| n==1) return 1;
    return factorial(n-1) * n;

}

int getLME(int perm[],int dir[],int n){
    int mobile = 0;
    for(int i=1;i<=n;i++){
        if(i!= 1 && dir[perm[i]] == RtoL){
            if(perm[i] > perm[i-1] && perm[i] > mobile){
                mobile =  perm[i];
            }
        }
        if(i!= n && dir[perm[i]] == LtoR){
            if(perm[i] > perm[i+1] && perm[i] > mobile){
                mobile = perm[i];
            }
        }
    }
    return mobile;

}

int getLMEPos(int perm[],int n,int mobile){
    int i;
    for(i = 1;i<=n;i++){
        if(perm[i] == mobile) break;
    }
    return i;
}

void getPermutation(int perm[],int dir[],int n){
    int mobile = getLME(perm,dir,n);
    int pos = getLMEPos(perm,n,mobile);
    if(dir[perm[pos]] == RtoL){     // swap pos with pos-1 element
        int temp = perm[pos];
        perm[pos] = perm[pos-1];
        perm[pos-1] = temp;
    }
    else{                           // swap pos with pos+1 element
        int temp = perm[pos];
        perm[pos] = perm[pos+1];
        perm[pos+1] = temp;
    }

    for(int i=1;i<=n;i++){
        if(perm[i] > mobile){
            if(dir[perm[i]] == RtoL) dir[perm[i]] = LtoR;
            else dir[perm[i]] = RtoL;
        }
    }
}

void printPermutation(int n){
    int dir[n+1];
    int perm[n+1];
    
    for(int i=1;i<=n;i++){
        perm[i] = i;
        dir[i] = RtoL;
    }
    for(int i=1;i<=n;i++){
        printf("%d",perm[i]);
    }
    printf("\n");

    int no = factorial(n);

    for(int i=1;i<no;i++){
        getPermutation(perm,dir,n);
        for(int i=1;i<=n;i++){
            printf("%d",perm[i]);
        }
         printf("\n");
    }

}


int main(){
    int n;
    clock_t start,end;
    printf("Enter the number of elements :");
    scanf("%d",&n);
    start = clock();
    printPermutation(n);
    end = clock();

    printf("\nThe time taken to generate all the permutations is : %lf",(double)(end - start)/CLOCKS_PER_SEC);



    return 0;
}
