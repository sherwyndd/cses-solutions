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
const int MULTITEST = 0;
struct Node{
    int l;
    int r;
    int p;
} a[N];
struct Segment{
    vector<int> St;
    int n;
    void init(int sz){
        n = sz;
        St.assign(n * 4 + 7, 0);
    }
    void Update(int id, int l, int r, int i, int val){
        if (i > r || i < l) return;
        if (l == r){
            St[id] = max(St[id], val);
            return;
        }
        int mid = l + r >> 1;
        Update(id * 2, l, mid, i, val);
        Update(id * 2 + 1, mid + 1, r, i, val);
        St[id] = max(St[id * 2], St[id * 2 + 1]);
    }
    void Update(int i, int val){
        Update(1, 1, n, i, val);
    }
    int Get(int id, int l, int r, int u, int v){
        if (l > v || r < u) return 0LL;
        if (u <= l && r <= v) return St[id];
        int mid = l + r >> 1;
        return max(Get(id * 2, l, mid, u, v), Get(id * 2 + 1, mid + 1, r, u, v));
    }
    int Get(int l, int r){
        if (l > r) return 0LL;
        return Get(1, 1, n, l, r);
    }
} Seg;
bool cmp(Node x, Node y){
    return x.r < y.r;
}
vector<int> vec;
void enter(){
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].l >> a[i].r >> a[i].p;
        vec.pb(a[i].l);
        vec.pb(a[i].r);
    }
    sort(vec.begin(),vec.end());
    vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())));
    for (int i = 0; i < vec.size(); ++i){
        m[vec[i]] = i + 1;
    }
    Seg.init(vec.size());
    sort(a + 1, a + n + 1, cmp);
    int res = 0;
    for (int i = 1; i <= n; ++i){
        int x = Seg.Get(1, m[a[i].l] - 1) + a[i].p;
        res = max(res, x);
        Seg.Update(m[a[i].r], x);
    }
    cout << res;
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
