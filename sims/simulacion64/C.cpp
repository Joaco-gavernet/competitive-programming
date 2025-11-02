#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i <(ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << '\n'
#define DBGV(v) forn(_,SZ(v)) cerr<<v[_]<<" " 
#define RAYA cerr << "============================\n"
#define ff first
#define ss second

const ll MOD = 1e9;

typedef vector<vector<ll>> Matrix;

Matrix ones(ll n){
  Matrix r(n,vector<ll>(n));
  forn(i,n) r[i][i]=1;
  return r;
}

Matrix operator*(Matrix &a, Matrix &b){
  int n=a.size(), m=b[0].size(),z=a[0].size();
  Matrix r(n,vector<ll>(m));
  forn(i,n) forn(j,m) forn(k,z) r[i][j]+=a[i][k]*b[k][j],r[i][j]%=MOD;
  return r;
}

Matrix be(Matrix b,ll e){
  Matrix r=ones(b.size());
  while(e){if(e&1LL)r=r*b;b=b*b;e/=2;}
  return r;
}


int main() {
  FIN;
  ll n,m; cin>>n>>m;
  vi dpfil(n+1); dpfil[0]=1; dpfil[1]=1;
  forr(i,2,n+1) dpfil[i]=dpfil[i-1]+dpfil[i-2];
  ll tam=1<<n;
  Matrix trans(tam,vi(tam));
  forn(col,tam) forn(fil,tam) if(!(col&fil)){
    ll x=col|fil;
    ll pos=0;
    vi inter; ll cont=0;
    while(pos<n){
      if (!(1<<pos & x)) cont++;
      else if(cont>0) {inter.pb(cont); cont=0;}
      pos++;
    }
    if(cont>0) {inter.pb(cont); cont=0;}
    ll el=1;
    for(auto u:inter) el=(el*dpfil[u])%MOD;
    trans[fil][col]=el;
  }
  //forn(i,tam){DBGV(trans[i]); cerr<<endl;}
  Matrix inicial(1,vi(tam)); inicial[0][0]=1;
  Matrix calc=be(trans,m);
  Matrix final=inicial*calc;
  //RAYA;
  //forn(i,tam){DBGV(final[i]); cerr<<endl;}
  ll ans=final[0][0];
  //for(auto u:final) for(auto v: u) ans=(ans+v)%MOD;
  cout<<ans<<"\n";
  return 0; 
}