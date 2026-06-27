#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "========================\n"


typedef ll tipo; 
const ll MOD=998244353;

ll be(ll a, ll b){
    if(b==0) return 1;
    ll c=be(a,b/2);
    c=c*c%MOD;
    if(b%2==1) c=c*a%MOD;
    return c;
}

struct node {
    tipo ans[3], f[3], l, r, k;
    node() {l = r = -1;}
    node(tipo val, int pos) : l(pos), r(pos) {
        k=1;
        val--;
        forn(i,3){
            ans[i]=1;
            f[i]=val+i;
        }
        ans[val]=0;
        f[val]=-1;
    }
    void upd(tipo val) {
        forn(i,3){
            ans[i]=1;
            f[i]=val+i;
        }
        ans[val]=0;
        f[val]=-1;
    }
};

struct segtree_lazy {
    #define l(x) int(x<<1)
    #define r(x) int(x<<1|1)
    vector<node> t; int tam;
    node op(node a, node b) {
        if(b.l==-1) return a;
        if(a.l==-1) return b;
        //RAYA;
        //cout << a.l << " " << a.r <<  " " << b.l << " " << b.r << endl;
        //DBG(a.k);
        //forn(i,3) {DBG(a.ans[i]); DBG(a.f[i]); DBG(b.ans[i]); DBG(b.f[i]);}
        node aux;
        aux.l = a.l, aux.r = b.r;
        aux.k=be(2,aux.r-aux.l+1)-1;
        forn(i,3){
            if(b.f[i]!=-1){
                if(a.f[3-b.f[i]]!=-1){
                    aux.f[i]=a.f[3-b.f[i]];
                    aux.ans[i]=(a.ans[3-b.f[i]]+b.ans[i]+b.ans[i]*a.k%MOD)%MOD;
                }
                else{
                    aux.f[i]=b.f[i];
                    aux.ans[i]=(b.ans[i]+b.ans[i]*a.k%MOD)%MOD;
                }
            }
            else{
                aux.f[i]=a.f[i];
                aux.ans[i]=a.ans[i];
            }
        }
        //forn(i,3) {DBG(aux.ans[i]); DBG(aux.f[i]);}
        return aux; 
    }
    node query(int l, int r, int p = 1) {
        node& cur = t[p];
        if (l > cur.r or r < cur.l) return node();
        if (l <= cur.l and cur.r <= r) return cur;
        return op(query(l, r, l(p)), query(l, r, r(p)));
    }
    void update(int x, tipo val, int p = 1) {
        node& cur = t[p];
        if (x > cur.r or x < cur.l) return;
        if (x <= cur.l and cur.r <= x) {
            cur.upd(val); return;
        }
        update(x, val, l(p)), update(x, val, r(p));
        cur = op(t[l(p)], t[r(p)]); 
    }
    void build(vector<tipo> v, int n) {
        tam = sizeof(int) * 8 - __builtin_clz(n); tam = 1<<tam;
        t.resize(2*tam); v.resize(tam); 
        forn(i,tam) t[tam+i] = node(v[i], i);
        for (int i = tam - 1; i > 0; i--) t[i] = op(t[l(i)], t[r(i)]); 
    }
};

int main() {
    FIN;
    int n, q; cin >> n >> q;
    vi v(n);
    forn(i,n) cin >> v[i];
    segtree_lazy s;
    s.build(v,n);
    while(q--){
        //RAYA; RAYA; RAYA;
        char c; cin >> c;
        int a, b; cin >> a >> b;
        a--; b--;
        if(c=='c') s.update(a,b);
        else cout << s.query(a,b).ans[0] << "\n";
    }
    return 0; 
}