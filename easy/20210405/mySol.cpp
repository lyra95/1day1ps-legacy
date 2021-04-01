using namespace std;

int solution(int n) {
    int ans = 0;
    int d = 1;
    while (d*d<n) {
        (n%d) ? d++ : ans+=d+(n/d++);
    }
    if (d*d==n)
        ans += d;
    return ans;
}