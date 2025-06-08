#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=========================\n"

const ll MOD = 1e9+7;
typedef vector<vi> Matrix; 

const int MAXN = 10;
Matrix trans(MAXN, vi(MAXN));

Matrix ones(int n) {
  Matrix r(n, vi(n));
  forn(i,n) r[i][i] = 1;
  return r;
}
Matrix operator*(Matrix &a, Matrix &b) {
  int n = SZ(a), m = SZ(b[0]), z = SZ(a[0]); 
  Matrix r(n, vi(m));
  forn(i,n) forn(j,m) forn(k,z)
    r[i][j] += a[i][k]*b[k][j], r[i][j] %= MOD;
  return r;
}
Matrix be(Matrix b, ll e) {
  if(e==0) return ones(SZ(b));
  Matrix r = ones(SZ(b));
  while (e) { if (e&1LL) r = r*b; b = b*b; e /= 2; }
  return r;
}

 
int main() {
  FIN;

  // Matrix trans(MAXN, vi(MAXN));
  trans[0][2] = trans[0][4] = trans[0][6] = trans[0][8] = 3; 
  forn(i,9) trans[i+1][i] = 1;


  // forn(i,MAXN) {
  //   forn(j,MAXN) cerr << trans[i][j] << ' ';
  //   cerr << '\n'; 
  // }
  // RAYA;

  ll t; cin>>t;
  while(t--){
    ll n; cin>>n;
    n/=2;
    Matrix in(10,vi(1,0)); in[0][0]=1;
    Matrix res=be(trans,n);
    // for(auto u:res){for (auto v:u) cout<<v<<" "; cout<<endl;} 
    Matrix mans=res*in;
    // for(auto u:mans){for (auto v:u) cout<<v<<" "; } cout<<endl;
    ll ans=0;
    for(auto u:mans) for(auto v:u){ans=(ans+v)%MOD;}
    cout<<ans<<"\n";
  }

  return 0; 
}