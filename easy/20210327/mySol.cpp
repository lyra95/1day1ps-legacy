/*
https://programmers.co.kr/learn/courses/30/lessons/42748
Use of <vector> library
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int helper(const vector<int> & array, int i, int j, int k){
    vector<int> arr;
    for(i;i<=j;i++){
        arr.push_back(array.at(i));
    }

    sort(arr.begin(),arr.end());

    return arr.at(k);
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

int main() {
    vector<int> arr{1,5,2,6,3,7,4};
    helper(arr,2,5,3);
    return 0;
}

/*
[1, 5, 2, 6, 3, 7, 4] 	[[2, 5, 3], [4, 4, 1], [1, 7, 3]] 	[5, 6, 3]*/