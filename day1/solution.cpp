#include <vector>
#include "PrimeNumbers.h"

using namespace std;

int solution(int n)
{
    vector<bool> nums(n+1,true);    // created a vector of "size n+1" and initalize its the all elements to "true".

    // 0 and 1 are not primes.
    nums[0] = false;
    nums[1] = false;

    // falsing muliples
    for (int i=2 ; i <= n ; i++)
    {
        if (nums[i])    // minimum i with nums[i]==true  <==> i:prime
        {
            for (int j=2 ; i*j <=n ; j++)
            {
                nums[i*j] = false;
            }
        }
    }

    int ans = 0;
    for (auto m: nums)
    {
        if (m) ans++;
    }
    return ans;
}