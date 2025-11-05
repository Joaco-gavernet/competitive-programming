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
#define RAYA cerr << "==============================\n"

const ll INF=1e17;

typedef vector<vi> Matrix;

Matrix ones(int n) {
  Matrix r(n, vi(n));
  forn(i,n) r[i][i] = 1;
  return r;
}

Matrix operator * (Matrix &a, Matrix &b) {
  int n = SZ(a), m = SZ(b[0]), z = SZ(a[0]);
  Matrix r(n, vi(m));
  forn(i,n) forn(j,m) forn(k,z) {
    r[i][j] = max(r[i][j], a[i][k] + b[k][j]);
  }
  return r;
}

Matrix be(Matrix b, ll e) {
  Matrix r = b; e--;
  while (e) { if (e&1LL) r = r*b; b = b*b; e /= 2; }
  return r; 
}


void solve() {
  ll n,m,k,r; cin>>n>>m>>k>>r;
  vi dam(n),cos(n); forn(i,n) cin>>dam[i]>>cos[i];
  ll est=1<<n;
  Matrix trans(est,vi(est,0));
  forn(i,est) forn(j,est){
    ll c=0,d=0;
    forn(b,n) if(1<<b & j){
      d+=dam[b];
      c+=cos[b];
      if(1<<b & i) c+=k;
    }
    if(c<=m) trans[i][j]=d;
  }
  Matrix ans=be(trans,r);
  Matrix inicial(1,vi(est,-INF)); inicial[0][0]=0;
  Matrix final=inicial*ans;
  ll ansn=0;
  for(auto u:final) for(auto v:u) ansn=max(ansn,v);
  cout<<ansn<<"\n";
}

int main() {
  FIN;
  int t; cin >> t;
  while (t--) solve();
  return 0;
}