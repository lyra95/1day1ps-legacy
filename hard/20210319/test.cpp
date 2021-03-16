#include "mySol.h"
#include "mySol2.h"
#include "sol.h"
#include <iostream>

int main()
{
    vector<string> test_n ={"1924","1231234","4177252841"};
    vector<int> test_k = {2,3,4};
    vector<string> answer={"94","3234","775841"};

    for(int i=0;i<3;i++)
    {
        string my1 = mySol1(test_n[i],test_k[i]);       // recursive solution, O(n^2)
        string my2 = mySol2(test_n[i],test_k[i]);       // greedy, O(n+k)
        string s = sol(test_n[i],test_k[i]);            // greedy and stack, O(n+k)
        
        if (my1!=answer[i])
            cout << "mySol1: " << my1 << "    ans: " << answer[i] << endl;
        if (my2!=answer[i])
            cout << "mySol2: " << my2 << "    ans: " << answer[i] << endl;
        if (s!=answer[i])
            cout << "Sol: " << s << "    ans: " << answer[i] << endl;
    }
    cout << "test completed" << endl;
}