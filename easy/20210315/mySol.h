#include <string>

using namespace std;

string mySol(int n) {
    int q = n/2;
    int r = n%2;

    string answer = "";
    for(int i=0;i<q;i++)
        answer+= "수박";
    if (r!=0)
        return answer+"수";

    return answer;
}