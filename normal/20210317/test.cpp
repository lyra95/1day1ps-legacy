#include "mySol.h"
#include "sol.h"
#include <iostream>

int main()
{
    vector<int> testcase={1,2,3,4,5,6,7,8,9,10};
    vector<string> answer={"1","2","4","11","12","14","21","22","24","41"};

    for(int i=0;i<10;i++)
    {
        string my = mySol(i+1);
        string s = sol(i+1);

        if (my!=answer[i])
            cout << "mySol: " << my << "    ans: " << answer[i] << endl;
        if (s!=answer[i])
            cout << "Sol: " << s << "    ans: " << answer[i] << endl;
    }
    cout << "test completed" << endl;
}