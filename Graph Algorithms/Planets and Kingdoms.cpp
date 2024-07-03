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
const int N2 = 3000;
const int INF = 1'000'000'000'000'000;
const int base = 311;
const int MOD = 1'000'000'007;
const int MULTITEST = 0;
vector<int> E[N];
int Num[N], Low[N], Cmp[N], Time, Scc;
bool Del[N];
stack<int> St;
void Tarjan(int u){
    Num[u] = Low[u] = Time++;
    St.push(u);
    for (int i : E[u]){
        if (Del[i]) continue;
        if (!Num[i]){
            Tarjan(i);
            Low[u] = min(Low[u], Low[i]);
        }
        else{
            Low[u] = min(Low[u], Num[i]);
        }
    }
    if (Low[u] == Num[u]){
        int v;
        Scc++;
        do{
            v = St.top();
            St.pop();
            Cmp[v] = Scc;
            Del[v] = true;
        } while (v != u);
    }
}
void enter(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int x, y;
        cin >> x >> y;
        E[x].push_back(y);
    }
    for (int i = 1; i <= n; ++i) if (!Num[i]){
        Tarjan(i);
    }
    cout << Scc << nl;
    for (int i = 1; i <= n; ++i){
        cout << Cmp[i] << ' ';
    }
}
int32_t main(){
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    IOS;
    int q = 1;
    if (MULTITEST) cin >> q;
    while (q--){enter();}
}
