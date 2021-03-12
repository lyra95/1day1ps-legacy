#include "runners.h"
#include <iostream>

using namespace std;

void testSol(vector<string> & p, vector<string> & c, string & ans)
{
    string res = sol(p, c);
    if (res!=ans)
    {
        cout << "solution test failed: ans,output=" << ans << "," << res << endl;
    }
}
void testMySol(vector<string> & p, vector<string> & c, string & ans)
{
    string res = mySol(p, c);
    if (res!=ans)
    {
        cout << "my solution test failed: ans,output=" << ans << "," << res << endl;
    }
}

int main()
{
    vector<string> test_p = {"leo", "kiki", "eden"};
    vector<string> test_c = {"eden", "kiki"};
    string ans = "leo";

    testSol(test_p,test_c,ans);
    testMySol(test_p,test_c,ans);
    return 0;
}