//328479
#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
const int prime=31;
const int N = 5e5+7;
const ll mod = 1e9+7;
int n;
ll hs[N],base[N];
void init() {
    base[0] = 1;
    for(int i=1;i<=n;i++) {
        base[i] = base[i-1]*prime%mod;
    }  

    hs[0] = 0;
    for(int i=1;i<=n;i++) {
        ll val = (s[i] - 'a' + 1);
        hs[i] = (hs[i-1] * prime + val) %mod;
        //cout<<hs[i]<<'\n';
    }
}
ll cal(int u,int v) {
    return (hs[v] - hs[u-1] * base[v-u+1]%mod + mod*mod)%mod;
}
int find_lcs(int u, int v) {
    int r = v - u +1;
    int l = 0;
    int ans = 0;
    while(l<=r) {
        int mid = (l+r)/2;
        if(cal(u, u + mid - 1) == cal(1,mid)) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".inp", "r", stdin);
    
    cin>>s;
    n = s.length();
    s = '0'+s;

    init();
    for(int i=1;i<=n;i++) {
        cout<< find_lcs(i,n) <<'\n';
    }
    return 0;
}
