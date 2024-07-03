/*
    Harder not smarter
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 2'00'007;
int Sta[N], End[N], m, a[N];
vector<int> E[N];
struct SegmentTree{
    int n;
    vector<long long> st;
    void init(int sz){
        n = sz;
        st.assign(n * 4 + 7, 0);
    }
    void update(int id, int l, int r, int i, int val){
        if (i > r || i < l) return;
        if (l == r){
            st[id] = val * 1LL;
            return;
        }
        int mid = l + r >> 1;
        update(id * 2, l, mid , i, val);
        update(id * 2 + 1, mid + 1, r, i, val);
        st[id] = st[id * 2] + st[id * 2 + 1];
 
    }
    void update(int i, int val){
        update(1, 1, n, i, val);
    }
    long long get(int id, int l, int r, int u, int v){
        if (u > r || v < l) return 0LL;
        if (u <= l && r <= v) return st[id];
        int mid = l + r >> 1;
        return get(id * 2, l, mid ,u, v) + get(id * 2 + 1, mid + 1, r, u, v);
    }
    long long get(int l, int r){
        return get(1, 1, n, l, r);
    }
} segtree;
void dfs_pre(int u, int v){
    m++;
    Sta[u] = m;
    for (int i : E[u]) if (i != v){
        dfs_pre(i, u);
    }
    m++;
    End[u] = m;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
       int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i){
        int x, y;
        cin >> x >> y;
        E[x].push_back(y);
        E[y].push_back(x);
    }
    dfs_pre(1, 0);
    segtree.init(m);
    for (int i = 1; i <= n; ++i){
        segtree.update(Sta[i], a[i] * 1LL);
        segtree.update(End[i], -a[i] * 1LL);
    }
    while (q--){
        int k;
        cin >> k;
        if (k == 1){
            int i, val;
            cin >> i >> val;
            segtree.update(Sta[i], val * 1LL);
            segtree.update(End[i], -val * 1LL);
        }
        else{
            int s;
            cin >> s;
            cout << segtree.get(Sta[1], Sta[s]) << '\n';
        }
    }
}
