#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(int i = (ll)a; i <(ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "================================\n"


int main() {
  FIN;

  int n; cin >> n; 
  vi v(n); forn(i,n) cin >> v[i]; 
  v.pb(0); n++; 
  sort(all(v)); 

  ll mx = 0; 
  ll mi = 1LL<<60; 
  forn(i,n-1) mx = max(mx, v[i+1] -v[i]);  
  forn(i,n-2) mi = min(mi, v[i+2] -v[i]);  
  if (mx >= mi) cout << "0\n"; 
  else cout << mx << '\n'; 

  return 0; 
}
