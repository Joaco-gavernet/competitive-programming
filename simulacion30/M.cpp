#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi;
typedef pair<ll,ll> ii; 
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define all(c) (c).begin(),(c).end()
#define esta(v,x) (v).find(x) != (v).end()
#define pb push_back
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=================================\n"

void solve() {
  int n; cin >> n; 
  vi v(n); forn(i,n) cin >> v[i]; 
  unordered_map<int,int> cont; 
  forr(i,1,n) cont[v[i]]++; 

  ll ans = 0; 
  forr(j,1,n-1) {
    cont[v[j]]--;
    forn(i,j) {
      ll delta = v[j] -v[i];
      ll aux = cont[v[j] +delta]; 
      if (aux > 0) ans += aux;
    }
  }

  cout << ans << '\n'; 
  // RAYA; 
}

int main() {
  FIN; 
  int t; cin >> t; 
  while (t--) solve(); 
  return 0; 
}

