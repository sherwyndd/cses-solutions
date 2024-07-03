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
int n, m;
int Dp[N2][N2];
const int MULTITEST = 0;
void Generate(int pos, int i, int mask, int nmask, int x){
    if (pos == n){
        //if (i == 1 && mask == 0) cout << nmask << ' ' << x << nl;
        Dp[i + 1][nmask] = (Dp[i + 1][nmask] + x) % MOD;
        return;
    }
    if (!(mask >> pos & 1)){
        Generate(pos + 1, i, mask, nmask | (1 << pos), x);
    }
    if (pos < n - 1 && !(mask >> pos & 1) && !(mask >> (pos + 1) & 1)){
        Generate(pos + 2, i, mask, nmask, x);
    }
    if ((mask >> pos & 1)){
        Generate(pos + 1, i, mask, nmask, x);
    }
}
void enter(){
    cin >> n >> m;
    Dp[1][0] = 1LL;
    int Bitmx = (1 << n);
    for (int i = 1; i <= m; ++i){
        for (int j = 0; j < Bitmx; ++j){
            Generate(0, i, j, 0, Dp[i][j]);
        }
    }
    cout << Dp[m + 1][0];
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
