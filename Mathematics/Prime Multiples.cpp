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
int a[N];
void enter(){
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; ++i){
        cin >> a[i];
    }
    int BIT = (1LL << k);
    int Ans = 0;
    for (int i = 0; i < BIT; ++i){
        int Cnt = 0;
        int Prime = 1;
        bool Ok = true;
        for (int j = 0; j < k; ++j) if (i >> j & 1){
            Cnt += 1;
            if (Prime > n / a[j + 1]) {Ok = false; break;}
            Prime = Prime * a[j + 1];
        }
        if (!Ok) continue;
        if (Cnt > 0){
            if (Cnt % 2 == 1) Ans = Ans + n / Prime; else Ans = Ans - n / Prime;
        }
    }
    cout << Ans;
}
int32_t main(){
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    IOS;
    int q = 1;
    if (MULTITEST) cin >> q;
    while (q--){enter();}
}
