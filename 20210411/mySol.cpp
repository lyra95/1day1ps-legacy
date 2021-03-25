#include <string>
#include <vector>

using namespace std;
vector<int> convert(int n){
    vector<int> v(0);
    while (true){
        if (n<3){
            v.push_back(n);
            break;
        }
        v.push_back(n%3);
        n /= 3;
    }
    return v;
}
int solution(int n) {
    vector<int> v = convert(n);
    int answer = 0;
    for(int i=0;i<v.size();i++){
        answer = 3*answer + v[i];
    }
    return answer;
}