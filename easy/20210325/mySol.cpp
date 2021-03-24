/*
https://programmers.co.kr/learn/courses/30/lessons/1845
*/
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{   
    sort(nums.begin(),nums.end());

    int answer=1;
    for(int i=0;i+1<nums.size();i++){
        if(nums[i]!=nums[i+1]) answer++;
    }
    return (answer>nums.size()/2) ? nums.size()/2 : answer;
}

int main(){
    return 0;
}