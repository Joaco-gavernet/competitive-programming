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

ll f(vi &v){
  for(ll x : v) cout << x << " ";
  cout << endl;
  ll d; cin >> d;
  return d;
}

int main() {
  NaN;
  ll n; cin >> n;
  if(n==1){
    ll d;
    cout << "1 1"<< endl;
    cin >> d;
    if(d==0) return 0;
    cout << "1 2"<< endl;
    cin >> d;
    if(d==0) return 0;
    cout << "2 1"<< endl;
    cin >> d;
    if(d==0) return 0;
    cout << "2 2"<< endl;
    cin >> d;
    if(d==0) return 0;
  }
  vi v(n,n), ans(n,-1);
  ll d=f(v);
  if(d==0) return 0;
  forn(i,n){
    v[i]=1;
    ll aux=f(v);
    if(aux==0) return 0;
    if(aux>d) {ans[i]=1+aux; v[i]=n; continue;}
    v[i]=2*n;
    aux=f(v);
    if(aux==0) return 0;
    if(aux>d) {ans[i]=2*n-aux; v[i]=n; continue;}
    v[i]=n;
  }
  forn(i,n) if(ans[i]!=-1) v[i]=ans[i];
  forn(i,n) if(ans[i]==-1){
    v[i]=n-1;
    d=f(v);
    if(d==0) return 0;
    if(d>1) v[i]=n+1;
    else v[i]=n;
  }
  f(v);
  return 0; 
} 
