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
const int N = 2'00'007;
const int N2 = 3000;
const int INF = 1'000'000'000'000'000'000;
const int base = 311;
const int MOD = 1'000'000'007;
const int MULTITEST = 0;
const int LOG = 30;
int Up[N][LOG + 2];
int Kth(int x, int k){
    for (int i = 0; (1LL << i) <= k; ++i){
        if (k >> i & 1){
            x = Up[x][i];
        }
    }
    return x;
}
void enter(){
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        cin >> Up[i][0];
    }
    for (int i = 1; i < LOG; ++i){
        for (int j = 1; j <= n; ++j){
            Up[j][i] = Up[Up[j][i - 1]][i - 1];
        }
    }
    while (q--){
        int x, k;
        cin >> x >> k;
        cout << Kth(x, k) << nl;
    }
}
signed main(){
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    IOS;
    int q = 1;
    if (MULTITEST) cin >> q;
    while (q--){enter();}
}
