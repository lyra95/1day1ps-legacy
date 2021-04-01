#include <string>
#include <iostream>
#include <vector>


using namespace std;

bool inline is_possible(int n, int c){
    return n-1 <= c && c <= (n*(n+1))/2 -1;
}
vector<int> partition(int n,int c){
    vector<int> ans(n-1,1);
    int remain = c-n+1;
    for(int i=0;i<n-1 && remain > 0;++i){
        (n-i>remain) ? ans[i]+=remain : ans[i]=n-i;
        remain -= ans[i]-1;
    }
    return ans;
}
vector<int> helper(int n, vector<int> & p){
    if(n==1){
        vector<int> ans{};
        ans.push_back(1);
        return ans;
    }

    vector<int> ans(n,0);
    int m = p[0];

    ans[m-1]=1;
    for(int i=m;i<n;i++){
        ans[i] = i+1;
    }
    if(m==1) return ans;
    p.erase(p.begin());
    vector<int> temp = helper(m-1,p);

    for(int i=m-2;i>=0;--i){
        ans[i] = temp[m-2-i]+1;
    }

    return ans;
}
vector<int> findOne(int n, int c){
    vector<int> pos = partition(n,c);
    
    return helper(n,pos);
}

int main() {
    int t;
    cin >> t;
    int cnt=1;

    for(cnt;cnt<=t;cnt++){
        int n,c;
        cin >> n >> c;

        cout << "Case #"<<cnt<<":";
        if(!is_possible(n,c)) cout <<" IMPOSSIBLE"<<endl;
        else{
            vector<int> ans = findOne(n,c);
            for(int i=0;i<ans.size();i++){
                cout << ' ' << ans[i];
            }
            cout << endl;
        }
    }
}