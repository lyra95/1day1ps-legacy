#include <string>
#include <vector>

using namespace std;
int distance(char thumb, int key){
    switch (key)
    {
    case 2:
        
        break;
    
    default:
        break;
    }
}
char whichFinger(int key, char & left, char & right, int leftHanded = 0){
    switch (key)
    {
    case 1: case 4: case 7:
        left = key;
        return 'L';
    
    case 2: case 5: case 8:
        right = key;
        return 'R';
    
    default:
        break;
    }
}
string solution(vector<int> numbers, string hand) {
    char left = '*';
    char right = '#';
    int lefthanded = (hand=="left") ? 1 : 0;

    string answer = "";
    for(int key: numbers)
    {
        answer.push_back(whichFinger(key,left,right,lefthanded));
    }
    return answer;
}