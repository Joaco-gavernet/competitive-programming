#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << '\n'
#define RAYA cerr << "===========================\n"

struct DSU {
  vi link, sz;

  DSU(int tam) {
    link.resize(tam+5), sz.resize(tam+5);
    forn(i,tam+5) link[i] = i, sz[i] = 1;
  }

  ll find(ll x) { return link[x] = (link[x] == x ? x : find(link[x])); }
  bool same(ll a, ll b) { return find(a) == find(b); }
  void join(ll a, ll b) {
    a = find(a), b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    link[b] = a;
  }
};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_random(int l, int r){return uniform_int_distribution<int>(l,r)(rng);}

vi dx={-1,-1,-1,0,0,1,1,1}, dy={1,0,-1,1,-1,1,0,-1};

int main() {
  FIN;
  vi cont(2);
  DSU d(1156);
  vector <vi> v(17,vi(52,2));
  forn(i,17){
    forr(j,16-i,52-i){
      ll r=my_random(0,99);
      cont[r%2]++;
      v[i][j]=r%2;
    }
    cout << endl;
  }
  forn(i,17){
    forn(j,52){
      if(v[i][j]==2) cout << '*';
      else cout << v[i][j];
    }
    cout << endl;
  }
  forn(i,17) forn(j,52) if(v[i][j]!=2) forn(k,8) if(i+dx[k]<17 and i+dx[k]>=0 and j+dy[k]<52 and j+dy[k]>=0 and v[i][j]==v[i+dx[k]][j+dy[k]]){
    d.join(i*52+j,(i+dx[k])*52+j+dy[k]);
  }
  cout << cont[0] << " " << cont[1] << endl;
  ll ans=0;
  forn(i,884) ans=max(ans,d.sz[i]);
  DBG(ans);
  return 0;
}