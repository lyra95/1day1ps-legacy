/*
https://programmers.co.kr/learn/courses/30/lessons/42862
greedy, padding
*/

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> student(n+2,1);     // padded 1 at both end.

    for(int x:lost){
        student[x] = 0;
    }
    for(int x: reserve){
        student[x] += 1;
    }
    
    for(int i=1;i<=n;i++){
        if(student[i]==2){
            if(student[i-1]==0){
                student[i]--;
                student[i-1]++;
            } else if(student[i+1]==0){
                student[i]--;
                student[i+1]++;
            }
        }
    }
    
    int answer =0;
    for(int i=1;i<=n;i++){
        answer += (student[i]>0);
    }
    return answer;
}