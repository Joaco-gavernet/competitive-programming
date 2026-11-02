#include <bits/stdc++.h>
using namespace std;

using ll = long long; 
using vi = vector<ll>;
using vb = vector<bool>;
using ii = pair<ll,ll>;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=========================\n"

ll dx[3]={0,0,1}, dy[3]={1,-1,0};

ll dfs(ll x, ll y, vector <vb> &visto, vector <vb> &v){
    ll n=SZ(visto), m=SZ(visto[0]);
    ll ans=x;
    visto[x][y]=true;
    forn(i,3){
        ll _x=x+dx[i], _y=y+dy[i];
        if(_x>=n or _y<0 or _y>=m or !v[_x][_y] or visto[_x][_y]) continue;
        ans=max(ans,dfs(_x,_y,visto,v));
    }
    return ans;
}

void solve() {
    ll n, m, k; cin >> n >> m >> k;
    vector <string> s(n);
    forn(i,n) cin >> s[i];
    vector <vb> v(n,vb(m,true)), visto(n,vb(m,false));
    forn(j,m){
        ll t=n+k;
        for(int i=n-1; i>=0; i--){
            if(s[i][j]=='x') t=i;
            if(t<i+k or i+k>n) v[i][j]=false;
        }
    }
    cout << dfs(0,0,visto,v)+k << "\n";
}

int main() {
    FIN;
    int t; cin >> t;
    while (t--) solve();
    return 0; 
}