#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int cost(char prev,char next,int x,int y, int len){
    if(prev=='X' || next=='X'){
        int p = (len-1)%2;
        int q = len-1-p;
        return min(0,min(p*x+q*y,q*x+p*y));
    } 
    if(prev!=next){
        if(prev=='C') return x;
        else return y;
    }
    else{
        return 0;
    }
}

int helper(int x, int y, string s){
    if(s.size()==0) return 0;
    int ans = 0;
    
    string t{};
    t = 'X'+s+'X';
    int i=0;
    while(i<t.size()){
        int j =i+1;
        for(j;j<t.size();++j){
            if(t[j]!='?') break;
        }

        if(j-i==1) {
            if(t[i]=='C' && t[j]=='J') ans+=x;
            else if(t[i]=='J' && t[j]=='C') ans+=y;
            i = j;
        }
        else{
            ans += cost(t[i],t[j],x,y,j-i-1);
            i = j;
        }
    }    
    return ans;
}

int main() {
    int t;
    cin >> t;
    int cnt=1;

    for(cnt;cnt<=t;cnt++){
        int x,y;
        string s;
        cin >> x >> y >> s;

        cout << "Case #"<<cnt<<": ";

        cout << helper(x,y,s) << endl;
        
    }
}