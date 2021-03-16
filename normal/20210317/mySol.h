// problem: https://programmers.co.kr/learn/courses/30/lessons/12899
#include <string>
#include <vector>

using namespace std;

string decTo124(int n){
    string ans="";
    while (n>0){
        switch (n%3) {
            case 0:
                ans = "4"+ans;
                n -= 3;
                break;
            case 1:
                ans = "1"+ans;
                n -= 1;
                break;
            case 2:
                ans = "2"+ans;
                n -= 2;
                break;
        }
        n /= 3;
    }
    return ans;
}
string mySol(int n) {
    return decTo124(n);
}