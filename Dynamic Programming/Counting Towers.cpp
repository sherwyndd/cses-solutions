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
const int MULTITEST = 1;
int Dp[N][3];
void enter(){
    int n;
    cin >> n;
    // Câu trả lời vì sao lại phải chia ra 2 trường hợp mà ko phải cứ từ hình trước rồi thêm vào các hình khả thi: Bởi vì một hình được thêm vào có thể thêm được nhiều lần tùy vào hình trước là gì
    Dp[1][0] = 1;
    Dp[1][1] = 1;
    for (int i = 2; i <= n; ++i){
        Dp[i][0] = (Dp[i - 1][0] * 2  + Dp[i - 1][1]) % MOD;
        Dp[i][1] = (Dp[i - 1][0] + Dp[i - 1][1] * 4) % MOD;
    }
    cout << (Dp[n][0] + Dp[n][1]) % MOD << nl;
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
