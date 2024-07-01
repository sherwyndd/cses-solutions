/*
    Patience is key
*/
#include <bits/stdc++.h>
using namespace std;
const int N = (10) + 7;
const int MOD = (1e9) + 7;
pair<int, int> p[N];
pair<int, int> vec(pair<int, int> x, pair<int, int> y){
    return {y.first - x.first, y.second - x.second};
}
int cross(pair<int, int> x, pair<int, int> y){
    long long t = 1ll * x.first * y.second - 1ll * y.first * x.second;
    if (t > 0) return 1;
    if (t < 0) return -1;
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("main.inp", "r", stdin);
    //freopen("main.out", "w", stdout);
    int q;
    cin >> q;
    while (q--){
        for (int i = 1; i <= 3; ++i){
            cin >> p[i].first >> p[i].second;
        }
        int x = cross(vec(p[1], p[2]), vec(p[1], p[3]));
        if (x > 0){
            cout << "LEFT";
        }
 
        else if (x < 0){
            cout << "RIGHT";
        }
        else{
            cout << "TOUCH";
        }
        cout << '\n';
    }
}
