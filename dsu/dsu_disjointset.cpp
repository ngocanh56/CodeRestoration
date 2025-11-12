#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
const int N=1e5 + 7;
int parent[2*N], siz[2*N];

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
    for(int i=0;i<n;i++) {
        parent[i] = i;
        siz[i] = 1;
    }    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".inp", "r", stdin);
    int q;
    cin>>n>>q;

    init();
    for(int i=1;i<=q;i++) {
        int u,v,t;
        cin>>t>>u>>v;
        if(t) {
            //cout<<u<<" "<<v<<'\n';
            //cout<<find_set(u)<<" "<<find_set(v)<<'\n';
            if(find_set(u) == find_set(v))      
                cout<<1<<'\n';
            else cout<<0<<'\n';
        } else {
            union_set(u,v);
        }

    }
    
    return 0;
}
