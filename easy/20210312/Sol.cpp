#include "runners.h"
#include <algorithm>

using namespace std;

string sol(vector<string> & participant, vector<string> & completion) 
{
    sort(participant.begin(),participant.end());
    sort(completion.begin(),completion.end());

    for (int i=0 ; i<participant.size() ; i++)
    {
        if (participant[i] != completion[i])        // the first p doesn't match with c is the one not in completion.
            return participant[i];
    }
    return participant[-1];
}