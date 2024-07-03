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
vector<int> E[N];
vector<int> ans;
int In[N], Vis[N];
bool Cycle(int u){
    Vis[u] = 1;
    for (int i : E[u]){
        if (Vis[i] == 1){
            return true;
        }
        if (!Vis[i]){
            if (Cycle(i)) return true;
        }
    }
    //cout << u << nl;
    Vis[u] = 2;
    ans.pb(u);
    return false;
}
void enter(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int x, y;
        cin >> x >> y;
        In[y]++;
        E[x].pb(y);
    }
    for (int i = 1; i <= n; ++i) if (!Vis[i]){
        if (Cycle(i)){
            //cout << i << nl;
            cout << "IMPOSSIBLE";
            return;
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i : ans){
        cout << i << ' ';
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
