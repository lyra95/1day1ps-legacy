#include "mySol.h"
#include <iostream>

int main()
{
    string skill="CBD";
    vector<string> skill_trees={"BACDE", "CBADF", "AECB", "BDA"};
    int ans = 2;
    int result = mySol(skill,skill_trees);
    if (ans!=result)
        cout <<  "mySol: "<< result<<"      ans: "<<ans<<endl;
    cout << "test completed" << endl;

    return 0;
}