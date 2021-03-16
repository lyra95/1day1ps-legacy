#include <string>
#include <vector>

using namespace std;
void makeDescending(string & number, int & k)
{
    int i=0;
    while (i+1<number.size())
    {
        if (k==0)
            break;
        while(number[i+1]-number[i]>0 && i>=0)
        {
            k--;
            number = number.erase(i,1);
            i--;
        }
        i++;
    }
}
string solution(string number, int k) {
    makeDescending(number,k);
    return number.substr(0,number.size()-k);
}