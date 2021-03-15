#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> stack;
    vector<int> answer(prices.size());
    stack.push_back(prices.size()-1);
    for(int i=prices.size()-1;i>=0;i--){
        int pos=stack.back();
        if (prices[i]>prices[pos]){
            answer[i] = 1;
            stack.push_back(i);
        }
        else{
            while (prices[i]<=prices[pos]){
                stack.pop_back();
                if (stack.size()==0){
                    pos = prices.size()-1;
                    break;
                }
                pos = stack.back();
            }
            answer[i] = pos-i;
            stack.push_back(i);
        }
    }
    return answer;
}
int main(){
    solution({1,2,3,2,3});
    return 0;
}