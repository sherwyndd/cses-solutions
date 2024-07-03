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
bool Vis[N];
void Dfs(int u){
    Vis[u] = true;
    for (int i : E[u]) if (!Vis[i]){
        Dfs(i);
    }
}
void enter(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int x, y;
        cin >> x >> y;
        E[x].pb(y);
        E[y].pb(x);
    }
    vector<int> vec;
    for (int i = 1; i <= n; ++i) if (!Vis[i]){
        vec.pb(i);
        Dfs(i);
    }
    cout << vec.size() - 1 << nl;
    for (int i = 0; i < vec.size() - 1; ++i){
        cout << vec[i] << ' ' << vec[i + 1] << nl;
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
