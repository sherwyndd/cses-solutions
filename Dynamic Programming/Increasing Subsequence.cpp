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
void enter(){
    int n;
    cin >> n;
    vector<int> b(n + 1, INF);
    int res = 0;
    b[0] = 0;
    for (int i = 1; i <= n; ++i){
        int x;
        cin >> x;
        int k = lower_bound(b.begin(), b.end(), x) - b.begin();
        res = max(res, k);
        b[k] = x;
    }
    cout << res;
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
