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
#define DBG(x) cerr << #x <<  " = " << x << endl
#define RAYA cerr << "==================\n"
#define DBGV(v) cerr << #v << " = "; for (auto _: v) cout << _ << ' '; cout << '\n'

void cota(vector<vi>& g, vi& p, vi& l) {
    const int n = SZ(g);
    priority_queue<ll> pq; 
    vi in(n); 
    forn(x,n) for (auto y : g[x]) in[y]++;
    forn(x,n) if (in[x] == 0) pq.push(x);

    while (SZ(pq)) {
        auto x = pq.top(); pq.pop(); 
        if (p[x] > 0) l[x] = max(l[x], p[x]); 
        for (auto y : g[x]) {
            l[y] = max(l[y], l[x] + 1); 
            if (--in[y] == 0) pq.push(y); 
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;
    vi p(n); 
    vb visto(n + 1);
    forn(i,n) cin >> p[i], visto[p[i]] = true; 

    vector<vi> g(n), gr(n);
    forn(i,m) {
        int u, v; cin >> u >> v;
        u--, v--; 
        g[u].pb(v);
        gr[v].pb(u);
    }

    vi l(n), r(n); 
    cota(g, p, l);

    forn(i,n) if (p[i] > 0) p[i] = n + 1 - p[i]; 
    cota(gr, p, r); 
    forn(i,n) r[i] = n + 1 - r[i]; 
    forn(i,n) if (p[i] > 0) p[i] = n + 1 - p[i]; 

    set<ll> rems; 
    forn(i,n) if (visto[i + 1] == false) rems.insert(i + 1);

    // sweep line 
    vector<ii> sw; 
    forn(i,n) {
        if (p[i] == 0) sw.pb({r[i], i});
        else if (p[i] < l[i] or r[i] < p[i]) {
            cout << "-1\n";
            return; 
        }
    }
    assert(SZ(sw) == SZ(rems)); 

    sort(all(sw)); 
    for (auto [x, id] : sw) {
        auto it = rems.lower_bound(l[id]); 
        // cout << x << ' ' << id << ' ' << bool(it == rems.end()) << '\n';
        if (it == rems.end() or r[id] < *it) {
            cout << "-1\n";
            return; 
        } else {
            p[id] = *it;
            rems.erase(it);
        }
    }
    assert(SZ(rems) == 0); 
    for (auto x : p) cout << x << ' ';
    cout << '\n'; 
}

int main() {
    FIN;
    int t; cin >> t;
    while (t--) solve();
    return 0;
}