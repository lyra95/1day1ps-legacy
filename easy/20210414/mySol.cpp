#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> score(3,0);
    
    vector<int> one{1,2,3,4,5};;
    vector<int> two{2,1,2,3,2,4,2,5};
    vector<int> thr{3,3,1,1,2,2,4,4,5,5};
    
    int N = answers.size();
    for(int i=0;i<N;i++){
        score[0] += (answers[i]==one[i%5]) ? 1 : 0;   
    }
    for(int i=0;i<N;i++){
        score[1] += (answers[i]==two[i%8]) ? 1 : 0;   
    }
    for(int i=0;i<N;i++){
        score[2] += (answers[i]==thr[i%10]) ? 1 : 0;   
    }
    
    int max= 0;
    answer.push_back(1);
    for(int i=1;i<3;i++){
        if (score[max]<score[i]){
            answer={i+1};
            max = i;
        }
        else if (score[max]==score[i]){
            answer.push_back(i+1);
            max = i;
        }
    }
    
    return answer;
}