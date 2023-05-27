#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isValidPosition(vector<string>& board,int row_index,int col_index,int n){

    for (int i =0;i<n;i++){
        if (board[row_index][i] == 'Q'){
            return false;
        }
    }

    int i = row_index;
    int j = col_index;

    while(j>=0){
        if(i<0) break;
        if(board[i][j] == 'Q'){
            return false;
        }
        i = i - 1;
        j = j - 1;

    }
    
    i = row_index;
    j = col_index;

    while(i<n){
        if(j<0) break;
        if(board[i][j] == 'Q'){
            return false;
        }
        i = i+1;
        j = j-1;
    }

    return true;
}


void solve(vector<vector<string> >& result,vector<string>&board,int n,int col_index){
    if(col_index == n){
        result.push_back(board);
        return ;
    }

    for (int row_index = 0;row_index<n;row_index++){
        if(isValidPosition(board,row_index,col_index,n)){
            board[row_index][col_index] = 'Q';

            solve(result,board,n,col_index+1);
        }
        board[row_index][col_index] = '.';

    }
    return ;
}

void solveNQueens(vector<vector<string> >& result,vector<string>&board,int n){

    solve(result,board,n,0);

}


int main(){
    int n = 4;
    vector<string> board(n,string(n,'.'));
    vector<vector<string> > result;

    solveNQueens(result,board,n);

  
    return 0;
}