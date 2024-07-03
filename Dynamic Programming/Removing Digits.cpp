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
const int N2=1008;
const int N3=108;
const int MOD=1000000007;
const int base=311;
const int dx4[4] = {-1, 1, 0, 0};
const int dy4[4] = {0, 0, -1, 1};
int n, dp[N];
vector<int> check(int x){
    vector<int> b;
    while (x>0){
        b.pb(x%10);
        x=x/10;
    }
    return b;
}
void init(){
    for (int i=0; i<=n; ++i){
        dp[i]=INF;
    }
}
void Enters(){
    cin>>n;
    init();
    dp[n]=0;
    n++;
    while (n--){
        for (int i : check(n)){
            dp[n-i]=min(dp[n-i],dp[n]+1);
        }
    }
    //cout<<dp[20]<<nl;
    cout<<dp[0]<<nl;
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
