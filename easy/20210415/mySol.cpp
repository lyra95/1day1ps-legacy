#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    int days=0;
    switch (a)
    {
        case 1:
            days=b-1;
            break;
        case 2:
            days=b+30;
            break;
        case 3:
            days=b+30+29;
            break;
        case 4:
            days=b+30+29+31;
            break;
        case 5:
            days=b+30+29+31+30;
            break;
        case 6:
            days=b+30+29+31+30+31;
            break;
        case 7:
            days=b+30+29+31+30+31+30;
            break;
        case 8:
            days=b+30+29+31+30+31+30+31;
            break;
        case 9:
            days=b+30+29+31+30+31+30+31+31;
            break;
        case 10:
            days=b+30+29+31+30+31+30+31+31+30;
            break;
        case 11:
            days=b+30+29+31+30+31+30+31+31+30+31;
            break;
        case 12:
            days=b+30+29+31+30+31+30+31+31+30+31+30;
            break;
    }
    days = days%7;
    vector<string> day = {"FRI","SAT","SUN","MON","TUE","WED","THU"};
        
    return day[days];
}