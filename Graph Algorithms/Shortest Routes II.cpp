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
int W[N2][N2];
void enter(){
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j) if (i != j){
            W[i][j] = INF;
        }
    }
    for (int i = 1; i <= m; ++i){
        int x, y, w;
        cin >> x >> y >> w;
        W[x][y] = min(W[x][y], w);
        W[y][x] = min(W[y][x], w);
    }
 
    for (int k = 1; k <= n; ++k){
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= n; ++j) if (i != j){
                W[i][j] = min(W[i][j], W[i][k] + W[k][j]);
            }
        }
    }
    while (q--){
        int x, y;
        cin >> x >> y;
        if (W[x][y] >= INF){
            cout << -1 << nl;
        }
        else{
            cout << W[x][y] << nl;
        }
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
