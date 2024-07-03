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
int H[N], D[N], n, Dp[N];
vector<int> E[N];
void DfsPrepare(int u, int v){
    for (int i : E[u]) if (i != v){
        DfsPrepare(i, u);
        H[u] += H[i];
        D[u] += D[i] + H[i];
    }
}
void DfsCal(int u, int v){
    //cout << u << ' ' << v << ' ' << Dp[v] << nl;
    int x = H[u];
    for (int i : E[u]) if (i != v){
        Dp[u] = Dp[v] + (n - x) + D[u] - D[i] - H[i];
        DfsCal(i, u);
    }
    //cout << u << ' ' << v << ' ' << Dp[v] << nl;
    Dp[u] = D[u] + Dp[v] + (n - x); // cap nhat kq cho dinh u
}
void enter(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        H[i] = 1;
    }
    for (int i = 1; i < n; ++i){
        int x, y;
        cin >> x >> y;
        E[x].pb(y);
        E[y].pb(x);
    }
    DfsPrepare(1, 0);
    DfsCal(1, 0);
    for (int i = 1; i <= n; ++i){
        cout << Dp[i] << ' ';
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
