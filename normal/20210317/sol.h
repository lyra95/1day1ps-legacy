// problem: https://programmers.co.kr/learn/courses/30/lessons/12899
#include <string>
#include <vector>

using namespace std;

string decTo124_(int n){
    string ans="";
    while (n>0){
        int r = n%3;
        ans = ans+"412"[r];
        vector<int> remainder = {3,1,2};
        n -= remainder[r];
        n /= 3;
    }
    return ans;
}
string sol(int n) {
    return decTo124_(n);
}