#include "PrimeNumbers.h"
#include <iostream>

using namespace std;

void testSol(int n, int ans)
{
    int res = solution(n);
    if (res!=ans)
    {
        cout << "solution test failed: n=" << n << ", output=" << res << ", ans=" << ans << endl;
    }
}
void testMySol(int n, int ans)
{
    int res = mySolution(n);
    if (res!=ans)
    {
        cout << "my solution test failed: n=" << n << ", output=" << res << ", ans=" << ans << endl;
    }
}
int main()
{
    testSol(10,4);
    testSol(100,25);

    testMySol(10,4);
    testMySol(100,25);

    cout << "test completed" << endl;
    return 0;
}