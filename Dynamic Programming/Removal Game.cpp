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
const int N2 = 5'001;
const int INF = 1'000'000'000'000'000'000;
const int base = 311;
const int MOD = 1'000'000'007;
const int MULTITEST = 0;
int a[N], Sum[N], Dp[N2][N2];
void enter(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        Dp[i][i] = a[i];
        Sum[i] = Sum[i - 1] + a[i];
    }
    for (int k = 2; k <= n; ++k){
        for (int i = 1; i <= n - k + 1; ++i){
            int j = i + k - 1;
            int x = Sum[j - 1] - Sum[i - 1];
            Dp[i][j] = (x - Dp[i][j - 1]) + a[j];
            x = Sum[j] - Sum[i];
            Dp[i][j] = max(x - Dp[i + 1][j] + a[i], Dp[i][j]);
        }
    }
    cout << Dp[1][n];
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
