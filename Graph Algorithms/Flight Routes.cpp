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
int n, m, k, D[N], Cnt[N];
vector<int> Ans[N];
vector<p> E[N];
void Djtra(int u){
    for (int i = 1; i <= n; ++i) {
        Cnt[i] = 0;
        D[i] = INF;
    }
    D[1] = 0;
    priority_queue<p, vector<p>, greater<p>> h;
    h.push({D[1], 1});
    while (h.size()){
        p x = h.top();
        int u = x.S;
        int d = x.F;
        Cnt[u]++;
        h.pop();
        if (Cnt[u] > k) continue;
        Ans[u].pb(d);
        for (p i : E[u]){
            int v = i.F;
            int w = i.S;
            h.push({d + w, v});
        }
    }
}
void enter(){
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i){
        int x, y, w;
        cin >> x >> y >> w;
        E[x].pb({y, w});
    }
    Djtra(1);
    for (int i : Ans[n]){
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
