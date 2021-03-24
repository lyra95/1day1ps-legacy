#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    for(int x:arr){
        if(x%divisor==0) answer.push_back(x);
    }
    sort(answer.begin(),answer.end());
    return (answer.size()) ? answer : vector<int>{-1};
}