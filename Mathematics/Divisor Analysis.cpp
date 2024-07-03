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
int Pow(int a, int b){
    int Res = 1;
    for (;b > 0; b >>= 1, a = a * a % MOD){
        if (b & 1) Res = (Res * a) % MOD;
    }
    return Res;
}
int Inv(int a){
    return Pow(a, MOD - 2);
}
void enter(){
    int n;
    cin >> n;
    int Num = 1;
    int Sum = 1;
    int Product = 1;
    int Cnt = 1;
    for (int i = 1; i <= n; ++i){
        int a, b;
        cin >> a >> b;
        // First, Number of Divisor
        Num = (Num * (b + 1))  % MOD;
        // Second, Sum of Divisor. Caculate Sum of (a ^ 0 + a ^ 1 + ... a ^ b) then multiply them
        int SumPrime = (Pow(a, b + 1) - 1 + MOD) % MOD * Inv(a - 1) % MOD;
        Sum = (Sum * SumPrime) % MOD;
        // Third, Product of Divisor. Caculate Product of (a ^ 0 * a ^ 1 * a ^ b) then multiply them
        int Exp = Pow(a, (b * (b + 1) / 2));
        int Val_Product = ((Pow(Exp, Cnt)) % MOD) % MOD;
        Product = (Pow(Product, b + 1) * Val_Product) % MOD;
        Cnt = (Cnt * (b + 1)) % (MOD - 1);
    }
    cout << Num << ' ' << Sum << ' ' << Product;
}
int32_t main(){
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    IOS;
    int q = 1;
    if (MULTITEST) cin >> q;
    while (q--){enter();}
}
