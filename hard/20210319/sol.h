#include <string>
#include <vector>
#include <stack>

using namespace std;

string sol(string number, int k) {
    stack<char> s;                                    
    for(char d:number)
    {
        while( !s.empty() && s.top()<d && k>0 )
        {
            s.pop();
            k--;
        }
        s.push(d);
    }

    while(k>0)
    {
        s.pop();
        k--;
    }

    string ans="";
    while(!s.empty())
    {
        ans = s.top() + ans;
        s.pop();
    }
    return ans;
}