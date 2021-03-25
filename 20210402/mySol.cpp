#include <string>
#include <queue>

using namespace std;

int parser(queue<char> & q, char & type){
    int pts;
    
    pts = q.front()-'0';
    q.pop();

    if(q.front()=='0'){
        pts = 10;
        q.pop();
    }
    switch (q.front())
    {
    case 'D':
        pts = pts*pts;
        break;
    
    case 'T':
        pts = pts*pts*pts;
        break;
    default:
        break;
    }
    q.pop();

    if(!q.empty() && !isdigit(q.front())){
        type = q.front();
        q.pop();
    }

    return pts;
}
void scoreUpdate(int & score, int pts,char type, int & prev_pts){
    switch (type)
    {
        case '*':
            score += prev_pts+2*pts;
            prev_pts = 2*pts;
            break;
        case '#':
            score -= pts;
            prev_pts = -pts;
            break;
        default:
            score += pts;
            prev_pts = pts;
            break;
    }
}
int solution(string dartResult) {
    queue<char> q;
    for(char c:dartResult){
        q.push(c);
    }

    int score = 0;
    int prev_pts=0;
    while(!q.empty()){
        char type='0';
        int pts=parser(q,type);
        scoreUpdate(score,pts,type,prev_pts);
    }
    return score;
}
int main(){
    solution("1D2S#10S");
    return 0;
}