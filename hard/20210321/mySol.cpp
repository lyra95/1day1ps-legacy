// https://programmers.co.kr/learn/courses/30/lessons/42839
/*
next_permutation(s.begin(),s.end()) : modify s to next permutation return true. return false if no next permutation
*/
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
bool primality(const int n);

// return the set of all subset of string s with size k(represented as string of size k)
set<string> choose_k(string s, int k);

// k=s.size(). put (int) string t to the set nums, iterating over all k! possible strings t from s. 
void permutaion_k(string s,set<int> & nums);

int mySol(string numbers) {
    set<int> nums;
    for(int k=1;k<=numbers.size();k++){
        set<string> temp = choose_k(numbers,k);
        for(string s:temp){
            permutaion_k(s,nums);
        }
    }

    int answer=0;
    for(int n:nums){
        answer += primality(n);
    }
    return answer;
}
bool primality(const int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0)
            return false;
    }
    return n!=0 && n!=1;
}

set<string> choose_k(string s, int k){
    set<string> ans;
    switch (k)
    {
    case 1:
        for(int i=0;i<s.size();i++){
            ans.insert(s.substr(i,1));
        }
        return ans;
    
    default:
        for(int i=0;i<s.size();i++){
            string copy = s;
            set<string> temp = choose_k(copy.erase(i,1),k-1);
            for(string e:temp){
                string x = s[i]+e;
                sort(x.begin(),x.end());
                ans.insert(x);
            }
        }
    }
    return ans;
}

void permutaion_k(string s,set<int> & nums){
    do{
        nums.insert(stoi(s));
    }while(next_permutation(s.begin(),s.end()));
}