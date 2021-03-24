#include <string>

using namespace std;

string solution(string s) {
    int q,r;
    q = s.size()/2;
    r = s.size()%2;
    return  s.substr(q-1+r,2-r);
}