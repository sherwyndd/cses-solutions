/*
    Patience is key
*/
#include <bits/stdc++.h>
using namespace std;
const int N = (1e3) + 7;
const int MOD = (1e9) + 7;
const int maxvalue = (1e9);
int n;
pair<int, int> p[N];
int cross(pair<int, int> x, pair<int, int> y){
    long long t = 1ll * x.first * y.second - 1ll * x.second * y.first;
    if (t < 0) return -1;
    if (t > 0) return 1;
    return 0;
}
pair<int, int> vec(pair<int, int> x, pair<int, int> y){
    return {y.first - x.first, y.second - x.second};
}
int dot(pair<int, int> x, pair<int, int> y){
    long long t = 1ll * x.first * y.first + 1ll * x.second * y.second;
    if (t < 0) return -1;
    if (t > 0) return 1;
    return 0;
}
bool intersect(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3, pair<int, int> p4){
    int x = cross(vec(p1, p2), vec(p1, p3)); // first point
    int y = cross(vec(p1, p2), vec(p1, p4)); // second point
    int x1 = cross(vec(p3, p4), vec(p3, p1)); // first point
    int y1 = cross(vec(p3, p4), vec(p3, p2)); // second point
    if (x * y > 0 || x1 * y1 > 0){
        return false;
    }
    // check for straight line and then check for order
    bool ok = true;
    if (cross(vec(p1, p2), vec(p1, p3)) == 0){
        ok = false;
        if (dot(vec(p1, p3), vec(p2, p3)) <= 0){
            return true;
        }
    }
    if (cross(vec(p1, p2), vec(p1, p4)) == 0){
        ok = false;
        if (dot(vec(p1, p4), vec(p2, p4)) <= 0){
            return true;
        }
    }
    if (cross(vec(p3, p4), vec(p3, p1)) == 0){
        ok = false;
        if (dot(vec(p3, p1), vec(p4, p1)) <= 0){
            return true;
        }
    }
    if (cross(vec(p3, p4), vec(p3, p2)) == 0){
        ok = false;
        if (dot(vec(p3, p2), vec(p4, p2)) <= 0){
            return true;
        }
    }
    if (!ok){
        return false;
    }
    return true;
}
int position(pair<int, int> x){
    // check boundary
    for (int i = 1; i <= n; ++i) if (x == p[i]) return 0;
    for (int i = 1; i <= n; ++i){
        if (cross(vec(p[i], x), vec(p[i], p[i + 1])) == 0){
            if (dot(vec(x, p[i]), vec(x, p[i + 1])) <= 0) return 0;
        }
    }
    // check inside or outside
    pair<int, int> startpoint = {-maxvalue + 2, -maxvalue + 7};
    int cnt = 0;
    for (int i = 1; i <= n; ++i){
        if (intersect(startpoint, x, p[i], p[i + 1])) cnt++;
    }
    if (cnt % 2) return 1;
    return -1;
}
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("main.inp", "r", stdin);
    //freopen("main.out", "w", stdout);
    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        cin >> p[i].first >> p[i].second;
    }
    p[n + 1] = p[1];
    while (q--){
        pair<int, int> x;
        cin >> x.first >> x.second;
        int t = position(x);
        if (t == -1){
            cout << "OUTSIDE";
        }
        else if (t == 0){
            cout << "BOUNDARY";
        }
        else{
            cout << "INSIDE";
        }
        cout << '\n';
    }
}
