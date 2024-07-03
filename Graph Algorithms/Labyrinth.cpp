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
const int INF = 1'000'000'000;
const int base = 311;
const int MOD = 1'000'000'007;
const int MULTITEST = 0;
bool Vis[N2][N2];
int n, m, x, y, u, v, H[N2][N2];
p Trace[N2][N2];
void Bfs(int i, int j){
    queue<p> q;
    q.push({i, j});
    H[i][j] = 0LL;
    while (q.size()){
        p x = q.front();
        q.pop();
        int i = x.F;
        int j = x.S;
        if (Vis[i][j]) continue;
        Vis[i][j] = true;
        if (i - 1 > 0 && !Vis[i - 1][j]) {H[i - 1][j] = H[i][j] + 1; Trace[i - 1][j] = {i, j}; if (i - 1 == u && j == v) return; q.push({i - 1, j});};
        if (i + 1 <= n && !Vis[i + 1][j]) {H[i + 1][j] = H[i][j] + 1; Trace[i + 1][j] = {i, j}; if (i + 1 == u && j == v) return; q.push({i + 1, j});};
        if (j - 1 > 0 && !Vis[i][j - 1]) {H[i][j - 1] = H[i][j] + 1; Trace[i][j - 1] = {i, j}; if (i == u && j - 1 == v) return; q.push({i, j - 1});};
        if (j + 1 <= m && !Vis[i][j + 1]) {H[i][j + 1] = H[i][j] + 1; Trace[i][j + 1] = {i, j}; if (i == u && j + 1 == v) return; q.push({i, j + 1});};
 
    }
}
void enter(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            char c;
            cin >> c;
            if (c == '#') Vis[i][j] = true;
            if (c == 'A'){
                x = i;
                y = j;
            }
            if (c == 'B'){
                u = i;
                v = j;
            }
        }
    }
    Bfs(x, y);
    if (H[u][v] == 0){
        cout << "NO";
        return;
    }
    cout << "YES" << nl;
    cout << H[u][v] << nl;
    vector<char> vec;
    while (true){
        p x = Trace[u][v];
        if (x.F == 0){
            break;
        }
        int i = x.F - u;
        int j = x.S - v;
        u = x.F;
        v = x.S;
        if (i == 1){
            vec.pb('U');
        }
        if (i == -1){
            vec.pb('D');
        }
        if (j == 1){
            vec.pb('L');
        }
        if (j == -1){
            vec.pb('R');
        }
    }
    reverse(vec.begin(), vec.end());
    for (char i : vec){
        cout << i;
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
