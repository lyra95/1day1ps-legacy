#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long x = 1;
    while (x*x<n)
        x++;
    if (x*x==n)
        return (x+1)*(x+1);
    else
        return -1;
        
}