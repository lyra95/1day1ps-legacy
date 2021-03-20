// https://programmers.co.kr/learn/courses/30/lessons/12905
/*
dynamic programming.
let's identify squares as triple int (i,j,k), where (i,j) is the top left point and k is the size of square
say k(i,j) is the maximum possible size of the square at (i,j).

k(i-1,j-1) =
(1) board[i-1][j-1]==0
    0
(2) k(i,j-1)==k(i-1,j)==k
    (2)-a board[i-1+k][j-1+k] == 0
        k
    (2)-b board[i-1+k][j-1+k] == 1
        k+1
(3) k(i,j-1)!=k(i-1,j)==k
    min( k(i,j-1) ,k(i-1,j) ) + 1
*/
#include <vector>

using namespace std;
int helper(const vector<vector<int>> & board,const vector<vector<int>> & arr,int i,int j);
int findMax(const vector<vector<int>> & arr);
int solution(vector<vector<int>> board)
{   
    int row = board.size();
    int col = board[0].size();
    vector<vector<int>> arr(row,vector<int>(col,0));

    for(int i=0;i<row;++i){
        arr[i][col-1] = board[i][col-1];
    }
    for(int j=0;j<col;++j){
        arr[row-1][j] = board[row-1][j];
    }

    for(int i=row-1;i>0;--i){
        for(int j=col-1;j>0;--j){
            arr[i-1][j-1] = helper(board,arr,i,j);
        }
    }

    return findMax(arr);
}

int helper(const vector<vector<int>> & board,const vector<vector<int>> & arr,int i,int j){
    if(board[i-1][j-1]==0) return 0;
    int x = arr[i-1][j];
    int y = arr[i][j-1];
    if(x==y){
        if(board[i+x-1][j+x-1]==1) return x+1;
        return x;
    }
    if(x>y) return y+1;
    else return x+1;
}

int findMax(const vector<vector<int>> & arr){
    int ans=0;
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            if(arr[i][j]>ans) ans=arr[i][j];
        }
    }
    return ans*ans;
}

int main()
{
    vector<vector<int>> board={{0,0,1,1},{1,1,1,1}};
    return solution(board);
}