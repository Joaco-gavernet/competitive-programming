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

void solve() {
  int n, m, k, b; cin >> n >> m >> k >> b; 
  
  vector<ii> v(n);
  forn(i,n) {
    ll act = 0, upd = 0; 
    vi score(m); 
    forn(j,m) {
      cin >> score[j]; 
      act += score[j];
      if (score[j] <= 0) upd += score[j] +1;
      else upd += score[j] -1; 
    }
    v[i] = {act, upd}; 
  }
  sort(all(v));
  ll tot = 0;
  while (SZ(v) and v.back().ff >= k) v.pop_back(), tot++; 
  
  vi rest; 
  for (auto p: v) rest.pb(p.ss);
  sort(all(rest));
  while (SZ(rest) and b and rest.back() >= k) b--, rest.pop_back(), tot++; 

  cout << tot << '\n'; 
}

int main() {
  FIN;
  int t; cin >> t;
  while (t--) solve();
  return 0;
}