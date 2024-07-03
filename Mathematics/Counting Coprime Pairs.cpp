/*
    Patience is key
*/
#include <bits/stdc++.h>
using namespace std;
const int N = (1e6) + 7;
const int MOD = (1e9) + 7;
int mp[N];
long long divisible[N];
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int m = 0;
    for (int i = 1; i <= n; ++i){
        int x; cin >> x; m = max(m, x);
        mp[x]++;
    }
    for (int i = m; i >= 1; --i){
        for (int j = 1; j <= m / i; ++j){
            divisible[i] += mp[i * j] * 1LL;
        }
        divisible[i] = divisible[i] * (divisible[i] - 1) / 2LL; // Dem so cap
        for (int j = 2; j <= m / i; ++j){
            divisible[i] = (divisible[i] - divisible[i * j]);
        }
    }
    cout << divisible[1];
}
