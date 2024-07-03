/*
    Harder not smarter
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define nl "\n"
typedef pair<int,int> p;
const int N = (1e6) + 7;
const int N2 = (1e3) + 7;
const int INF = (1e18);
const int base = 311;
const int MOD = (1e9) + 7;
const int MULTITEST = 0;
vector<int> E[N];
int Sz[N];
void Dfs(int u, int v){
    Sz[u] = 1;
    for (int i : E[u]) if (i != v){
        Dfs(i, u);
        Sz[u] += Sz[i];
    }
}
int Centroid(int u, int v, int n){
    for (int i : E[u]) if (i != v){
        if (Sz[i] > n / 2){
            return Centroid(i, u, n);
        }
    }
    return u;
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
    Dfs(1, 0);
    cout << Centroid(1, 0, n);
}
int32_t main(){
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    IOS;
    int q = 1;
    if (MULTITEST) cin >> q;
    while (q--){enter();}
}
