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
const int N = 1'00'007;
const int N2 = 3'000;
const int INF = 1'000'000'000;
const int base = 311;
const int MOD = 1'000'000'007;
const int MULTITEST = 0;
vector<int> num;
int Dp[20][10][3][3];
int Cal(int pos, int last, int state, int zero){
    if (pos == num.size()){
        return 1LL;
    }
    if (last != -1 ) if (Dp[pos][last][state][zero] != -1) return Dp[pos][last][state][zero];
    int LMT;
    if (state == 0){
        LMT = num[pos];
    }
    else{
        LMT = 9;
    }
    int res = 0;
    for (int i = 0; i <= LMT; ++i){
        if (i == last && i != 0) continue;
        if (i == last && i == 0 && zero == 1) continue;
        int nstate = state;
        int nzero = zero;
        if (i < LMT){
            nstate = 1;
        }
        if (i != 0){
            nzero = 1;
        }
        res += Cal(pos + 1, i, nstate, nzero);
    }
    if (last == -1) return res;
    return Dp[pos][last][state][zero] = res;
}
int Solve(int x){
    memset(Dp, -1, sizeof(Dp));
    num.clear();
    while (x > 0){
        num.pb(x % 10);
        x /= 10;
    }
    reverse(num.begin(), num.end());
    return Cal(0, -1, 0, 0);
}
void enter(){
    int l, r;
    cin >> l >> r;
    if (l == 0){
        cout << Solve(r);
        return;
    }
    cout << Solve(r) - Solve(l - 1);
}
signed main(){
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    IOS;
    int q = 1;
    if (MULTITEST) cin >> q;
    while (q--){enter();}
}
