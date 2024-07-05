/*
    Patience is key
*/
#include <bits/stdc++.h>
using namespace std;
using namespace std;
const int N = (1e4) + 7;
long long ways[N];
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("main.inp", "r", stdin);
    //freopen("main.out", "w", stdout);
    int n; cin >> n;
    // define ways[i] is the way to put 2 knight in k * k chessboard and so that they attack each other
    for (int i = 3; i <= n; ++i){
        ways[i] = ways[i - 1];
        // plus for all pair with cell type (i, j) with (j = 1 -> i)
        ways[i] += 4 + (i - 2) * 2;
        if (i > 3) ways[i] += 2 + (i - 4) * 2;
        // plus for all pair with cell type (j, i) with (j = 1 -> i)
        ways[i] += 4 + (i - 2) * 2;
        if (i > 3) ways[i] += 2 + (i - 4) * 2;
        ways[i] -= 4;
    }
    for (int i = 1; i <= n; ++i){
        long long totalways = 1ll * i * i * (i * i - 1) / 2;
        cout <<  totalways - 1ll * ways[i] << '\n';
    }
}
