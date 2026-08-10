#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds; 

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"


typedef long long tipo;
struct segtree {
    vector<tipo> t; int tam;
    tipo NEUT = 0;
    tipo op(tipo a, tipo b) { return a + b; }
    void build(int n) {
        tam = sizeof(int) * 8 - __builtin_clz(n); tam = 1<<tam; 
        t.resize(2 * tam, NEUT); forn(i,n) t[tam + i] = 0; 
        for (int i = tam - 1; i > 0; i--) t[i] = op(t[i<<1], t[i<<1|1]); 
    }
    void update(int p, tipo value) {
        for (t[p += tam] = value; p > 1; p >>= 1) t[p>>1] = op(t[p], t[p^1]); 
    }
    tipo query(int l, int r) {
        tipo res = NEUT; 
        for (l += tam, r += tam; l <= r; l >>= 1, r >>= 1) {
            if (l&1) res = op(res, t[l++]); 
            if (!(r&1)) res = op(res, t[r--]); 
        }
        return res; 
    }
};

struct querie{
    ll sid, qid, x, y, d;
    bool operator < (querie p) const { return d < p.d; }
};

bool solve(int ids) {
    int dx, dy, n, q; cin >> dx >> dy >> n >> q;
    if(dx==0 or dy==0 or q==0) return false;
    cout << "Case " << ids << ":\n";
    vector <pair<ll,ii>> ans(q);
    vii c(n);
    forn(i,n) cin >> c[i].ff >> c[i].ss;
    vi d(q); forn(i,q) cin >> d[i];
    indexed_set s[4];
    vii ox(n), oy(n);
    forn(i,n){ox[i]={c[i].ff,i}; oy[i]={c[i].ss,i};}
    sort(all(ox)); sort(all(oy));
    int xx[4]={-1,1,-1,1}, yy[4]={1,1,-1,-1}
    segtree s[4];
    forn(i,4) s[i].build(n);
    vector <querie> qr;
    forr(x,1,dx+1) forr(y,1,dy+1) forn(i,q) forn(j,4) qr.pb({j,i,x,y,d[i]+x*xx[j]+y*yy[j]});
    sort(all(qr));
    forn(i,q) cout << ans[i].ff << " " << "(" << -ans[i].ss.ss << "," << -ans[i].ss.ff << ")\n";
    return true; 
}

int main() {
    FIN;
    bool ans = true; 
    int i = 1; 
    while (ans) ans = solve(i++);
    return 0;
}