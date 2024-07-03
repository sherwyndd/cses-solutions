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
const int N = (1e6) + 7;
const int N2 = (1e3) + 7;
const int INF = (1e18);
const int base = 311;
const int MOD = (1e9) + 7;
const int MULTITEST = 0;
int Fac[N];
int Pow(int a, int b){
    int Res = 1;
    for  (; b > 0; b >>= 1, a = a * a % MOD){
        if (b & 1) Res = (Res * a) % MOD;
    }
    return Res;
}
int Inv(int x){
    return Pow(x, MOD - 2);
}
int Ckn(int k, int n){
    return Fac[n] * Inv(Fac[k] * Fac[n - k] % MOD) % MOD;
}
void enter(){
    int n;
    cin >> n;
    Fac[0] = 1;
    for (int i = 1; i <= n; ++i){
        Fac[i] = (Fac[i - 1] * i) % MOD;
    }
    if (n % 2 != 0){
        cout << 0;
        return;
    }
    cout << (Ckn(n / 2, n) - Ckn(n / 2 - 1, n) + MOD) % MOD;
}
int32_t main(){
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    IOS;
    int q = 1;
    if (MULTITEST) cin >> q;
    while (q--){enter();}
}
