/*
    Patience is key
*/
#include <bits/stdc++.h>
using namespace std;
const int N = (1e3) + 7;
const int MOD = (1e9) + 7;
pair<int, int> p[N];
long long cross(pair<int, int> x, pair<int, int> y){
    return 1ll * x.first * y.second - 1ll * x.second * y.first;
}
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("main.inp", "r", stdin);
    //freopen("main.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> p[i].first >> p[i].second;
    }
    p[n + 1] = p[1];
    long long res = 0;
    for (int i = 1; i <= n; ++i){
        res += cross(p[i], p[i + 1]);
    }
    res = abs(res);
    cout << res;
}
