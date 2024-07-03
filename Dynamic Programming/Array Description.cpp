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
const int N = 1'00'001;
const int N2 = 3'000;
const int INF = 1'000'000'000'000'000'000;
const int base = 311;
const int MOD = 1'000'000'007;
const int MULTITEST = 0;
int n, m, a[N], Dp[N][102];
void enter(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    if (a[1] == 0){
        for (int i = 1; i <= m; ++i){
            Dp[1][i] = 1;
        }
    }
    else{
        Dp[1][a[1]] = 1;
    }
    for (int i = 2; i <= n; ++i){
        if (a[i] == 0){
            for (int j = 1; j <= m; ++j){
                Dp[i][j] = (Dp[i - 1][j] + Dp[i - 1][j - 1] + Dp[i - 1][j + 1]) % MOD;
            }
        }
        else{
            Dp[i][a[i]] = (Dp[i - 1][a[i]] + Dp[i - 1][a[i] - 1] + Dp[i - 1][a[i] + 1]) % MOD;
        }
    }
    int res = 0;
    for (int i = 1; i <= m; ++i){
        res = (res + Dp[n][i]) % MOD;
    }
    cout << res;
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
