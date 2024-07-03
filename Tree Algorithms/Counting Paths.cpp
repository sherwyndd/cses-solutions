/*
    Harder not smarter
*/
#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define F first
#define S second
#define nl "\n"
typedef pair<int,int> p;
const int N = 2'00'001;
const int N2 = 3'000;
const int INF = 1'000'000'000'000'000'000;
const int base = 311;
const int MOD = 1'000'000'007;
const int MULTITEST = 0;
int Sz[N], Vt[N], Group[N], Head[N], m, Chain, Par[N], H[N], Up[N][22], Dp[N];
vector<int> E[N];
void DfsPre(int u, int v, int t){
    Par[u] = v;
    H[u] = t;
    Up[u][0] = v;
    for (int i = 1; i <= 20; ++i){
        Up[u][i] = Up[Up[u][i - 1]][i - 1];
    }
    for (int i : E[u]) if (i != v){
        DfsPre(i, u, t + 1);
        Sz[u] += Sz[i];
    }
}
int Kth(int u, int k){
    for (int i = 0; (1 << i) <= k; ++i){
        if (k >> i & 1) u = Up[u][i];
    }
    return u;
}
int Lca(int u, int v){
    if (u != v){
        if (H[u] < H[v]) swap(u, v);
        //cout << H[u] << ' ' << H[v] << nl;
        if (H[u] != H[v]){
            //cout << u << ' ' << v << nl;
            u = Kth(u, H[u] - H[v]);
        }
    }
    //cout << u << ' ' << v << nl;
    if (u == v){
        return u;
    }
    int k = __lg(H[u]);
    for (int i = k; i >= 0; --i){
        if (Up[u][i] != Up[v][i]){
            u = Up[u][i];
            v = Up[v][i];
        }
    }
    return Up[u][0];
}
void Hld(int u, int v){
    if (!Head[Chain]) Head[Chain] = u; // Đỉnh đầu của chain
    Vt[u] = ++m; // Vị trí của đỉnh u
    Group[u] = Chain; // Chuỗi mà chứa đỉnh u
    int Mx = 0; // Biến để so sánh Sz các cây con
    int vt = -1; // Cây con được chọn để đi tiếp (lớn nhất)
    for (int i : E[u]) if (i != v){
        if (Sz[i] > Mx){
            Mx = Sz[i];
            vt = i;
        }
    }
    if (vt != - 1){
        Hld(vt, u);
    }
    for (int i : E[u]) if (i != v){
        if (i != vt){
            ++Chain;
            Hld(i, u);
        }
    }
}
void Add(int l, int r, int val){
    Dp[l] += val;
    Dp[r + 1] -= val;
}
void Update(int u, int a){
    int U = Group[u];
    int A = Group[a];
    while (1){
        if (U == A){
            Add(Vt[a], Vt[u], 1);
            return;
        }
        Add(Vt[Head[U]], Vt[u], 1);
        u = Par[Head[U]];
        U = Group[u];
    }
}
void enter(){
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        Sz[i] = 1;
    }
    for (int i = 1; i < n; ++i){
        int x, y;
        cin >> x >> y;
        E[x].pb(y);
        E[y].pb(x);
    }
    DfsPre(1, 0, 0); // Tính trước Sz của từng cây con
    Hld(1, 0);
    while (q--){
        int x, y;
        cin >> x >> y;
        int a = Lca(x, y);
        Update(x, a);
        Update(y, a);
        Add(Vt[a], Vt[a], -1);
    }
    for (int i = 1; i <= m; ++i){
        Dp[i] = Dp[i - 1] + Dp[i];
    }
    for (int i = 1; i <= n; ++i){
        cout << Dp[Vt[i]] << ' ';
    }
 
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
