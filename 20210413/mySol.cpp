#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer;
    long long a_ = a;
    long long b_ = b;
    (a<b) ? answer=((b_-a_+1)*(a_+b_)) : answer=((a_-b_+1)*(a_+b_));
    return answer/2;
}