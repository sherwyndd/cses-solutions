/*
    Harder not smarter
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define F first
#define S second
#define nl "\n"
typedef pair<int,int> p;
const int N = 1'000'007;
const int N2 = 3'000;
const int INF = 1'000'000'000'000'000'000;
const int base = 311;
const int MOD = 1'000'000'007;
const int MULTITEST = 0;
int Sz[N], m, Vt[N], a[N];
vector<int> E[N];
void Dfs_Pre(int u, int v){
    ++m;
    Vt[u] = m;
    for (int i : E[u]) if (i != v){
        Dfs_Pre(i, u);
        Sz[u] += Sz[i];
    }
}
struct Segment{
    int sz;
    vector<int> St;
    vector<int> Lazy;
    void init(int n){
        sz = n;
        St.assign(n * 4 + 7, 0);
    }
    void Update(int id, int l, int r, int i, int val){
        if (i > r || i < l) return;
        if (l == r){
            St[id] = val;
            return;
        }
        int mid = l + r >> 1;
        Update(id * 2, l, mid, i, val);
        Update(id * 2 + 1, mid + 1, r, i, val);
        St[id] = St[id * 2] + St[id * 2 + 1];
    }
    void Update(int i, int val){
        Update(1, 1, sz, i, val);
    }
    int Get(int id, int l, int r, int u, int v){
        if (u > r || v < l) return 0LL;
        if (u <= l && r <= v) return St[id];
        int mid = l + r >> 1;
        return Get(id * 2, l, mid ,u, v) + Get(id * 2 + 1, mid + 1, r, u, v);
    }
    int Get(int l, int r){
        return Get(1, 1, sz, l, r);
    }
} Seg;
void enter(){
    int n, q;
    cin >> n >> q;
    Seg.init(n);
    for (int i = 1; i <= n; ++i){
        int x;
        cin >> a[i];
        Sz[i] = 1;
    }
    for (int i = 1; i < n; ++i){
        int x, y;
        cin >> x >> y;
        E[x].pb(y);
        E[y].pb(x);
    }
    Dfs_Pre(1, 0);
    for (int i = 1; i <= n; ++i){
        Seg.Update(Vt[i], a[i]);
    }
    while (q--){
        int k;
        cin >> k;
        if (k == 1){
            int i, x;
            cin >> i >> x;
            Seg.Update(Vt[i], x);
        }
        else{
            int u;
            cin >> u;
            int l = Vt[u];
            int r = l + Sz[u] - 1;
            //cout << l << ' ' << r << nl;
            cout << Seg.Get(l, r) << nl;
        }
    }
}
void solve(){
}
signed main(){
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    IOS;
    int q = 1;
    if (MULTITEST) cin >> q;
    while (q--){enter(); solve();}
}
