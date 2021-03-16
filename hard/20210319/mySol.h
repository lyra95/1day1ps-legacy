// problem: https://programmers.co.kr/learn/courses/30/lessons/42883
// recursive solution
#include <string>
#include <vector>

using namespace std;
int findLeading(const string & number, const int k)       // find the maximum leading digit by erasing at most k digits. 
{   
    int max=0;
    for(int i=0;i<k+1 && i<number.size();i++)
    {
        if(number[max]<number[i])
            max=i;
    }
    
    return max;
}
string mySol1(string number, int k) {
    string answer = "";
    if(number.size()==0)
        return answer;
    if(k==0)
        return number;
    if(k==number.size())
        return answer;
    
    int lead = findLeading(number,k);
    answer = number[lead] + mySol1(number.substr(lead+1),k-lead);
    return answer;
}
/*
worstcase: number = 1000000...000000, k = size-1
findLeading always goes full loop of k.
one recursive call reduce the length of number and k by 1.
running time = size-1 + size-2 + ... + 1 = O(size^2).
*/