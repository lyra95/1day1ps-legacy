#include "sol.h"
#include "mySol.h"
#include <iostream>


int main()
{
    for(int i=1;i<=10;i++)
    {
        cout << sol(i) << endl;
    }

    for(int i=1;i<=10;i++)
    {
        cout << mySol(i) << endl;
    }
    return 0;
}