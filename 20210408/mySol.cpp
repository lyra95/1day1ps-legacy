#include <string>
using namespace std;

string solution(int num) {
    string ans;
    (num%2==0) ? ans="Even" : ans="Odd";
    return ans;
}