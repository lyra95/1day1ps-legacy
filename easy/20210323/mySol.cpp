/*
problem: https://programmers.co.kr/learn/courses/30/lessons/64061
Objective: make the code easily readable
Caution: data representation of the board. board[0] represent the top level. board.size() = the height. board[0].size() = the width.
*/

#include <string>
#include <vector>

using namespace std;
int answer;

void putToBasket(vector<int> & basket, int doll){
    // assume doll != 0
    if(basket.empty()){
        basket.push_back(doll);
    } else{
        int lastDoll = basket.back();
        if(doll==lastDoll){
            basket.pop_back();
            ++answer;
        } else{
            basket.push_back(doll);
        }
    }
    return;
}
int getDoll(vector<vector<int>> & board, const int x){
    int h = 0;  // height
    int doll = 0;
    while(h<board.size())
    {
        if(board[h][x]>0) 
        {
            doll = board[h][x];
            board[h][x] = 0;
            break;
        }
        ++h;
    }
    return doll;    // warning: doll==0 means no doll has been gotten.
}

int solution(vector<vector<int>> board, vector<int> moves) {
    answer = 0;
    vector<int> basket;
    for(int x:moves)
    {
        int doll = getDoll(board,x-1);
        if(doll!=0) putToBasket(basket,doll);
    }

    return answer;
}

int main(){
    /*[[0, 0, 0, 0, 0], [0, 0, 1, 0, 3], [0, 2, 5, 0, 1], [4, 2, 4, 4, 2], [3, 5, 1, 3, 1]], [1, 5, 3, 5, 1, 2, 1, 4]*/
    vector<vector<int>> testBoard = {{0, 0, 0, 0, 0}, {0, 0, 1, 0, 3}, {0, 2, 5, 0, 1}, {4, 2, 4, 4, 2}, {3, 5, 1, 3, 1}};
    vector<int> testMoves = {1, 5, 3, 5, 1, 2, 1, 4};

    int ans = solution(testBoard,testMoves);
    return 0;
}