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
    long long t = 1ll * x.first * y.second - 1ll * x.second * y.first;
    if (t > 0) return 1;
    if (t < 0) return -1;
    if (t == 0) return 0;
}
int dot(pair<int, int> x, pair<int, int> y){
    long long t = 1ll * x.first * y.first + 1ll * x.second * y.second;
    if (t > 0) return 1;
    if (t < 0) return -1;
    if (t == 0) return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("main.inp", "r", stdin);
    //freopen("main.out", "w", stdout);
    int q;
    cin >> q;
    while (q--){
        for (int i = 1; i <= 4; ++i){
            cin >> p[i].first >> p[i].second;
        }
        // check if any pair of point both in the left or right of other line
        int x = cross(vec(p[1], p[2]), vec(p[1], p[3])); // first point
        int y = cross(vec(p[1], p[2]), vec(p[1], p[4])); // second point
        int x1 = cross(vec(p[3], p[4]), vec(p[3], p[1])); // first point
        int y1 = cross(vec(p[3], p[4]), vec(p[3], p[2])); // second point
        if (x * y > 0 || x1 * y1 > 0){
            cout << "NO" << '\n';
            continue;
        }
        // check for straight line and then check for order
        bool ok = true;
        if (cross(vec(p[1], p[2]), vec(p[1], p[3])) == 0){
            ok = false;
            if (dot(vec(p[1], p[3]), vec(p[2], p[3])) <= 0){
                cout << "YES" << '\n';
                continue;
            }
        }
        if (cross(vec(p[1], p[2]), vec(p[1], p[4])) == 0){
            ok = false;
            if (dot(vec(p[1], p[4]), vec(p[2], p[4])) <= 0){
                cout << "YES" << '\n';
                continue;
            }
        }
        if (cross(vec(p[3], p[4]), vec(p[3], p[1])) == 0){
            ok = false;
            if (dot(vec(p[3], p[1]), vec(p[4], p[1])) <= 0){
                cout << "YES" << '\n';
                continue;
            }
        }
        if (cross(vec(p[3], p[4]), vec(p[3], p[2])) == 0){
            ok = false;
            if (dot(vec(p[3], p[2]), vec(p[4], p[2])) <= 0){
                cout << "YES" << '\n';
                continue;
            }
        }
        if (!ok){
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
    }
}
