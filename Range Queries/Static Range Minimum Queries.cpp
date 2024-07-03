/*
    Harder not smarter
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define nl "\n"
typedef pair<int,int> p;
const int N = (2e5) + 7;
const int LOG = 20;
const int N2 = (1e3) + 7;
const int INF = (1e18);
const int base = 311;
const int MOD = (1e9) + 7;
const int MULTITEST = 0;
int a[N], Min[N][LOG];
int Get_Min(int l, int r){
    int k = __lg(r - l + 1);
    r = r - (1LL << (k)) + 1;
    return min(Min[l][k], Min[r][k]);
}
void enter(){
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        Min[i][0] = a[i];
    }
    int LOG = __lg(n);
    for (int i = 1; i <= LOG; ++i){
        for (int j = 1; j <= n - (1LL << (i - 1)); ++j){
            Min[j][i] = min(Min[j][i - 1], Min[j + (1LL << (i - 1))][i - 1]);
        }
    }
    while (q--){
        int l, r;
        cin >> l >> r;
        cout << Get_Min(l, r) << nl;
    }
}
int32_t main(){
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    IOS;
    int q = 1;
    if (MULTITEST) cin >> q;
    while (q--){enter();}
}
