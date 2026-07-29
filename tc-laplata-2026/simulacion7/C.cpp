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
#define RAYA cerr << "=============================\n"

struct edge{
    int u, v, id, w;
    bool operator < (edge y) const {
        return w < y.w; 
    }
};


vi tsort(vector<vi>& g, int n) {
    vi r; priority_queue<ll> q;
    vi d(2*n);
    forn(i,n) for(ll j : g[i]) d[j]++;
    forn(i,n) if (!d[i]) q.push(-i);
    while (!q.empty()) {
        ll x = -q.top(); q.pop(); r.pb(x);
        for(ll j : g[x]) {
            d[j]--;
            if (!d[j]) q.push(-j);
        }
    }
    return r;
}

int main() {
    FIN;
    int n, m; cin >> n >> m;
    vector <edge> e(m);
    forn(i,m){
        cin >> e[i].u >> e[i].v >> e[i].w; e[i].u--; e[i].v--;
        e[i].id=i;
    }
    sort(all(e)); reverse(all(e));
    int l=0, r=m+1;
    vi ans;
    while(r-l>1){
        int med=(r+l)/2;
        vector <vi> g(n);
        forn(i,med) g[e[i].u].pb(e[i].v);
        vi t=tsort(g,n), id(n);
        if(SZ(t)<n) {r=med; continue;}
        l=med; ans.clear();
        forn(i,n) id[t[i]]=i;
        forn(i,m) if(id[e[i].u] > id[e[i].v]) ans.pb(e[i].id);
    }
    if(l==m) cout << "0 ";
    else cout << e[l].w << " ";
    cout << SZ(ans) << "\n";
    for(auto u : ans) cout << u+1 << " ";
    cout << "\n";
    return 0;
}