#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define SZ(x) (x).size()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "========================\n"

struct compresion {
    vector<int> todos; 
    compresion(vector<int> v) {
        todos = v; sort(all(todos)); 
        todos.erase(unique(all(todos)), todos.end()); 
    }
    int obtener(int x) { return (int)(lower_bound(all(todos), x) - todos.begin()); }
};

typedef ll tipo;
struct segtree {
    vector<tipo> t; int tam; 
    tipo NEUT = 0;
    tipo op(tipo a, tipo b) { return a + b; }
    void build(int n) {
        tam = sizeof(int) * 8 - __builtin_clz(n); tam = 1<<tam;
        t.resize(2*tam, NEUT); forn(i,n) t[tam + i] = 0;
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


int main() {
    FIN;
    int n; cin >> n;
    vi x1(n), y1(n), x2(n), y2(n);
    vector <int> t;
    forn(i,n){
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        t.pb(y1[i]); t.pb(y2[i]);
    }
    compresion c(t);
    forn(i,n){y1[i]=c.obtener(y1[i]); y2[i]=c.obtener(y2[i]);}
    segtree s;
    s.build(2*n);
    vii q(2*n);
    forn(i,n){
        q[2*i]={x1[i],i};
        q[2*i+1]={x2[i],i};
    }
    sort(all(q));
    for(auto [x,i]: q){
        if(x==x1[i]){
            if(s.query(y1[i],y2[i])>0){cout << "1\n"; return 0;}
            s.update(y1[i],1);
            s.update(y2[i],1);
        }
        else{
            s.update(y1[i],0);
            s.update(y2[i],0);
            if(s.query(y1[i],y2[i])>0){cout << "1\n"; return 0;}
        }
    }
    cout << "0\n";
    return 0; 
}
