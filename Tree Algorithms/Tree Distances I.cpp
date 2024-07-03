/*
    Harder not smarter
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define nl "\n"
typedef pair<int,int> p;
const int N = (2e5) + 7;
const int N2 = (1e3) + 7;
const int INF = (1e18);
const int base = 311;
const int MOD = (1e9) + 7;
const int MULTITEST = 0;
int len[N], dp[N];
vector<int> E[N];
void dfs_pre(int u, int v){
    len[u] = 1;
    for (int i : E[u]) if (i != v){
        dfs_pre(i, u);
        len[u] = max(len[u], len[i] + 1);
    }
}
void dfs_cal_llpath(int i, int pa){
	vector<int> val;
	val.push_back(0);
	int cnt = 0;
	for(int u : E[i]) if(u != pa){
		val.push_back(len[u]);
		++cnt;
	}
	vector<int> lef(cnt + 10, 0);
	vector<int> rig(cnt + 10, 0);
	for(int i = 1; i <= cnt; ++i){
		lef[i] = max(lef[i - 1], val[i]);
	}
	for(int i = cnt; i >= 1; --i){
		rig[i] = max(rig[i + 1], val[i]);
	}
	int index = 0;
	for(int u : E[i]) if(u != pa){
		++index;
		dp[i] = max(max(lef[index - 1], rig[index + 1]), dp[pa] + 1);
		dfs_cal_llpath(u, i);
	}
	dp[i] = max(rig[1], dp[pa] + 1);
	return;
}
void enter(){
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i){
        int x, y;
        cin >> x >> y;
        E[x].push_back(y);
        E[y].push_back(x);
    }
    dfs_pre(1, 0);
    dp[0] = -1;
    dfs_cal_llpath(1, 0);
    for (int i = 1; i <= n; ++i){
        cout << dp[i] << ' ';
    }
}
int32_t main(){
    //freopen("CTREE.inp","r",stdin);
    //freopen("CTREE.out","w",stdout);
    IOS;
    int q = 1;
    if (MULTITEST) cin >> q;
    while (q--){enter();}
}
