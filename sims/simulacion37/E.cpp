#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define pb push_back
#define esta(x,v) (v).find(x) != (v).end()
#define all(v) (v).begin(),(v).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "================================\n"
#define DBGV(v,n) forn(i,n) cerr << v[i] << ' '


ll be(ll x, ll y, ll m) {
  if (y == 0) return 1;
  ll p = be(x, y/2, m) %m;
  p = (p * p) %m;
  return (y%2 == 0) ? p : (x * p) %m; 
}

int main() {
  FIN;
  
  ll n, k; cin >> n >> k;
  string s; cin >> s; 
  
  ll jump = be(2,k,n); 
  forn(i,n) cout << s[(i*jump) %n]; 
  cout << '\n'; 
  
  return 0;
}
