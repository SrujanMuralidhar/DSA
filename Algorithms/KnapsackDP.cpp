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

int knapsack(vector<Knapsack> &knapsackArr,int item_num,int knapsackCapacity){
   vector<vector<int> > dp(item_num+1,vector<int> (knapsackCapacity+1,0));

   for(int i = 1;i<=item_num;i++){
        for(int j = 1;j<=knapsackCapacity;j++){
            if( j < knapsackArr[i-1].weight){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j],knapsackArr[i-1].value + dp[i-1][j - knapsackArr[i-1].weight]);
            }
        }
   }

   return dp[item_num][knapsackCapacity];
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

    int MaxProfit =  knapsack(knapsackArr,item_num,knapsackCapacity);

   cout<<"The maximum value that can be obtained is "<<MaxProfit<<endl;

    return 0;
}
