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
int Mx, Vt;
void Dfs(int u, int v, int t){
    if (t > Mx){
        Mx = t;
        Vt = u;
    }
    for (int i : E[u]) if (i != v){
        Dfs(i, u, t + 1);
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
    Mx = - 1;
    Dfs(1, 0, 0);
    Dfs(Vt, 0, 0);
    cout << Mx;
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
