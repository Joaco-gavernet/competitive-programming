#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==============================\n"




int main() {
  FIN; 

  ll n; cin >> n; 
  multiset<string> st; 
  map<string, multiset<string>> mp; 
  forn(i,n) {
    string s, so; cin >> s; 
    so = s; 
    sort(all(s)); 
    mp[s].insert(so); 
    st.insert(s); 
  }
  for (auto s : st) DBG(s); 
  RAYA; 

  int q; cin >> q; 
  while (q--) {
    string s, so; cin >> s; 
    so = s; 
    sort(all(s)); 
    ll ans = 0;
    auto it = st.lower_bound(s); 
    if (it != st.begin()) { 
      ans = distance(st.begin(), --it) +1;
      it++; 
    }
    if (it != st.end() and *it == s) {
      auto itt = mp[s].upper_bound(so); 
      if (itt != mp[s].begin()) ans += distance(mp[s].begin(), --itt) +1;
    }
    cout << min(n, ans) << endl; 
  }


  return 0;
}
