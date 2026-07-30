#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
using vi = vector<ll>;
using vb = vector<bool>;
using ii = pair<ll,ll>;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "================================\n"
const int MAXN=1005;
vector <vector<ii>> g(MAXN);
set <int> s;
vb visto(MAXN,false);
void dfs(int v){
    visto[v]=true;
    for(auto [u,i] : g[v]) if(!visto[u]){
        s.insert(i); dfs(u);
    }
}

int main() {
    FIN;
    int n; cin >> n;
    vi v(n-1), u(n-1);
    forn(i,n-1){
        cin >> u[i] >> v[i]; u[i]--; v[i]--;
        g[u[i]].pb({v[i],i}); g[v[i]].pb({u[i],i});
    }
    vi r, x;
    forn(i,n) if(!visto[i]){
        r.pb(i); dfs(i);
    }
    forn(i,n-1) if(s.find(i)==s.end()) x.pb(i);
    cout << SZ(r)-1 << "\n";
    forn(i,SZ(r)-1){
        cout << u[x[i]]+1 << " " << v[x[i]]+1 << " " << r[0]+1 << " " << r[i+1]+1 << "\n";
    }
    return 0;
}