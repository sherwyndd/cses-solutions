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
const int INF = (1e18);
const int base = 311;
const int MOD = (1e9) + 7;
const int MULTITEST = 0;
int sz[N], color[N], ans[N], st[N], ft[N], TimeDfs, node[N], cnt[N], res;
vector<int> E[N];
void dfs_pre(int u, int v){
    sz[u] = 1;
    st[u] = ++TimeDfs;
    node[TimeDfs] = u;
    for (int i : E[u]) if (i != v){
        dfs_pre(i, u);
        sz[u] += sz[i];
    }
    ft[u] = TimeDfs;
}
void add(int color, int x){
    if (cnt[color] == 0 && x == 1) res++;
    if (cnt[color] == 1 && x == -1) res--;
    cnt[color] += x;
}
void dfs_cal(int u, int v, bool keep){
    int mx = 0;
    int big = -1;
    for (int i : E[u]) if (i != v){
        if (sz[i] > mx){
            mx = sz[i];
            big = i;
        }
    }
    for (int i : E[u]) if (i != v && i != big){
        dfs_cal(i, u, 0);
    }
    if (big != -1){
        dfs_cal(big, u, 1);
    }
    for (int i : E[u]) if (i != v && i != big){
        for (int j = st[i]; j <= ft[i]; ++j){
            add(color[node[j]], 1);
        }
    }
    add(color[u], 1);
    ans[u] = res;
    if (keep == 0){
        for (int i = st[u]; i <= ft[u]; ++i){
            add(color[node[i]], -1);
        }
    }
}
void enter(){
    int n;
    cin >> n;
    vector<int> roirac;
    map<int, int> mp;
    for (int i = 1; i <= n; ++i){
        cin >> color[i];
        roirac.push_back(color[i]);
    }
    sort(roirac.begin(), roirac.end());
    roirac.erase(unique(roirac.begin(), roirac.end()), roirac.end());
    for (int i = 0; i < roirac.size(); ++i){
        mp[roirac[i]] = i + 1;
    }
    for (int i = 1; i <= n; ++i){
        color[i] = mp[color[i]];
    }
    for (int i = 1; i < n; ++i){
        int x, y;
        cin >> x >> y;
        E[x].push_back(y);
        E[y].push_back(x);
    }
    dfs_pre(1, 0);
    dfs_cal(1, 0, 1);
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
}
int32_t main(){
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    IOS;
    int q = 1;
    if (MULTITEST) cin >> q;
    while (q--){enter();}
}
