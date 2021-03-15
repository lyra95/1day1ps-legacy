#include <vector>

using namespace std;

vector<int> mySol(vector<int> prices) {
    vector<int> stack;
    vector<int> answer(prices.size());
    stack.push_back(prices.size()-1);
    for(int i=prices.size()-1;i>=0;i--){
        int pos=stack.back();       // math. Induction: pos is always i+1
        if (prices[i]>prices[pos]){         // prices[i] > prices[i+1], so decreasing in 1 sec.
            answer[i] = 1;
            stack.push_back(i);
        }
        else{
            while (prices[i]<=prices[pos]){         // pop until prices[i] > prices[top(=pos)] 
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