/*
    Harder not smarter
*/
#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define F first
#define S second
#define nl "\n"
typedef pair<int,int> p;
const int N = (2e4) + 7;
const int N2 = (1e3) + 7;
const int INF = (1e9);
const int base = 311;
const int MOD = (1e9) + 7;
const int MULTITEST = 0;
int a[N];
void enter(){
    int n, k;
    cin >> n >> k;
    int Res = INF;
    for (int i = 1; i <= n; ++i){
        string s;
        cin >> s;
        int Up = 1;
        for (int j = s.size() - 1; j >= 0; --j){
            if (s[j] == '1') a[i] += Up;
            Up = Up * 2LL;
        }
        for (int j = 1; j <= i - 1; ++j){
            Res = min(Res, __builtin_popcount(a[i] ^ a[j]));
        }
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
