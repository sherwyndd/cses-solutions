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
const int N = 1'000'007;
const int N2 = 3000;
const int INF = 1'000'000'000'000'000'000;
const int base = 311;
const int MOD = 1'000'000'007;
const int MULTITEST = 0;
int Map[N];
void enter(){
    int n;
    cin >> n;
    int m = 0;
    for (int i = 1; i <= n; ++i){
        int x;
        cin >> x;
        Map[x] += 1;
        m = max(m, x);
    }
    for (int i = m; i >= 1; --i){
        int Cnt = 0;
        for (int j = 1; j <= m / i; ++j){
            Cnt += Map[i * j];
            if (Cnt >= 2){
                cout << i;
                return;
            }
        }
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
