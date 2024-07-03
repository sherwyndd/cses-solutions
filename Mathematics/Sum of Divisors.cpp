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
const int N2 = 3000;
const int INF = 1'000'000'000'000'000'000;
const int base = 311;
const int MOD = 1'000'000'007;
const int MULTITEST = 0;
int I;
int Pow(int a, int b){
    if (b == 1) return a;
    int Half = Pow(a, b / 2);
    if (b % 2 == 0){
        return Half * Half % MOD;
    }
    else{
        return a * (Half * Half % MOD) % MOD;
    }
}
int Sum(int l, int r){
    int x = (l + r) % MOD;
    int y = x * ((r - l + 1) % MOD) % MOD;
    return (y * I) % MOD;
}
void enter(){
    int n;
    cin >> n;
    int Res = 0;
    I = Pow(2, MOD - 2);
    int L = 0;
    for (int i = 1; i * i <= n; ++i){
        Res = (Res + n / i * i) % MOD;
        L = i;
    }
    for (int i = 1; i * i <= n; ++i){
        int l = max(L + 1, n / (i + 1) + 1);
        int r = n / i;
        //cout << l << ' ' << r << ' ' << Sum(l, r) << nl;
        Res = (Res + Sum(l, r) * i % MOD) % MOD;
    }
    cout << Res;
}
int32_t main(){
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    IOS;
    int q = 1;
    if (MULTITEST) cin >> q;
    while (q--){enter();}
}
