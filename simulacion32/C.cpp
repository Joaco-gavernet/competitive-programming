#include <bits/stdc++.h> 
using namespace std; 

//~ g++ -std=c++17 -DLOCAL -g -O2 -Wconversion -Wshadow -Wall -Wextra -D_GLIBCXX_DEBUG -c %f
//~ g++ -std=c++17 -DLOCAL -g -O2 -Wconversion -Wshadow -Wall -Wextra -D_GLIBCXX_DEBUG -o %e %f

typedef long long ll; 
typedef vector<ll> vi; 
typedef vector<bool> vb;
typedef vector<long double> vd;
typedef pair<ll,ll> ii;  
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define esta(v,x) (v).find(x) != (v).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "===================================\n" 

const int MAXN = 200; 
// const double EPS = 1e-6; 
// const double EPS = 0; 

int main() {
  FIN; 
  
  int n; 
  long double m; 
  cin >> n >> m; 
  vd pieces; 
  forn(i,n) {
    int tot; cin >> tot; 
    long double len; cin >> len; 
    forn(i,tot) pieces.pb(len); 
  }

  bitset<MAXN> rest; 
  const int sz = SZ(pieces); 
  forr(i,sz,MAXN) rest[i] = 1; 
  /*
  DBG(m); 
  DBG(sz); 
  forn(i,MAXN) cerr << rest[i] << ' '; 
  cerr << endl; 
  */

  ll ans = 0; 
  while (rest.count() < MAXN) {
    long double best = 0; 
    int bmask = 0; 
    forn(mask,1<<sz) {
      long double act = 0; 
      forn(i,sz) 
        if (rest[i] == 0 and mask & (1<<i)) 
          act += pieces[i]; 
      if (act <= m and best < act) best = act, bmask = mask; 
    }
    forn(i,sz) {
      if (rest[i]) continue; 
      rest[i] = bmask & (1<<i); 
    }
    ans++; 
    /*
    forn(i,MAXN) cerr << rest[i] << ' '; 
    cerr << endl; 
    RAYA; 
    */
  }
  cout << ans << '\n'; 
  
  return 0;
}
