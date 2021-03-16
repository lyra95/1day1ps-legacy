#include <vector>
#include <stack>

using namespace std;

vector<int> sol2(vector<int> prices) {
    stack<int> s;
    vector<int> answer(prices.size());
    s.push(prices.size()-1);
    for(int i=prices.size()-1;i>=0;i--){
        int pos=s.top();       // math. Induction: pos is always i+1
        if (prices[i]>prices[pos]){         // prices[i] > prices[i+1], so decreasing in 1 sec.
            answer[i] = 1;
            s.push(i);
        }
        else{
            while (prices[i]<=prices[pos]){         // pop until prices[i] > prices[top(=pos)] 
                s.pop();
                if (s.size()==0){
                    pos = prices.size()-1;
                    break;
                }
                pos = s.top();
            }
            answer[i] = pos-i;
            s.push(i);
        }
    }
    return answer;
}