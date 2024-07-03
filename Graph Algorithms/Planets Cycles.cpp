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
const int N2 = 3000;
const int INF = 1'000'000'000'000'000;
const int base = 311;
const int MOD = 1'000'000'007;
const int MULTITEST = 0;
int E[N], D[N];
int Map[N], Vis[N], Ok;
vector<int> Node;
void Dfs(int u){
    Vis[u] = 1;
     Map[u] = 1;
    int v = E[u];
    if (Vis[v] == 0) Dfs(v); else if (Vis[v] == 1) {Map[v] = 0; Ok = true;}
    if (Ok) Node.push_back(u);
    if (Map[u] == 0) Ok = false;
    Vis[u] = 2;
}
void Cal(int u){
    if (D[u]) return;
    int v = E[u];
    if (!D[v]) Cal(v);
    D[u] = D[v] + 1;
}
void enter(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> E[i];
    }
    for (int i = 1; i <= n; ++i) if (!Vis[i]){
        Node.clear();
        Dfs(i);
        int cnt = Node.size();
        Ok = false;
        for (int i : Node){
            //cout << i << ' ';
            D[i] = cnt;
        }
        //cout << nl;
    }
    for (int i = 1; i <= n; ++i) Vis[i] = 0;
    for (int i = 1; i <= n; ++i) if (!D[i]){
        Cal(i);
    }
    for (int i = 1; i <= n; ++i){
        cout << D[i] << ' ';
    }
}
int32_t main(){
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    //IOS;
    int q = 1;
    if (MULTITEST) cin >> q;
    while (q--){enter();}
}
