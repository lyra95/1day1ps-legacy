#include <string>
#include <vector>

using namespace std;


int digitSum(int x)
{
    int ans=0;
    while (x>0)
    {
        ans+=x%10;
        x/=10;
    }
    return ans;
}
bool solution(int x) {
    return x%digitSum(x)==0;
}