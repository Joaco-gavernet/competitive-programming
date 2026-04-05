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


const ll INF = 1LL<<60; 

int main() {
  NaN;

  int n; cin >> n; 
  vi p(n); forn(i,n) cin >> p[i], p[i] %= 5; 
  sort(all(p));

  ll best = 0; 
  int a = 0, b = 0; 
  forn(i,n) {
    if (p[i] == 3) a++;
    else if (p[i] == 4) b++;
    else best += p[i]; 
  }

  best += min(a, b) * 2; 
  int d = min(a, b); 
  a -= d, b -= d;

  best += (b / 3) * 2; 
  b %= 3; 

  best += a / 2; 
  a %= 2; 

  best -= 2 * a;
  best -= b;  

  cout << best << '\n'; 


  return 0; 
} 
