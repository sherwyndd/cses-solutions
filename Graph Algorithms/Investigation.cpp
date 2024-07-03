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
struct Node{
    int Wei;
    int Way;
    int Sma;
    int Lar;
} Dp[N];
bool Vis[N];
vector<p> E[N];
int n, m;
void Djtra(int u){
    for (int i = 1; i <= n; ++i){
        Dp[i].Wei = INF;
        Dp[i].Way = 0;
        Dp[i].Sma = INF;
        Dp[i].Lar = -INF;
        Vis[i] = false;
    }
    Dp[u].Wei = 0LL;
    Dp[u].Sma = 0;
    Dp[u].Way = 1;
    Dp[u].Lar = 0;
    priority_queue<p, vector<p>, greater<p>> h;
    h.push({Dp[u].Wei, u});
    while (h.size()){
        p x = h.top();
        h.pop();
        int u = x.S;
        if (Vis[u]) continue;
        Vis[u] = true;
        for (p i : E[u]){
            int v = i.F;
            int w = i.S;
            if (Dp[u].Wei + w < Dp[v].Wei){
                Dp[v].Wei = Dp[u].Wei + w;
                Dp[v].Way = Dp[u].Way;
                Dp[v].Sma = Dp[u].Sma + 1;
                Dp[v].Lar = Dp[u].Lar + 1;
                h.push({Dp[v].Wei, v});
            }
            else if (Dp[u].Wei + w == Dp[v].Wei){
                Dp[v].Way = (Dp[v].Way + Dp[u].Way) % MOD;
                Dp[v].Lar = max(Dp[v].Lar, Dp[u].Lar + 1);
                Dp[v].Sma = min(Dp[v].Sma, Dp[u].Sma + 1);
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
    cout << Dp[n].Wei << ' ' << Dp[n].Way << ' ' << Dp[n].Sma << ' ' << Dp[n].Lar;
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
