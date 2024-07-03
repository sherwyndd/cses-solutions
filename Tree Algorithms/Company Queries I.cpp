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
int Up[N][30], x, n, q, u;
vector<int> E[N];
void DfsPre(int u, int v){
    Up[u][0] = v;
    //cout << u << ' ' << v << nl;
    for (int i = 1; i < 20; ++i){
        Up[u][i] = Up[Up[u][i - 1]][i - 1];
    }
    for (int i : E[u]) if (i != v){
        DfsPre(i, u);
    }
}
int Cal(int u, int k){
    for (int i = 0; (1 << i) <= k; ++i){
        if (k >> i & 1) u = Up[u][i];
    }
    return u;
}
void enter(){
    cin >> n >> q;
    for (int i = 2; i <= n; ++i){
        cin >> x;
        E[x].pb(i);
        E[i].pb(x);
    }
    DfsPre(1, 0);
    while (q--){
        cin >> u >> x;
        int t = Cal(u, x);
        if (t == 0) cout << -1 << nl; else cout << t << nl;
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
