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
bool Vis[N];
int s, e, T[N];
vector<int> E[N];
bool Dfs_Cycle(int u, int v){
    T[u] = v;
    Vis[u] = true;
    for (int i : E[u]) if (i != v){
        if (Vis[i]){
            s = i;
            e = u;
            return true;
        }
        if (Dfs_Cycle(i, u)) return true;
    }
    return false;
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
        //cout << i << nl;
        if (Dfs_Cycle(i, 0)){
            vector<int> vec;
            vec.pb(s);
            vec.pb(e);
            //cout << s << ' ' << e << nl;
            while (T[e] != s){
                e = T[e];
                vec.pb(e);
            }
            vec.pb(s);
            reverse(vec.begin(), vec.end());
            cout << vec.size() << nl;
            for (int i : vec){
                cout << i << ' ';
            }
            return;
        }
    }
    cout << "IMPOSSIBLE";
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
