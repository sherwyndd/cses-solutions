/*
    Nguyễn Hải Phong
    nhphong
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
const int N=1000007;
const int INF = 2000000000000000000LL;
const int N2=2008;
const int N3=108;
const int MOD=1000000007;
const int base=311;
const int dx4[4] = {-1, 1, 0, 0};
const int dy4[4] = {0, 0, -1, 1};
int dp[N2][N2], n;
char a[N2][N2];
void Enters(){
    cin>>n;
    for (int i=1; i<=n; ++i){
        for (int j=1; j<=n; ++j){
            cin>>a[i][j];
        }
    }
    if (a[1][1]=='.') dp[1][1]=1;
    for (int i=1; i<=n; ++i){
        for (int j=1; j<=n; ++j) if (a[i][j]!='*'){
            if (a[i-1][j]=='.') dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;
            if (a[i][j-1]=='.') dp[i][j]=(dp[i][j]+dp[i][j-1])%MOD;
        }
    }
    cout<<dp[n][n];
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
