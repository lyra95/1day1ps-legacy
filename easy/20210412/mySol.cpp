#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(const char& x: s){
        int i = (int)x;
        if (64<i && i<91)    // x is UPPERCASE
            answer += (char)((i-65+n)%26 + 65);
        else if (96<i && i<123)   // x is lowercase
            answer += (char)((i-97+n)%26 +97);
        else
            answer+= x;
    }
    return answer;
}