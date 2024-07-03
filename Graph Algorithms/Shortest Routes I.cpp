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
int n, m, Dp[N];
vector<p> E[N];
bool Vis[N];
void Djtra(int u){
    for (int i = 1; i <= n; ++i){
        Vis[i] = false;
        Dp[i] = INF;
    }
    Dp[u] = 0LL;
    priority_queue <p, vector<p>, greater<p>> h;
    h.push({Dp[u], u});
    while (h.size()){
        p x = h.top();
        int u = x.S;
        h.pop();
        if (Vis[u]) continue;
        Vis[u] = true;
        for (p i : E[u]){
            int v = i.F;
            int w = i.S;
            if (Dp[u] + w < Dp[v]){
                Dp[v] =Dp[u] + w;
                h.push({Dp[v], v});
            }
        }
    }
}
void enter(){
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int x, y, w;
        cin >> x >> y >> w;
        E[x].pb({y, w});
    }
    Djtra(1);
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
