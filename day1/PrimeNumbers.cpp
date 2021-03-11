#include <string>
#include <vector>
#include <iostream>

using namespace std;

void seive(int p, vector<int> & v)
{
    int i=2;
    while (i*p <= v.size())
    {
        v[i*p -1] = 0;
        i++;
    }
}
int findNextPrime(int p, vector<int> & v)
{
    int ans = p;
    while (ans < v.size())
    {
        if (v[ans] > 0) return ++ans;
        ans++;
    }
    return ++ans;
}
int solution(int n) {
    vector<int> nums(n);
    
    for (auto & m: nums)
    {
        m++;
    }
    
    nums[0]--;
    
    int p = 2;
    while (p <= n)
    {
        seive(p, nums);
        p = findNextPrime(p, nums);
    }
    
    int answer = 0;
    for (auto m: nums)
    {
        answer += m;
    }
    return answer;
}

int main(){
    int n;
    cin >> n;
    cout << solution(n)<<endl;
    return 0;
}