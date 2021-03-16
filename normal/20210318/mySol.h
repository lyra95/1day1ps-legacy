// problem: https://programmers.co.kr/learn/courses/30/lessons/49993
#include <string>
#include <vector>

using namespace std;

bool is_valid(const vector<int> & v){
    for(int i=0;i<v.size();i++){
        if (v[i]!=i)
            return false;
    }
    return true;
}

bool check(const string & skill, const string & tree){
    vector<int> v;
    for(char x:tree){
        int pos = skill.find(x);
        if (pos!=string::npos){
            v.push_back(pos);
        }
    }
    return is_valid(v);
}
int mySol(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(auto & tree:skill_trees){
        answer+= (check(skill,tree)) ? 1:0;
    }
    return answer;
}