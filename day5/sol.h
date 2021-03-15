#include <string>

using namespace std;

string sol(int n)
{   
    string ans = "";
    for(int i=0;i<n;i++)
    {
        i & 1 ? ans+="수" : ans+="박";
    }

    return ans;
}