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
int a[N];
bool Dp[N];
void enter(){
    int n;
    cin >> n;
    int x = 0;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        x += a[i];
    }
    Dp[0] = 1;
    for (int i = 1; i <= n; ++i){
        for (int j = x; j >= 0; --j){
            if (j >= a[i]) Dp[j] += Dp[j - a[i]];
        }
    }
    int cnt = 0;
    for (int i = 1; i <= x; ++i){
        if (Dp[i]) cnt++;
    }
    cout << cnt << nl;
     for (int i = 1; i <= x; ++i){
        if (Dp[i]) cout << i << ' ';
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
