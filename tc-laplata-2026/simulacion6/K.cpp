#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==================================\n"

struct info {
    ll sz, sum, mn, mx;
};

ostream &operator << (ostream &os, info& p) {
    auto [sz, sum, mn, mx] = p; 
    return os << "(" << sz << ", " << sum << ", " << mn << ", " << mx << ")"; 
}

int main() {
    FIN;

    int n, m; cin >> n >> m;
    vector<vi> g(n);
    forn(i,m) {
        int a, b; cin >> a >> b;
        --a, --b;
        g[a].pb(b);
        g[b].pb(a);
    }

    vector<info> comp; 
    vb visto(n);
    function<void(ll, ll)> dfs = [&](ll x, ll id) -> void {
        visto[x] = true;
        auto &[sz, sum, mn, mx] = comp[id];
        for (auto y: g[x]) if (visto[y] == false) {
            sz++, sum += y, mn = min(mn, y), mx = max(mx, y);
            dfs(y, id);
        }
    };

    vector<ii> sweep; 
    forn(x,n) if (visto[x] == false) {
        info state = {1, x, x, x}; 
        comp.pb(state);
        dfs(x, SZ(comp) - 1);
        auto [sz, sum, mn, mx] = comp.back();
        sweep.pb({mn, -1}); 
        sweep.pb({mx, 1}); 
    }
    // DBG(SZ(comp)); 
    // for (auto x : comp) cout << x << '\n';
    // RAYA; 

    // sweep line in the comps to check how many edges are needed
    sort(all(sweep)); 
    ll tot = 0, open = 0;
    for (auto [x, op] : sweep) {
        // cout << x << ' ' << op << '\n';
        if (op == -1) tot += open > 0, open++;
        else open--; 
    }
    cout << tot << '\n';

    return 0;
}