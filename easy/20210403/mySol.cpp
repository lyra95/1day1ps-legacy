#include <string>
using namespace std;

bool solution(string s)
{
    int p{},y{};
    for(char x:s){
        switch (x)
        {
        case ('p'):
            p++;
            break;
        case ('P'):
            p++;
            break;
        case ('y'):
            y++;
            break;
        case ('Y'):
            y++;
            break;
        }
    }
    return p==y;
}
int main(){
    solution("pPoooyY");
    return 0;
}