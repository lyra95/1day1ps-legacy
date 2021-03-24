/*
https://programmers.co.kr/learn/courses/30/lessons/42748
Use of iterators
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int helper(const vector<int> & array, int i, int j, int k){
    vector<int> arr=array;
    sort(arr.begin()+i,arr.begin()+j+1);
    return arr.at(i+k);
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for(vector<int> command:commands){
        int i,j,k;
        i = command[0]-1;
        j = command[1]-1;
        k = command[2]-1;
        answer.push_back(helper(array,i,j,k));
    }
    return answer;
}