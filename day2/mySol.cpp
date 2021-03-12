#include <map>
#include "runners.h"

using namespace std;

string mySol(vector<string> & participant, vector<string> & completion) 
{
    map<string,int> m;
    
    for (auto & x : participant)
    {
        try
        {
            m[x] += 1;
        }
        catch(...) 
        {
            m[x] = 1;
        }
    }
    
    for (auto & x : completion)
    {
        m[x] -= 1;
    }
    
    for (auto & x : participant) 
    {
        if ( m[x] > 0)
            return x;
    }
    return "";
}