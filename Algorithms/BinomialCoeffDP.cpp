#include<iostream>
#include<vector>
using namespace std;

int min(int a,int b){
    return a < b ? a:b;
}

int binomialcoeff(int n,int k){
    vector<vector<int> > dp(n+1,vector<int>(k+1,0));
    
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=min(i,k);j++){
            if(j == 0 || i == 0){
                dp[i][j] = 1;
            }
            else{
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            }
        }
    }
    return dp[n][k];   

}

int main(){
    int n,k;
    cout<<"Enter the number of elements:";
    cin>>n;
    cout<<"Enter the number of objects selected :";
    cin>>k;

    int res = binomialcoeff(n,k);
    cout<<"The value of the coefficient is :"<<res;
    return 0;
    
}
