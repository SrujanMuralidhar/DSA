#include<iostream>
#include<vector>
using namespace std;

struct Knapsack{
    int weight;
    int value;
};

int max(int a,int b){
    return a > b ? a:b;
}

int knapsack(vector<vector<int> >&dp,vector<Knapsack> &knapsackArr,int item_num,int knapsackCapacity,int i,int j){
    if (i == 0 || j == 0) {
        return 0;
    }
    if (dp[i][j] != -1){
        return dp[i][j];
    }
    if( j < knapsackArr[i-1].weight){
        dp[i][j] = knapsack(dp,knapsackArr,item_num,knapsackCapacity,i-1,j);
    }
    else{
        dp[i][j] = max(knapsack(dp,knapsackArr,item_num,knapsackCapacity,i-1,j) , knapsackArr[i-1].value + knapsack(dp,knapsackArr,item_num,knapsackCapacity,i-1,j - knapsackArr[i-1].weight));
    }
    return dp[i][j];
}

int main(){
    cout<<"Enter the number of items:";
    int item_num;
    cin>>item_num;
    vector<Knapsack> knapsackArr(item_num);
    cout<<"Enter the Knapsack capacity :";
    int knapsackCapacity;
    cin>>knapsackCapacity;
    cout<<"Enter the item weight and the corresponding item value :\n";
    for(int i = 0;i<item_num;i++){
        cin>>knapsackArr[i].weight>>knapsackArr[i].value;
    }
    vector<vector<int> > dp(item_num+1,vector<int> (knapsackCapacity+1,-1));

    int MaxProfit =  knapsack(dp,knapsackArr,item_num,knapsackCapacity,item_num,knapsackCapacity);

   cout<<"The maximum value that can be obtained is "<<MaxProfit<<endl;

   cout<<"Dp matrix :"<<endl;
   for(int i = 0;i<item_num;i++){
        for(int j = 0;j<knapsackCapacity;j++){
            if(dp[i][j] == -1){
                cout<<"-"<<" ";
            }
            else{
                cout<<dp[i][j]<<" ";
            }
        }
        cout<<endl;
   }

    return 0;
}
