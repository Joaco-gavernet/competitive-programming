#include <bits/stdc++.h>
using namespace std; 

// un solo engargado: puede mirar el scoreboard y tiene que administra los tiempos. 
// anotar en la tablita el tiempo de inicio de codeo de cada uno. 
// si se pasa mucho tiempo sacarlo y que se encargue otro.
// prioricen codear un nuevo problema antes de debuggear. 
// debuggen solo en papel o desde el celu si no tienen impresora.
// planteen como objetivo quedar top 18 (Posicion para clasificar al mundial)

typedef long long ll; 
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 
typedef vector<ii> vii;
typedef long double ld;
#define NaN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back 
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size()) 
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "================================\n"
#define ff first
#define ss second 

const ld EPS = 1e-14;
const ld INF = 1e15;

int main() {
  NaN;
  cout<<fixed<<setprecision(10);
  ll n; cin>>n;
  vii pos(n);
  vi v(n);
  forn(i,n) cin>>pos[i].ff>>pos[i].ss>>v[i];
  ld l=0,r=2e6;
  forn(itbinsearch,60){
    ld med=(l+r)/2;
    ld r2=-INF,r4=-INF;
    forn(i,n){
      if(pos[i].ff+pos[i].ss-med*v[i] - EPS > r2) r2 = pos[i].ff+pos[i].ss-med*v[i];
      if(pos[i].ff-pos[i].ss-med*v[i] - EPS > r4) r4 = pos[i].ff-pos[i].ss-med*v[i];
    }
    bool impos=false;
    forn(i,n){
      ld num1,num3;
      num1=pos[i].ff+pos[i].ss+med*v[i];
      num3=pos[i].ff-pos[i].ss+med*v[i];
      if(r2 - EPS > num1){impos=true; break;}
      if(r4 - EPS > num3){impos=true; break;}
    }
    if(impos) l=med;
    else r=med;
  }
  cout<<r<<'\n';
  return 0; 
} 
