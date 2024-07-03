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
int C[N2][N2];
int Ckn(int k, int n){
    if (k > n) return 0;
    return C[k][n];
}
void enter(){
    int n;
    cin >> n;
    int BIT = __lg(n);
    for (int i = 0; i <= BIT + 1; ++i){
        C[0][i] = 1;
        C[i][i] = 1;
    }
    for (int i = 1; i <= BIT + 1; ++i){
        for (int j = i; j <= BIT + 1; ++j){
            C[i][j] = C[i][j - 1] + C[i - 1][j - 1];
        }
    }
    int pre = 0;
    int Res = 0;
    for (int i = BIT; i >= 0; --i){
        if (n >> i & 1){
            for (int j = 0; j <= i; ++j){
                Res += (j + pre) * Ckn(j, i);
            }
            pre++;
        }
        //cout << Res << nl;
    }
    cout << Res + pre;
}
int32_t main(){
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    IOS;
    int q = 1;
    if (MULTITEST) cin >> q;
    while (q--){enter();}
}
