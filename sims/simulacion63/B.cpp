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
#define RAYA cerr << "==================================\n"

typedef ll tipo;
const tipo NEUT = 0; 

struct node {
  int l, r; tipo ans,cant;
  node() { ans = NEUT, l = r = -1; cant=0;}
  node(tipo val, int pos): l(pos), r(pos), ans(val), cant(val) {}
  void update(tipo val) { 
    ans += val;
    if(ans) cant=1;
    else cant=0; 
  }
};

struct segtree {
  #define l(x) int(x<<1)
  #define r(x) int(x<<1|1)
  vector<node> t; int tam;
  
  node op(node a, node b) {
    // ...
    node aux; 
    aux.ans=a.ans+b.ans;
    aux.cant=a.cant+b.cant;
    aux.l=a.l; aux.r=b.r;
    return aux;
  }

  node query(int l, int r, int p = 1) {
    node &cur = t[p];
    if (l > cur.r or r < cur.l) return node();
    if (l <= cur.l and cur.r <= r) return cur;
    return op(query(l, r, l(p)), query(l, r, r(p)));
  }

  void update(int pos, tipo val, int p = 1) {
    node &cur = t[p];
    if (cur.r < pos or cur.l > pos) return;
    if (cur.l == cur.r) { cur.update(val); return; }
    update(pos, val, l(p)); update(pos, val, r(p));
    cur = op(t[l(p)], t[r(p)]); 
  }

  void build(vector<tipo> v, int n) {
    tam = sizeof(int) *8 -__builtin_clz(n); tam = 1<<tam;
    t.resize(2*tam); v.resize(tam);
    forn(i,tam) t[tam+i] = node(v[i], int(i));
    for (int i = tam -1; i > 0; i--) t[i] = op(t[l(i)], t[r(i)]); 
  }
};



int main() {
  FIN;
  ll n,b,r,w; cin>>n>>b>>r>>w;
  vi travel(n,0);
  forn(i,b) cin>>travel[i];
  vi findest(n);
  forn(i,n) cin>>findest[i];
  ll liminf=0; ll limsup=100;
  ll med=(liminf+limsup)/2;
  while(liminf+1<limsup){
    //DBG(med);
    bool puedo=true;

    ll pos=0;
    vi base(b+1,0);
    segtree st; st.build(base,b+1);
    ll nbus=0;
    //RAYA;
    while(pos<n){
      ll lastpo=pos;
      ll contpe=0;
      ll lastpa=0;
      ll tbus=nbus*r;
      if(tbus>med){
        puedo=false; 
        break;
      }
      //DBG(pos);
      while(tbus<med and pos<n){
        //DBG(pos);
        ll act=findest[pos];
        contpe++;
        node viejo=st.query(act,act);
        st.update(act,1);
        node nuevo=st.query(act,act);
        node data=st.query(0,act);
        //DBG(data.ans); DBG(data.cant); DBG(contpe);
        ll nue=nuevo.cant-viejo.cant; 
        //DBG(act); DBG(lastpa);
        if(lastpa<act){
          tbus+=(2*w*data.cant);
          //DBG(tbus);
          while(lastpa<act){
            tbus+=travel[lastpa++];
            //DBG(tbus);
          }
        }else{
          tbus+=(2*w*data.cant);
          if(nue){
            //RAYA;
            tbus+=((contpe)-data.ans)*2*w;
          }
        }
        pos++;
      }
      //DBG(tbus);
      if(tbus>med) pos--;
      if(lastpo==pos){
        puedo=false; 
        break;
      }
      nbus++;
      while(contpe--){
        //DBG(lastpo);
        st.update(findest[lastpo++],-1);
      }
    }


    if(puedo) limsup=med;
    else liminf=med;
    med=(liminf+limsup)/2;
  }
  cout<<limsup<<"\n";
  return 0; 
}
