/*
https://programmers.co.kr/learn/courses/30/lessons/67256
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;
struct Pos{
    int x;
    int y;
};

Pos convert(int thumb){
    Pos a;
    switch (thumb)
    {
    case -1:
        a.x = 0;
        a.y = 0;
        break;

    case 0:
        a.x = 1;
        a.y = 0;
        break;
    
    case -2:
        a.x = 2;
        a.y = 0;
        break; 
    
    default:
        a.x = (thumb-1)%3;
        a.y = 3 - (thumb-1)/3;
        break;
    }
    return a;
}


int distance(int thumb, int key){
    Pos t = convert(thumb);
    Pos k = convert(key);
    return abs(t.x-k.x) + abs(t.y-k.y);
}
char whichFinger(int key, int & left, int & right, int leftHanded = 0){
    switch (key)
    {
    case 1: case 4: case 7:
        left = key;
        return 'L';
    
    case 3: case 6: case 9:
        right = key;
        return 'R';
    
    default:
        if(leftHanded){
            if(distance(left, key)>distance(right,key)){
                right = key;
                return 'R';
            }
            else{
                left = key;
                return 'L';
            }
        } 
        else{
            if(distance(left, key)<distance(right,key)){
                left = key;
                return 'L';
            }
            else{
                right = key;
                return 'R';
            }
        }
    }
}
string solution(vector<int> numbers, string hand) {
    int left = -1;
    int right = -2;
    int lefthanded = (hand=="left") ? 1 : 0;

    string answer = "";
    for(int key: numbers)
    {
        answer.push_back(whichFinger(key,left,right,lefthanded));
    }
    return answer;
}

int main(){
    while(true){
        int x;
        cin >> x;
        cout << convert(x).x << " , " << convert(x).y << endl;
    }
    return 0;
}