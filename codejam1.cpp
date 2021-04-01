#include <string>
#include <iostream>

#include <vector>


using namespace std;

int cost(vector<int> v, int n){
    if(n==0) return 0;
    if(n==1) return 0;
    vector<int> w(0);
    int j=0;
    for(int i=0;i<n;++i){
        if(v[i]==1){
            j=i;
            break;
        }
    }

    for(int i=j-1;i>=0;--i){
        w.push_back(v[i]-1);
    }
    for(int i=j+1;i<n;++i){
        w.push_back(v[i]-1);
    }

    return j+1+cost(w,n-1);
}

int main() {
    
    int t;
    cin >> t;
    int cnt=1;

    vector<int> res(0);

    for(cnt;cnt<=t;cnt++){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;++i){
            cin>>v[i];
        }
        res.push_back(cost(v,n));
    }

    for(int i=1;i<=t;i++){
        cout << "Case #"<<i<<": "<<res[i-1]<<endl;
    }
}