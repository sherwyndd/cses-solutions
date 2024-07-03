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
bool Vis[N];
int D[N], n, m, T[N];
vector<int> E[N];
void Bfs(int u){
    Vis[u] = true;
    queue<int> q;
    q.push(u);
    D[u] = 1;
    while (q.size()){
        int u = q.front();
        q.pop();
        for (int i : E[u]) if (!Vis[i]){
            D[i] = D[u] + 1;
            T[i] = u;
            if (i == n) return;
            Vis[i] = true;
            q.push(i);
        }
    }
}
void enter(){
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int x, y;
        cin >> x >> y;
        E[x].pb(y);
        E[y].pb(x);
    }
    Bfs(1);
    if (D[n] == 0){
        cout << "IMPOSSIBLE";
        return;
    }
    cout << D[n] << nl;
    vector<int> ans;
    ans.pb(n);
    while (T[n] != 0){
        n = T[n];
        ans.pb(n);
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
    //IOS;
    int q = 1;
    if (MULTITEST) cin >> q;
    while (q--){enter(); solve();}
}
