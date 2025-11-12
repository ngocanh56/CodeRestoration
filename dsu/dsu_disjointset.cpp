//328479
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, m, k, t;
const int N=1e5 + 7;
const ll mod = 998244353;
int parent[N], siz[N];

int find_set(int v) {
    if(v == parent[v]) return v;
    int p = find_set(parent[v]); // Đệ quy lên cha của đỉnh v
    parent[v] = p; // Nén đoạn từ v lên gốc của cây
    return p;
}

void union_set(int u, int v) {
    u = find_set(u);
    v = find_set(v);

    if(u!=v) {
        if(siz[u]<siz[v]) swap(u,v);
        parent[v] = u;
        siz[u] += siz[v];
    }
}
int init() {
    for(int i=1;i<=n;i++) {
        parent[i] = i;
        siz[i] = 1;
    }    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".inp", "r", stdin);
    int n,q;
    cin>>n>>q;

    for(int i=1;i<=q;i++) {
        int u,v;
        cin>>t>>u>>v;
        if(t) {
            cin>>u>>v;
            if(find_set(u) == find_set(v))      
                cout<<1<<'\n';
            else cout<<0<<'\n';
        }

    }
    
    return 0;
}
