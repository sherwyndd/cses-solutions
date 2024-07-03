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
int Vis[N], Trace[N], Start, End;
vector<int> E[N];
bool Dfs(int u){
    Vis[u] = 1;
    for (int i : E[u]){
        if (Vis[i] == 0){
            Trace[i] = u;
            if (Dfs(i)) return true;
        }
        else if (Vis[i] == 1){
            Start = i;
            End = u;
            return true;
        }
    }
    Vis[u] = 2;
    return false;
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
        if (Dfs(i)){
            // print
            vector<int> ans;
            ans.pb(Start);
            ans.pb(End);
            while (End != Start){
                End = Trace[End];
                ans.pb(End);
            }
            reverse(ans.begin(), ans.end());
            cout << ans.size() << nl;
            for (int i : ans) cout << i << ' ';
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
    IOS;
    int q = 1;
    if (MULTITEST) cin >> q;
    while (q--){enter(); solve();}
}
