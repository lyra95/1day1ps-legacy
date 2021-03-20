#include<vector>
#include<iostream>
using namespace std;

int main()
{
    vector<vector<int>> board(2,vector<int>(3,0));
    board[0][2] = 1;
    for(int i=0;i<2;++i){
        cout << board[i][2] << endl;
    }

    return 0;
}