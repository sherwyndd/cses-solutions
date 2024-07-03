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
int Dp[N];
int PowMod(int a, int b){
    if (b == 0) return 1LL;
    if (b == 1) return a;
    int half = PowMod(a, b / 2);
    if (b % 2 == 0){
        return (half * half) % MOD;
    }
    else{
        return (a * (half * half) % MOD) %MOD;
    }
}
int Inv(int x){
    return PowMod(x, MOD - 2);
}
void enter(){
    int n;
    cin >> n;
    int Sum = n * (n + 1) / 2;
    if (Sum % 2 != 0){
        cout << 0;
        return;
    }
    Dp[0] = 1LL;
    for (int i  = 1; i <= n; ++i){
        for (int j = Sum / 2; j >= 1; --j){
           if (j >= i) Dp[j] = (Dp[j] + Dp[j - i]) % MOD;
        }
    }
    cout << (Dp[Sum / 2] * Inv(2)) % MOD;
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
