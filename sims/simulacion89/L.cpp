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

struct op {
    ll t, u, v; 
};

struct DSU {
    vi link, sz;
    DSU(int tam) {
        link.resize(tam), sz.resize(tam);
        forn(i,tam) link[i] = i, sz[i] = 1; 
    }
    ll find(ll x) {return link[x] = (link[x] == x ? x : find(link[x])); }
    bool same(ll a, ll b) { return find(a) == find(b); }
    void join(ll a, ll b) {
        a = find(a), b = find(b);
        if (a == b) return; 
        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b]; 
        link[b] = a;
    }
};

int main() {
    FIN;
    
    int n, q; cin >> n >> q; 
    vector<op> a(q);
    forn(i,q) cin >> a[i].t >> a[i].u >> a[i].v, a[i].u--, a[i].v--;

    vi x(q), y(q), z(q);
    DSU ds(n);
    forn(i,q) {
        if (i - 1 >= 0) z[i] += z[i - 1]; 
        auto [t, u, v] = a[i];
        if (!ds.same(u, v)) z[i]++; 
        ds.join(u, v); 
    }
    DSU dsx(n), dsy(n); 
    forn(i,q) {
        if (i - 1 >= 0) x[i] += x[i - 1], y[i] += y[i - 1]; 
        auto [t, u, v] = a[i];
        if (t == 1) {
            if (!dsx.same(u, v)) x[i]++;
            dsx.join(u, v);
        } else {
            if (!dsy.same(u, v)) y[i]++;
            dsy.join(u, v);
        }
    }
    // for (auto o : z) cout << o << ' '; 
    // cout << '\n';
    // for (auto o : x) cout << o << ' '; 
    // cout << '\n';
    // for (auto o : y) cout << o << ' '; 
    // cout << '\n';
    vi A(2);
    forn(i,q){
        A[a[i].t-1]++;
        cout << 2*min((A[0]+A[1]-z[i])/2,min(A[0]+y[i]-z[i],A[1]+x[i]-z[i])) << "\n";
    }
    return 0; 
}