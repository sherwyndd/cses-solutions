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
const int N = 2'000'007;
const int N2 = 3'000;
const int INF = 1'000'000'000;
const int base = 311;
const int MOD = 1'000'000'007;
const int MULTITEST = 0;
int a[N];
p Best[N];
void enter(){
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    int Bitmx = (1LL << n);
    Best[0].F = 1LL;
    Best[0].S = 0;
    for (int i = 1; i < Bitmx; ++i){
        Best[i] = {INF, 0};
        for (int j = 0; j < n; ++j) if (i >> j & 1LL){
            p option = Best[i ^ (1LL << j)];
            if (option.S + a[j + 1] <= x){
                option.S += a[j + 1];
            }
            else{
                option.F++;
                option.S = a[j + 1];
            }
            Best[i] = min(Best[i], option);
        }
    }
    cout << Best[Bitmx - 1].F;
}
void solve(){
}
signed main(){
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    //IOS;
    int q = 1;
    if (MULTITEST) cin >> q;
    while (q--){enter(); solve();}
}
