/*
    Harder not smarter
*/
#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define F first
#define S second
#define nl "\n"
typedef pair<int,int> p;
const int N = 1'00'007;
const int N2 = 3'000;
const int INF = 1'000'000'000;
const int base = 311;
const int MOD = 1'000'000'007;
const int MULTITEST = 0;
vector<int> E[N];
bool Ok;
bool Vis[N];
int Col[N];
void Dfs(int u, int c){
    Col[u] = c;
    Vis[u] = true;
    int t = 1;
    if (c == 1) t = 2;
    for (int i : E[u]){
        if (Col[i] == c){
            Ok = true;
        }
        if (!Vis[i]) Dfs(i, t);
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
    for (int i = 1; i <= n; ++i) if (!Vis[i]){
        Dfs(i, 1);
    }
    if (Ok){
        cout << "IMPOSSIBLE";
        return;
    }
    for (int i = 1; i <= n; ++i){
        cout << Col[i] << ' ';
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
