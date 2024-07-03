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
int n, m;
vector<p> E[N];
int Dp[N][3];
bool Vis[N][3];
struct Node{
    int u;
    int w;
    int id;
};
struct cmp{
    bool operator ()(Node a, Node b){
        return a.w > b.w;
    }
};
void djtra(int u){
    for (int i = 1; i <= n; ++i){
        Vis[i][0] = false;
        Vis[i][1] = false;
        Dp[i][0] = INF;
        Dp[i][1] = INF;
    }
    priority_queue<Node, vector<Node>, cmp> h;
    Dp[u][0] = 0;
    h.push({u, 0, 0});
    while (h.size()){
        Node x = h.top();
        h.pop();
        int u = x.u;
        int w = x.w;
        int id = x.id;
        if (Vis[u][id]) continue;
        Vis[u][id] = true;
        for (p i : E[u]){
            int v = i.F;
            int w = i.S;
            if (id == 0){
                if (Dp[u][0] + w < Dp[v][0]){
                    Dp[v][0] = Dp[u][0] + w;
                    h.push({v, Dp[v][0], 0});
                }
                if (Dp[u][0] + (w / 2) < Dp[v][1]){
                    Dp[v][1] = Dp[u][0] + (w / 2);
                    h.push({v, Dp[v][1], 1});
                }
            }
            else{
                if (Dp[u][1] + w < Dp[v][1]){
                    Dp[v][1] = Dp[u][1] + w;
                    h.push({v, Dp[v][1], 1});
                }
            }
        }
    }
}
void enter(){
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int x, y , w;
        cin >> x >> y >> w;
        E[x].pb({y, w});
    }
    djtra(1);
    cout << min(Dp[n][0], Dp[n][1]);
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
