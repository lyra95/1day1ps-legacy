// https://programmers.co.kr/learn/courses/30/lessons/42586
/*
queue.front() : const ref to front
queue.pop()
queue.push()
*/
#include <vector>
#include <queue>

using namespace std;

int time_(const int progress, const int speeds)
{
    return ((100-progress)%speeds) ? (100-progress)/speeds + 1 : (100-progress)/speeds;
}

int deployOnce(queue<int> & q)
{
    int first = q.front();
    int ans = q.size();
    
    while(!q.empty() && first>=q.front())
    {
        q.pop();
    }
    
    return ans-q.size();
}
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    queue<int> q;
    for(int i=0;i<speeds.size();i++)
    {
        q.push(time_(progresses[i],speeds[i]));
    }

    vector<int> answer;
    while (!q.empty())
    {
        answer.push_back(deployOnce(q));
    }
    return answer;
}