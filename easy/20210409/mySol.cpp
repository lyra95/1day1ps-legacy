#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    long long n=num;
    int answer = 0;
    while (n>1){
        if (answer == 500) 
            return -1;
        (n & 1) ? n=3*n+1 : n/=2;
        answer++;
    }
    return answer;
}