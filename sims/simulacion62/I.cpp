#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n) 
#define SZ(x) int((x).size()) 
#define all(v) begin(v),end(v)
#define pb push_back
#define ff first
#define ss second 
#define DBG(x) cerr << #x << " = " << x << endl 
#define RAYA cerr << "========================\n" 

const ll MOD = 998244353;

ll be(ll x, ll y){
  if(y==0) return 1;
  ll p=be(x,y/2)%MOD;
  p=(p*p)%MOD;
  return (y%2==0)? p : (x*p)%MOD;
}

ll inv_mod(ll x) { return be(x, MOD-2); }

void solve() {
  int n, k; cin >> n >> k; 
  unordered_map<int, int> cont; 
  vi a(n); forn(i,n) cin >> a[i], cont[a[i]]++; 
  vector<ii> v; 
  for (auto [key, x]: cont) v.pb({key,x}); 
  sort(all(v)); 

  forn(i,SZ(v)-1) {
    int dif = v[i+1].ff -v[i].ff; 
    if (dif*v[i].ss <= k) {
      v[i+1].ss += v[i].ss;
      k -= dif*v[i].ss;
      v[i].ss = 0;
    } else {
      int co = k/v[i].ss; 
      v[i].ff += co; 
      k %= v[i].ss;
      v[i].ss -= k; 
      if (k > 0) {
        if (v[i+1].ff == v[i].ff +1) v[i+1].ss += k;
        else v.pb({v[i].ff +1, k}); 
      }
      k = 0; 
      break; 
    }
  }

  sort(all(v)); 
  if (k > 0) {
    int co = k/v.back().ss; 
    v.back().ff += co; 
    k %= v.back().ss; 
    v.back().ss -= k; 
    if (k > 0) v.pb({v.back().ff +1, k}); 
  }
  
  ll denom = 0; 
  for (auto [key, x]: v) {
    if (x > 0) {
      denom += (inv_mod(key)*x) % MOD; 
      denom %= MOD;
    }
  }

  denom = (denom * inv_mod(n) % MOD); 
  cout << denom << endl; 
}

int main() {
  FIN; 
  int t; cin >> t;
  while (t--) solve(); 
  return 0; 
} 
