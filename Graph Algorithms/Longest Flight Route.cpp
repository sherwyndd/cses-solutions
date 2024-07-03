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
const int INF = 1'000'000'000;
const int base = 311;
const int MOD = 1'000'000'007;
const int MULTITEST = 0;
vector<int> E[N];
vector<int> Node;
int Dp[N], Trace[N];
bool Vis[N];
void Topo(int u){
    Vis[u] = true;
    for (int i : E[u]) if (!Vis[i]){
        Topo(i);
    }
    Node.pb(u);
}
void enter(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int x, y;
        cin >> x >> y;
        E[x].pb(y);
    }
    for (int i = 1; i <= n; ++i) if (!Vis[i]){
        Topo(i);
    }
    reverse(Node.begin(), Node.end());
    for (int i = 2; i <= n; ++i){
        Dp[i] = -INF;
    }
    Dp[1] = 1;
    for (int i : Node){
        for (int j : E[i]){
            if (Dp[i] + 1 > Dp[j]){
                Dp[j] = Dp[i] + 1;
                Trace[j] = i;
            }
        }
    }
    if (Dp[n] < 1){
        cout << "IMPOSSIBLE";
        return;
    }
    cout << Dp[n] << nl;
    Node.clear();
    int t = n;
    Node.pb(t);
    while (t != 1){
        t = Trace[t];
        Node.pb(t);
    }
    reverse(Node.begin(), Node.end());
    for (int i : Node){
        cout << i << ' ';
    }
}
void solve(){
}
signed main(){
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    //IOS;
    int q = 1;
    if (MULTITEST) cin >> q;
    while (q--){enter(); solve();}
}
