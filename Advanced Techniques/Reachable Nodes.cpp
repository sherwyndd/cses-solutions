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
bitset<N> Dp[N];
vector<int> Node, E[N];
bool Vis[N];
void Topo(int u){
    Vis[u] = true;
    for (int i : E[u]) if (!Vis[i]){
        Topo(i);
    }
    Node.push_back(u);
}
void enter(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int x, y;
        cin >> x >> y;
        E[x].push_back(y);
    }
    for (int i = 1; i <= n; ++i){
        Dp[i].set(i - 1);
    }
    for (int i = 1; i <= n; ++i) if (!Vis[i]){
        Topo(i);
    }
    for (int i = 0; i < Node.size(); ++i){
        for (int j : E[Node[i]]){
            Dp[Node[i]] = (Dp[Node[i]] | Dp[j]);
        }
    }
    for (int i =  1; i <= n; ++i){
        cout << Dp[i].count() << ' ';
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
