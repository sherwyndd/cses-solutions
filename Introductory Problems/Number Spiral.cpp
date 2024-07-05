/*
    Patience is key
*/
#include <bits/stdc++.h>
using namespace std;
const int N = (1e5) + 7;
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("main.inp", "r", stdin);
    //freopen("main.out", "w", stdout);
    int q; cin >> q;
    while (q--){
        long long x, y; cin >> x >> y;
        if (y > x){
            long long mid = (y - 1) * (y - 1) + y;
            if (y % 2) cout << mid + (y - x); else cout << mid - (y - x);
 
        }
        else{
            long long mid = (x - 1) * (x - 1) + x;
            if (x % 2) cout << mid - (x - y); else cout << mid + (x - y);
        }
        cout << '\n';
    }
}
