#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==============================" << endl
#define ff first
#define ss second

const ll INF = 1LL<<60; 

int main() {
  FIN;
  
  int n; cin >> n;
  vi a(n); forn(i,n) cin >> a[i]; 

  vi pref(n); 
  pref[0] = a[0]; 
  forn(i,n-1) pref[i+1] = (pref[i] + a[i+1]) %10; 
  set<ii> st; 
  forn(i,n) st.insert({pref[i], i}); 

  // for (auto x: pref) cout << x << " ";
  // cout << endl; 
  // RAYA;

  vi ans(n, -1); 
  forn(i,n) {
    ll rest = 0; 
    if (i > 0) rest = pref[i-1]; 
    auto it = st.lower_bound({rest, -INF}); 
    if (it != st.end()) {
      ans[i] = it->ss -i +1;
      if (it->ss == i and a[i] > 0) ans[i] = -1; 
    }
    st.erase({pref[i], i}); 
  }

  for (auto x: ans) cout << x << " "; 
  cout << endl; 

  return 0;
}