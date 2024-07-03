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
#define ve vector<int>
typedef pair<int,int> p;
const int N = 1'000'007;
const int N2 = 3'000;
const int INF = 1'000'000'000'000'000'000;
const int base = 311;
const int MOD = 1'000'000'007;
const int MULTITEST = 0;
int Up[N][30], H[N];
vector<int> E[N];
void DfsPre(int u, int v, int t){
    H[u] = t;
    Up[u][0] = v;
    for (int i = 1; i <= 20; ++i){
        Up[u][i] = Up[Up[u][i - 1]][i - 1];
    }
    for (int i : E[u]) if (i != v){
        DfsPre(i, u , t + 1);
    }
}
int Kth(int u, int k){
    for (int i = 0; (1 << i) <= k; ++i){
        if (k >> i & 1){
            u = Up[u][i];
        }
    }
    return u;
}
int Lca(int u, int v){
    if (u != v){
        if (H[u] < H[v]) swap(u, v);
        if (H[u] != H[v]) u = Kth(u, H[u] - H[v]);
    }
    if (u == v) return u;
    int k = __lg(H[u]);
    for (int i = k; i >= 0; --i){
        if (Up[u][i] != Up[v][i]){
            u = Up[u][i];
            v = Up[v][i];
        }
    }
    return Up[u][0];
}
int Dist(int u, int v){
    return H[u] + H[v] - 2 * H[Lca(u, v)];
}
void enter(){
    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; ++i){
        int x, y;
        cin >> x >> y;
        E[x].pb(y);
        E[y].pb(x);
    }
    DfsPre(1, 0, 0);
    while (q--){
        int x , y;
        cin >> x >> y;
        cout << Dist(x, y) << nl;
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
