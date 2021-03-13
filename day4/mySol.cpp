#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> rmDuplicate(vector<int> & v) {
    vector<int> ans;
    ans.push_back(v[0]);
    for (int i=1; i<v.size();i++) {
        if (ans.back()!=v[i]) 
            ans.push_back(v[i]);
    }
    return ans;
}
vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    for (int i=0; i<numbers.size();i++){
        for (int j=i+1; j<numbers.size();j++){
            answer.push_back(numbers[i]+numbers[j]);
        }
    }
    
    sort(answer.begin(),answer.end());
    return rmDuplicate(answer);
}