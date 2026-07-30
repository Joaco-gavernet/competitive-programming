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


typedef long long tipo; 
const int NEUT = 0;
struct node {
    tipo ans, l, r, lazy = 0;
    bool upd = false;
    node() { ans = lazy = 0; upd = false; l = r = -1; }
    node(tipo val, int pos): ans(val), l(pos), r(pos) {}
    void set_lazy(tipo x) { lazy = max(x,ans); upd = true; }
};

struct segtree_lazy {
    #define l(x) int(x<<1)
    #define r(x) int(x<<1|1)
    vector<node> t; int tam; 
    node op(node a, node b) {
        node aux; 
        aux.ans = max(a.ans, b.ans); 
        aux.l = a.l;
        aux.r = b.r;
        return aux; 
    }
    void node_update(node &cur) {
        cur.ans += cur.lazy * (cur.r - cur.l + 1); 
    }
    void reset_lazy(node& cur) {
        cur.lazy = 0; cur.upd = false;
    }
    void push(int p) {
        node& cur = t[p]; 
        if (cur.upd) {
            node_update(cur);
            if (cur.l < cur.r) {
                t[l(p)].set_lazy(cur.lazy);
                t[r(p)].set_lazy(cur.lazy); 
            }
        }
        reset_lazy(cur); 
    }
    node query(int l, int r, int p = 1) {
        push(p); node& cur = t[p]; 
        if (l > cur.r or r < cur.l) return node();
        if (l <= cur.l and cur.r <= r) return cur;
        return op(query(l, r, l(p)), query(l, r, r(p)));
    }
    void update(int l, int r, tipo val, int p = 1) {
        push(p); node& cur = t[p]; 
        if (l > cur.r or r < cur.l) return;
        if (l <= cur.l and cur.r <= r) {
            cur.set_lazy(val); push(p); return;
        }
        update(l, r, val, l(p)), update(l, r, val, l(p)); 
        cur = op(t[l(p)], t[r(p)]); 
    }
    void build(vector<tipo> v, int n) {
        tam = sizeof(int) * 8 - __builtin_clz(n); tam = 1 << tam; 
        t.resize(2 * tam); v.resize(tam); 
        forn(i,tam) t[tam+i] = node(v[i], i);
        for (int i = tam - 1; i > 0; i--) t[i] = op(t[l(i)], t[r(i)]); 
    }
};

struct compresion {
    vector<int> todos;
    compresion(vector<int> v) {
        todos = v; sort(all(todos)); 
        todos.erase(unique(all(todos)), todos.end()); 
    }
    int obtener(int x) { 
        return (int)(lower_bound(all(todos), x) - todos.begin()); 
    }
};

const ll LOG = 20;

int main() {
    FIN;
    ll n,m; cin>>n>>m;
    vector<int> c;
    vector<pair<ll,ii>> buses(n);
    vector<pair<ii,ll>> people(m);
    forn(i,n) cin>>buses[i].ff>>buses[i]ss.ff>>buses[i].ss.ss;
    sort(all(buses));
    forn(i,m) cin>>people[i].ff.ff>>people[i].ff.ss>>people[i].ss;
    forn(i,n){c.pb(buses[i].ss.ff); c.pb(buses[i].ss.ss);}
    forn(i,m){c.pb(people[i].ff.ff); c.pb(people[i].ff.ss);}
    compresion coord(c);
    vector<vi> paral(n);
    vector<vi> paral2(n);
    vi left(m,-1),right(m,1e5+2);
    vi ans(m,-1);
    forn(i,m) paral[(n+1)/2].pb(i);
    forn(k,LOG){
        vi base(SZ(coord.todos)+5,1e9+7);
        segtree_lazy maxfin(base,SZ(base));
        forn(i,n){
            ii u=buses[i].ss;
            maxfin.update(coord.obtener(u.ff),coord.obtener(u.ff),u.ss);
            while(SZ(paral[i])>0){
                ll pos=paral[i].back(); paral[i].pop_back();
                ii recta=people[pos].ff;
                ll b=people[pos].ss;
                if(b>buses[i].ss){
                    left[pos]=i;
                }else{
                    ll maxder=maxfin.query(0,coord.obtener(recta.ff)).ans;
                    if(maxder>coord.obtener(recta.ss)){
                        left[pos]=i;
                    }else{
                        right[pos]=i;
                    }
                }
                paral2[left[pos]+right[pos]].pb(pos);
            }
        }
        swap(paral,paral2);
    }
    forn(i,m) cout<<ans[i]<<" ";
    cout<<"\n";
    return 0;
}