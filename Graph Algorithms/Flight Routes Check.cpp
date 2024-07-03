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
const int INF = 1'000'000'000'000'000;
const int base = 311;
const int MOD = 1'000'000'007;
const int MULTITEST = 0;
bool Vis[N];
int Cmp[N];
vector<int> E[N];
vector<int> Re[N];
vector<int> Node;
void Dfs(int u){
    Vis[u] = true;
    for (int i : E[u]) if (!Vis[i]){
        Dfs(i);
    }
    Node.push_back(u);
}
void Topo(int u){
    Vis[u] = true;
    for (int i : Re[u]) if (!Vis[i]){
        Topo(i);
    }
}
void enter(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int x, y;
        cin >> x >> y;
        E[x].push_back(y);
        Re[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i) if (!Vis[i]){
        //cout << 1 << nl;
        Dfs(i);
    }
    reverse(Node.begin(), Node.end());
    for (int i = 1; i <= n; ++i){
        Vis[i] = false;
    }
    int Scc = 0;
    for (int i : Node) if (!Vis[i]){
        Scc++;
        Cmp[Scc] = i;
        Topo(i);
    }
    if (Scc >= 2){
        cout << "NO" << nl << Cmp[2] << ' ' << Cmp[1];
    }
    else{
        cout << "YES";
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
