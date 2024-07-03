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
const int N2 = 3000;
const int INF = 1'000'000'000'000'000'000;
const int base = 311;
const int MOD = 1'000'000'007;
const int MULTITEST = 0;
vector<int> E[N], Re[N], Ne[N];
vector<int> Node;
bool Vis[N];
int a[N], n, Vt[N], New, D[N];
vector<int> Scc[N];
void Topo(int u){
    Vis[u] = true;
    for (int i : E[u]) if (!Vis[i]){
        Topo(i);
    }
    Node.push_back(u);
}
void Kosaraju(){
    for (int i = 1; i <= n; ++i) if (!Vis[i]){
        Topo(i);
    }
    reverse(Node.begin(), Node.end());
}
void Dfs(int u){
    Vis[u] = true;
    Scc[New].push_back(u);
    for (int i : Re[u]) if (!Vis[i]){
        Dfs(i);
    }
}
void enter(){
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i){
        int x, y;
        cin >> x >> y;
        E[x].push_back(y);
        Re[y].push_back(x);
    }
    Kosaraju();
    for (int i = 1; i <= n; ++i){
        Vis[i] = false;
    }
    New = 0;
    for (int i : Node) if (!Vis[i]){
        New++;
        Dfs(i);
        for (int j : Scc[New]){
            Vt[j] = New;
        }
    }
    for (int i = 1; i <= New; ++i){
        for (int j : Scc[i]){
            //cout << i << ' ' << j << nl;
            D[i] += a[j];
            for (int k : E[j]) if (Vt[k] != i){
                Ne[i].push_back(Vt[k]);
            }
        }
    }
    int res = 0;
    for (int i = New; i >= 1; --i){
        int t = 0;
        for (int j : Ne[i]){
            t = max(t, D[j]);
        }
        D[i] = D[i] + t;
        res = max(res, D[i]);
    }
    cout << res;
}
signed main(){
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    IOS;
    int q = 1;
    if (MULTITEST) cin >> q;
    while (q--){enter();}
}
