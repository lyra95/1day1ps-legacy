// problem: https://programmers.co.kr/learn/courses/30/lessons/42883
// greedy solution
#include <string>
#include <vector>

using namespace std;
void makeDescending(string & number, int & k)   // make the digits decreasing by erasing at most k digits.
{                                               // this function ends either when k=0 or when all the digits are in decreasing. 
    int i=0;                                    // ending status: (k>0 && decreasing) or (k=0 && first few digits are in decreasing)
    while (i+1<number.size())
    {
        while(number[i+1]-number[i]>0 && i>=0)
        {
            if(k==0)
                return;
            k--;
            number = number.erase(i,1);
            i--;
        }
        i++;
    }
}
string mySol2(string number, int k) {
    makeDescending(number,k);
    return number.substr(0,number.size()-k);
}
/*
time analysis
makeDescending loops at most number.size() + k.
*/