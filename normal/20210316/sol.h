#include <vector>

using namespace std;

vector<int> sol1(vector<int> prices) {
    vector<int> answer(prices.size());
    for(int i=0;i<prices.size()-1;i++)
    {   
        answer[i] = prices.size()-1-i;
        for(int j=i+1;j<prices.size();j++){
            if (prices[i]>prices[j]){
                answer[i] = j-i;
                break;
            }
        }
    }
    answer[prices.size()-1] = 0;
    return answer;
}