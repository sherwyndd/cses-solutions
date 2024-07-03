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
int Dp[N2][N2];
void enter(){
    int m;
    int n;
    cin >> m >> n;
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
            if (i == j) Dp[i][j] = 1LL;
            else Dp[i][j] = INF;
        }
    }
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
            for (int k = 1; k < j; ++k){
                Dp[i][j] = min(Dp[i][j], Dp[i][k] + Dp[i][j - k]);
            }
            for (int k = 1; k < i; ++k){
                Dp[i][j] = min(Dp[i][j], Dp[k][j] + Dp[i - k][j]);
            }
        }
    }
    cout << Dp[m][n] - 1;
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
