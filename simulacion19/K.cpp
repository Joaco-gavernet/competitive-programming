#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<bool> vb;

#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define DBG(c) cerr << #c << " = " << (c) << endl
#define DBGV(v,n) forn(i,n) cerr << v[i] << " "; cerr << endl
#define RAYA cerr << " ============================= " << endl
#define SZ(x) int((x).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()

const int INF = -1;
const int MOD = -1;
const int MAXN = -1;

vi prod(vi a, vi b) {
  vi ans(SZ(a)+SZ(b)-1);
  forn(i,SZ(a)) {
    forn(j,SZ(b)) {
      ans[i+j] += a[i]*b[j];
    }
  }
  return ans;
}

int main() {
  FIN;
  
  string s; cin >> s;
  ll n = SZ(s);
  vi raices;
  
  forr(i,1,n) {
    if (s[i-1] != s[i]) {
      // encuentro raiz
      raices.pb(2*i +1); 
    }
  }
  
  vector<vi> polis;
  for (int r : raices) polis.pb({-r,1});
  
  while (SZ(polis) > 1) {
    vector<vi> nuevos;
    
    for (int i = 0; i < SZ(polis); i += 2) {
      if (i == SZ(polis) -1 and i %2 == 0) nuevos.pb(prod(polis[i], {1})); 
      else nuevos.pb(prod(polis[i], polis[i+1]));
    }

    polis = nuevos;
    nuevos.clear();
  }
    
  // OUTPUT //////////////////////////
  cout << SZ(raices) << '\n';
  if (SZ(raices)) {
    // acomodo los signos
    const ll sz = SZ(raices);
    if ((sz%2 == 0 and s[0] == 'A') or (sz%2 == 1 and s[0] == 'H')) {
      forn(i,SZ(polis[0])) polis[0][i] *= -1;
    }
    
    reverse(all(polis[0]));
    for (auto i : polis[0]) cout << i << " ";
    cout << endl;
  } else {
    if (s[0] == 'A') cout << "-1\n";
    else cout << "1\n";
  }
  
  
  
  return 0;
}
