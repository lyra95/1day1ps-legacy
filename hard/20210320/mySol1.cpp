// https://programmers.co.kr/learn/courses/30/lessons/12905
/*
Not efficient. O(n^3).
*/
#include <iostream>
#include<vector>
using namespace std;

// fint the maximum possible size of square having (i,j) as the left top point.
int findSize(const vector<vector<int>>& board, int i,int j);

// check whether the square with size is possible, where (i,j) is the left top point.
bool checkSize(const vector<vector<int>>& board, int i,int j,int & size);

int mySol1(vector<vector<int>> board)
{
    int max =0;
    int row = board.size();
    int col = board[0].size();

    for(int i=0;i<row;++i)
    {
        for(int j=0;j<col;++j)
        {
            int temp = findSize(board,i,j);
            if(temp>max) max=temp;
        }
    }
    
    return max*max;
}

int findSize(const vector<vector<int>>& board, int i,int j){
    int row = board.size();
    int col = board[0].size();
    int k;
    (row-i > col-j) ? k = col-j: k=row-i;

    while(k>0)
    {   
        if(checkSize(board,i,j,k)) return k;
    }

    return k;
}

bool checkSize(const vector<vector<int>>& board, int i,int j,int & size){
    for(int x=0;x<size;++x){
        for(int y=0;y<size;++y){
            if(board[i+x][j+y]==0){
                (x>y) ? size =x : size=y;
                return false;
            }
        }
    }
    return true;
}