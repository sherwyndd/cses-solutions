/*
    Nguyễn Hải Phong
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define F first
#define S second
#define nl "\n"
#define ve vector<int>
#define rt return
typedef pair<int,int>p;
bool MULTITEST = 0;
const int N=2000007;
const int INF = 2000000000000000000LL;
const int N2=1008;
const int N3=108;
const int MOD=1000000007;
const int base=311;
const int dx4[4] = {-1, 1, 0, 0};
const int dy4[4] = {0, 0, -1, 1};
int minimize(int x, int y){
    if (x==0) return y;
    return min(x,y);
}
int n, k, a[N], dp[N];
void Enters(){
    cin>>n>>k;
    for (int i=1; i<=n; ++i){
        cin>>a[i];
    }
    dp[0]=1;
    for (int i=0; i<=k; ++i) if (dp[i]){
        for (int j=1; j<=n; ++j){
            dp[i+a[j]]=(dp[i+a[j]]+dp[i])%MOD;
        }
    }
    cout<<dp[k];
}
void Solve(){
}
signed main(){
    IOS;
    int q=1;;
    if (MULTITEST) cin>>q;
    while (q--){ Enters(); Solve();}
}
 // Cầu xin ngài
/*
                       _oo0oo_
                      o8888888o
                      88" . "88
                      (| -_- |)
                      0\  =  /0
                    ___/`---'\___
                  .' \|     |// '.
                 / \|||  :  |||// \
                / _||||| -:- |||||- \
               |   | \  -  /// |   |
               | \_|  ''\---/''  |_/ |
               \  .-\__  '-'  ___/-. /
             ___'. .'  /--.--\  `. .'___
          ."" '<  `.___\_<|>_/___.' >' "".
         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
         \  \ `_.   \_ __\ /__ _/   .-` /  /
     =====`-.____`.___ \_____/___.-`___.-'=====
                       `=---='
     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
