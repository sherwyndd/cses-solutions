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
vector<int> Node;
vector<int> E[N], Re[N];
int Scc, Comp[N];
bool Vis[N], a[N];
void Topo(int u){
    Vis[u] = true;
    for (int i : E[u]) if (!Vis[i]){
        Topo(i);
    }
    Node.push_back(u);
}
void Dfs(int u){
    Vis[u] = true;
    Comp[u] = Scc;
    for (int i : Re[u]) if (!Vis[i]){
        Dfs(i);
    }
}
void enter(){
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; ++i){
        char cx, cy;
        int x, y;
        cin >> cx >> x >> cy >> y;
        if (cx == '+'){
            x = 2 * x - 1;
        }
         else{
            x = 2 * x;
         }
         if (cy == '+'){
            y = 2 * y - 1;
         }
         else{
            y = 2 * y;
         }
        //cout << x << ' ' << y << nl;
        if (cx == '+'){
            E[x + 1].push_back(y);
            Re[y].push_back(x + 1);
        }
        else{
            E[x - 1].push_back(y);
            Re[y].push_back(x - 1);
        }
        if (cy == '+'){
            E[y + 1].push_back(x);
            Re[x].push_back(y + 1);
        }
        else{
            E[y - 1].push_back(x);
            Re[x].push_back(y - 1);
        }
    }
    n = 2 * n;
    for (int i = 1; i <= n; ++i) if (!Vis[i]){
        Topo(i);
    }
    for (int i = 1; i <= n; ++i){
        Vis[i] = false;
    }
    reverse(Node.begin(), Node.end());
    Scc = 0;
    for (int i = 0; i < Node.size(); ++i) if (!Vis[Node[i]]){
        Scc++;
        Dfs(Node[i]);
    }
    for (int i = 1; i <= n; i += 2){
        int u = i / 2 + 1;
        bool Ok;
        if (Comp[i] == Comp[i + 1]){
            cout << "IMPOSSIBLE";
            return;
        }
        a[u] = Comp[i] > Comp[i + 1];
    }
    for (int i = 1; i <= n / 2; ++i){
        if (a[i]) cout << '+'; else cout << '-';
        cout << ' ';
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
