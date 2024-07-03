/*
    Harder not smarter
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define nl "\n"
typedef pair<int,int> p;
const int N = (2e5) + 7;
const int N2 = (1e3) + 7;
const int INF = (1e18);
const int base = 311;
const int MOD = (1e9) + 7;
const int MULTITEST = 0;
int up[N][22], TimeDfs, id[N], sz[N], h[N], tp[N], a[N];
vector<int> E[N];
void dfs_pre(int u, int v){
    up[u][0] = v;
    for (int i = 1; i <= 20; ++i){
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    sz[u] = 1;
    for (int i : E[u]) if (i != v){
        h[i] = h[u] + 1;
        dfs_pre(i, u);
        sz[u] += sz[i];
    }
}
void hld(int u, int v, int top){
    tp[u] = top;
    id[u] = ++TimeDfs;
    int mx = 0;
    int big = -1;
    for (int i : E[u]) if (i != v){
        if (sz[i] > mx){
            mx = sz[i];
            big = i;
        }
    }
    if (big != -1){
        hld(big, u, top);
    }
    for (int i : E[u]) if (i != v && i != big){
        hld(i, u, i);
    }
}
struct Seg{
    int n;
    vector<int> st;
    void Init(int _n){
        n = _n;
        st.assign(n * 4 + 7, 0);
    }
    void update(int id, int l, int r, int i, int val){
        if (i > r || i < l) return;
        if (l == r){
            st[id] = val;
            return;
        }
        int mid = l + r >> 1;
        update(id * 2, l, mid, i, val);
        update(id * 2 + 1, mid + 1, r, i, val);
        st[id] = max(st[id * 2], st[id * 2 + 1]);
    }
    void update(int i, int val){
        update(1, 1, n, i, val);
    }
    int get(int id, int l, int r, int u, int v){
        if (u > r || v < l) return 0;
        if (u <= l && r <= v){
            return st[id];
        }
        int mid = l + r >> 1;
        return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
    }
    int get(int l, int r){
        return get(1, 1, n, l, r);
    }
} Seg;
int Go(int u, int v){
    int Res = 0;
    while (u != v){
        if (u == tp[u]){
            Res = max(Res, a[u]);
            u = up[u][0];
        }
        else if (h[v] < h[tp[u]]){
            Res = max(Res, Seg.get(id[tp[u]], id[u]));
            u = up[tp[u]][0];
        }
        else{
            Res = max(Res, Seg.get(id[v], id[u]));
            break;
        }
    }
    return Res;
}
int lca(int u, int v){
    if (u != v){
        if (h[u] < h[v]) swap(u, v);
        int k = h[u] - h[v];
        for (int i = 0; (1LL << i) <= k; ++i) if (k >> i & 1){
            u = up[u][i];
        }
    }
    if (u == v) return u;
    int k = __lg(h[u]);
    for (int i = k; i >= 0; --i){
        if (up[u][i] != up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}
void enter(){
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i){
        int x, y;
        cin >> x >> y;
        E[x].push_back(y);
        E[y].push_back(x);
    }
    dfs_pre(1, 0);
    hld(1, 0, 1);
    Seg.Init(n);
    for (int i = 1; i <= n; ++i){
        Seg.update(id[i], a[i]);
    }
    while (q--){
        int query;
        cin >> query;
        if (query == 1){
            int u, x;
            cin >> u >> x;
            a[u] = x;
            Seg.update(id[u], x);
        }
        else{
            int u, v;
            cin >> u >> v;
            int res = max(a[u], a[v]);
            int P = lca(u, v);
            res = max(res, a[P]);
            res = max(res, Go(u, P));
            res = max(res, Go(v, P));
            cout << res << ' ';
        }
    }
}
int32_t main(){
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    IOS;
    int q = 1;
    if (MULTITEST) cin >> q;
    while (q--){enter();}
}
