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
string s, st;
int Dp[N2][N2];
void enter(){
    cin >> s >> st;
    for (int i = 0; i <= s.size(); ++i){
        for (int j = 0 ; j <= st.size(); ++j){
            Dp[i][j] = INF;
        }
    }
    Dp[0][0] = 0;
    for (int i = 0; i <= s.size(); ++i){
        for (int j = 0; j <= st.size(); ++j){
            if (i) Dp[i][j] = min(Dp[i][j], Dp[i - 1][j] + 1);
            if (j) Dp[i][j] = min(Dp[i][j], Dp[i][j - 1] + 1);
            if (i && j) Dp[i][j] = min(Dp[i][j], Dp[i - 1][j - 1] + (s[i - 1] != st[j - 1]));
            //cout << i << ' ' << j << ' ' << Dp[i][j] << nl;
        }
    }
    cout << Dp[s.size()][st.size()];
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
