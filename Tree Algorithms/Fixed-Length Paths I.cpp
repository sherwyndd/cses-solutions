/*
    Harder not smarter
*/
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define nl "\n"
typedef pair<int,int> p;
const int N = (2e5) + 7;
const int N2 = (1e3) + 7;
const int INF = (1e9);
const int base = 311;
const int MOD = (1e9) + 7;
const int MULTITEST = 0;
int n, k, sz[N], cnt[N], maxdepth;
long long res;
bool process[N];
vector<int> E[N];
int get_tree_size(int u, int v){
    sz[u] = 1;
    for (int i : E[u]) if (i != v && !process[i]){
        sz[u] += get_tree_size(i, u);
    }
    return sz[u];
}
int get_centroid(int u, int v, int n){
    for (int i : E[u]) if (i != v && !process[i]){
        if (sz[i] >= n / 2){
            return get_centroid(i, u, n);
        }
    }
    return u;
}
void get_cnt(int u, bool keep, int depth, int v){
    if (depth > k) return;
    maxdepth = max(maxdepth, depth);
    if (keep == 0){
        res += cnt[k - depth] * 1LL;
    }
    else{
        cnt[depth]++;
    }
    for (int i : E[u]) if (!process[i] && i != v){
        get_cnt(i, keep, depth + 1, u);
    }
}
void dfs_cal(int u){
    u = get_centroid(u, 0, get_tree_size(u, 0));
    process[u] = true;
    cnt[0] = 1;
    maxdepth = 0;
    for (int i : E[u]) if (!process[i]){
        get_cnt(i, 0, 1, 0);
        get_cnt(i, 1, 1, 0);
    }
    fill(cnt + 1, cnt + maxdepth + 1, 0);
    for (int i : E[u]) if (!process[i]){
        dfs_cal(i);
    }
}
void enter(){
    cin >> n >> k;
    for (int i = 1; i < n; ++i){
        int x, y;
        cin >> x >> y;
        E[x].push_back(y);
        E[y].push_back(x);
    }
    dfs_cal(1);
    cout << res;
}
int32_t main(){
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    IOS;
    int q = 1;
    if (MULTITEST) cin >> q;
    while (q--){enter();}
}
