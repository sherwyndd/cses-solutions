/*
    Harder not smarter
*/
#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt")
#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define F first
#define S second
#define nl "\n"
typedef pair<int,int> p;
const int N = (5e4) + 7;
const int N2 = (1e3) + 7;
const int INF = (1e18);
const int base = 311;
const int MOD = (1e9) + 7;
const int MULTITEST = 0;
vector<int> E[N], Re[N], Node, Ne[N];
bool Vis[N];
bitset<N> Dp[N];
int Comp[N], Scc;
void Topo(int u){
    Vis[u] = true;
    for (int i : E[u]) if (!Vis[i]){
        Topo(i);
    }
    Node.push_back(u);
}
void Dfs(int u){
    Comp[u] = Scc;
    Dp[Scc].set(u - 1);
    Vis[u] = true;
    for (int i : Re[u]) if (!Vis[i]){
        Dfs(i);
    }
}
void enter(){
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= m; ++i){
        int x, y;
        cin >> x >> y;
        E[x].push_back(y);
        Re[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i) if (!Vis[i]){
        Topo(i);
    }
    //cout << 1 << nl;
    for (int i = 1; i <= n; ++i){
        Vis[i] = false;
    }
    reverse(Node.begin(), Node.end());
    for (int i = 0; i < Node.size(); ++i) if (!Vis[Node[i]]){
        Scc += 1;
        Dfs(Node[i]);
    }
    for (int i = 1; i <= n; ++i){
        for (int j : E[i]){
            if (Comp[i] != Comp[j]) Ne[Comp[i]].push_back(Comp[j]);
        }
    }
    for (int i = Scc; i >= 1; --i){
        for (int j : Ne[i]){
            Dp[i] = (Dp[i] | Dp[j]);
        }
    }
    while (q--){
        int x, y;
        cin >> x >> y;
        bool ok = Dp[Comp[x]].test(y - 1);
        if (ok == false){
            cout << "NO" << nl;
        }
        else{
            cout << "YES" << nl;
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
