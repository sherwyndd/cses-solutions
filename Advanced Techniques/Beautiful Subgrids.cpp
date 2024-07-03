/*
    Harder not smarter
*/
#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt")
#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define F first
#define S second
#define nl "\n"
typedef pair<int,int> p;
const int N = (1e6) + 7;
const int N2 = (1e3) + 7;
const int INF = (1e18);
const int base = 311;
const int MOD = (1e9) + 7;
const int MULTITEST = 0;
void enter(){
    int n;
    cin >> n;
    vector<bitset<3000>> v(n);
    for (auto &i : v){
        cin >> i;
    }
    int Res = 0;
    for (int i = 0; i < n; ++i){
        for (int j = i + 1; j < n; ++j){
            int cnt = (v[i] & v[j]).count();
            Res += cnt * (cnt - 1) / 2;
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
