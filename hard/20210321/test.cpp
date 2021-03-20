#include "mySol.cpp"
#include <iostream>

using namespace std;

int main()
{
    vector<string> test={"17","011"};
    vector<int> ans={3,2};

    for(int i=0;i<2;++i)
    {
        cout << "mySol: " << mySol(test[i]) << "    ans: "<< ans[i] << endl; 
    }
}