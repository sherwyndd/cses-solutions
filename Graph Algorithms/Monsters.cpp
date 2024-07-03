/*
    Nguyễn Hải Phong
    nhphong
    Nitơ
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define F first
#define S second
#define nl "\n"
//#define v vector<int>
typedef pair<int,int>p;
bool MULTITEST = 0;
const int N=1000000;
const int INF = 2000000000000000000LL;
const int N2=1008;
const int N3=108;
const int MOD=1000000007;
const int base=311;
const int dx4[4] = {-1, 1, 0, 0};
const int dy4[4] = {0, 0, -1, 1};
bool f[N2][N2], Kt[N];
int P[N2][N2], P2[N2][N2], m, n, u, v;
p trace[N2][N2];
char a[N2][N2];
vector <p> kq, c;
string s;
queue<p> q2;
void init(){
    for (int i=0; i<=N2; ++i){
        for (int j=0; j<=N2; ++j) f[i][j]=true;
    }
}
void init2(){
    for (int i=0; i<=N2; ++i){
        for (int j=0; j<=N2; ++j) P2[i][j]=0;
    }
}
vector<p> check(p x){
    vector<p> res;
    int i=x.F;
    int j=x.S;
    if (a[i-1][j]=='.') res.pb({i-1,j});
    if (a[i][j-1]=='.') res.pb({i,j-1});
    if (a[i+1][j]=='.') res.pb({i+1,j});
    if (a[i][j+1]=='.') res.pb({i,j+1});
    return res;
}
void bfs(int u, int v){
    queue<p> q;
    f[u][v]=false;
    q.push({u,v});
    while (!q.empty()){
        p i=q.front();
        //cout<<i.F<<' '<<i.S<<nl;
        q.pop();
         if (check(i).size()==0) continue;
        for (p j : check(i)){
            //cout<<j.F<<' '<<j.S<<nl;
            if (f[j.F][j.S]){
                q.push(j);
                f[j.F][j.S]=false;
                P[j.F][j.S]=P[i.F][i.S]+1LL;
                trace[j.F][j.S]={i.F,i.S};
            }
        }
        //cout<<' '<<nl;
    }
}
void quai(){
    f[u][v]=false;
    while (!q2.empty()){
        p i=q2.front();
        q2.pop();
        if (check(i).size()==0) continue;
        for (p j : check(i)){
            if (f[j.F][j.S]){
                q2.push(j);
                f[j.F][j.S]=false;
                P2[j.F][j.S]=P2[i.F][i.S]+1;
            }
        }
    }
}
void Enters(){
    for (int i=0; i<=N; ++i) Kt[i]=true;
    cin>>m>>n;
    for (int i=1; i<=m; ++i){
        for (int j=1; j<=n; ++j){
            cin>>a[i][j];
        }
    }
    for (int i=1; i<=m; ++i){
        for (int j=1; j<=n; ++j){
        if (a[i][j]=='A') {u=i; v=j;};
        if (a[i][j]=='M') {q2.push({i,j});}
        if (i==1 || j==1 || i==m || j==n){
            if (a[i][j]=='.'){
                c.pb({i,j});
            }
            if (a[i][j]=='A') {return void(cout<<"YES"<<nl<<0);}
        }
    }
    }
    init();
    bfs(u,v);
    memset(f,true,sizeof(f));
    quai();
    //cout<<P2[8][2]<<nl;
    int h;
    for (int j=0; j<c.size(); ++j){
        bool ok=true;
        int k=c[j].F;
        int l=c[j].S;
        if (P[k][l]>=P2[k][l] && P2[k][l]!=0){
            ok=false;
        }
        else if (P[k][l]==0){
            ok=false;
        }
        if (!ok) Kt[j]=false;
    }
    for (int i=0; i<c.size(); ++i){
        if (Kt[i]){
            //cout<<c[i].F<<' '<<c[i].S<<' '<<i<<nl;
            p start={u,v};
            p End={c[i].F,c[i].S};
            kq.pb(End);
            while (End!=start){
                End=trace[End.F][End.S];
                kq.pb(End);
            }
            break;
        }
    }
    if (kq.size()==0) {return void(cout<<"NO");}
    reverse(kq.begin(),kq.end());
    //kq.erase(kq.begin());
    cout<<"YES"<<nl;
    cout<<kq.size()-1<<nl;
    for (int i=1; i<kq.size(); ++i){
        int t=kq[i].F;
        int k=kq[i].S;
        int h=kq[(i-1)].F;
        int l=kq[(i-1)].S;
        if (t>h) s.pb('D');
        if (k>l) s.pb('R');
        if (k<l) s.pb('L');
        if (t<h) s.pb('U');
    }
    cout<<s;
}
void Solve(){
}
signed main(){
    IOS;
    int q=1;;
    if (MULTITEST) cin>>q;
    while (q--){ Enters(); Solve();}
}
