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

struct st2d {
  int n; 
  vector<vi> st;
  ll NEUT = 0; 
  ll op(ll a, ll b) { return a + b; }
  st2d(int _n): n(_n) { st.resize(2*n+5, vi(2*n+5, 0)); }

  void upd(int x, int y, ll v) {
    st[x+n][y+n] = v;
    for (int j = y+n; j > 1; j >>= 1) st[x+n][j>>1] = op(st[x+n][j], st[x+n][j^1]);
    for (int i = x+n; i > 1; i >>= 1) for (int j = y+n; j; j >>= 1) st[i>>1][j] = op(st[i][j], st[i^1][j]); 
  }

  ll query(int x0, int x1, int y0, int y1) {
    ll r = NEUT; x1++, y1++; 
    for (int i0 = x0+n, i1 = x1+n; i0 < i1; i0 >>= 1, i1 >>= 1) {
      int t[4], q = 0; 
      if (i0&1) t[q++] = i0++;
      if (i1&1) t[q++] = --i1; 
      forn(k,q) for (int j0 = y0+n, j1 = y1+n; j0 < j1; j0 >>= 1, j1 >>= 1) {
        if (j0&1) r = op(r, st[t[k]][j0++]);
        if (j1&1) r = op(r, st[t[k]][--j1]); 
      }
    }
    return r; 
  }
};



vector <string> v(2500);
vector <vb> visto(2500,vb(2500,false));

bool check(int l, int n, int m){
  st2d s(max(n,m));
  forn(i,n) forn(j,m) if(v[i][j]=='#') s.upd(i,j,1);
  forn(i,n) forn(j,m) if(!visto[i][j] and v[i][j]=='#'){
    if(i+l>n or j+l>m or s.query(i,i+l-1,j,j+l-1)!=l*l) return false;
    forn(k,l) forn(t,l){visto[i+k][j+t]=true; s.upd(i+k,j+t,0);}
  }
  return true;
}

int main() {
  FIN;
  int n, m; cin >> n >> m;
  forn(i,n) cin >> v[i];
  int tot=0;
  forn(i,n) forn(j,m) if(v[i][j]=='#') tot++;
  int d=0;
  forn(i,n){
    int c=0;
    forn(j,m){
      if(v[i][j]=='#') c++;
      else if(c>0){
        d=__gcd(d,c);
        c=0;
      }
    }
    if(c>0) d=__gcd(d,c);
  }
  forn(j,m){
    int c=0;
    forn(i,n){
      if(v[i][j]=='#') c++;
      else if(c>0){
        d=__gcd(d,c);
        c=0;
      }
    }
    if(c>0) d=__gcd(d,c);
  }
  forn(i,d) if(tot%((d-i)*(d-i))==0 and d%(d-i)==0){
    if(check(d-i,n,m)) {cout << d-i <<"\n"; return 0;}
    forn(i,n) forn(j,m) visto[i][j]=false;
  }
  return 0; 
}
