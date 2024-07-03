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
int Dp[N][3];
vector<int> E[N];
void Dfs(int u, int v){
    for (int i : E[u]) if (i != v){
        Dfs(i, u);
        Dp[u][0] += max(Dp[i][0], Dp[i][1]);
    }
    for (int i : E[u]) if (i != v){
        Dp[u][1] = max(Dp[u][1], Dp[i][0] + 1 + Dp[u][0] - max(Dp[i][0], Dp[i][1]));
    }
}
void enter(){
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i){
        int x, y;
        cin >> x >> y;
        E[x].pb(y);
        E[y].pb(x);
    }
    Dfs(1, 0);
    cout << max(Dp[1][0], Dp[1][1]);
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
