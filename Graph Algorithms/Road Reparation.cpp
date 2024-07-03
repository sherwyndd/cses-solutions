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
int D[N];
vector<p> E[N];
void Prim(int n, int s){
    int Res = 0;
    for (int i = 1; i <= n; ++i){
        D[i] = INF;
    }
    int Cnt = 0;
    D[s] = 0;
    priority_queue<p, vector<p>, greater<p>> h;
    h.push({0, s});
    while (h.size()){
        p x = h.top();
        int u = x.S;
        int w = x.F;
        h.pop();
        if (w != D[u]) continue;
        Cnt++;
        Res += D[u]; D[u] = -INF;
        for (p i : E[u]){
            int v = i.F;
            int w = i.S;
            if (D[v] > w){
                D[v] = w;
                h.push({D[v], v});
            }
        }
    }
    if (Cnt != n) {cout << "IMPOSSIBLE"; return;}
    cout << Res;
}
void enter(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int x, y, w;
        cin >> x >> y >> w;
        E[x].push_back({y, w});
        E[y].push_back({x, w});
    }
    Prim(n, 1);
}
int32_t main(){
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    IOS;
    int q = 1;
    if (MULTITEST) cin >> q;
    while (q--){enter();}
}
