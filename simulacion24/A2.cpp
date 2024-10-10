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

typedef pair<string, string> tipo; 
struct cmp {
  bool operator () (const tipo &a, const tipo &b) const {
    if (a.first == b.first) return a.second < b.second; 
    else return a.first < b.first; 
  }
}; 

int main() {
  FIN; 

  int n; cin >> n; 
  // multiset<pair<string, string>> st; 
  vector<pair<string, string>> v; 
  forn(i,n) {
    string s, ss; cin >> s; 
    ss = s; 
    sort(all(ss)); 
    // st.insert({ss, s}); 
    v.push_back({ss, s}); 
  }

  sort(all(v)); 
  // for (auto [fst, snd] : v) cerr << fst << ' ' << snd << '\n'; 
  // RAYA; 

  int m; cin >> m; 
  while (m--) {
    string s, ss; cin >> s; 
    ss = s; 
    sort(all(ss)); 
    // cerr << ss << ' ' << s << '\n'; 
    cout << upper_bound(all(v), make_pair(ss,s), cmp()) -v.begin() << '\n'; 
    // cout << distance(st.begin(), st.upper_bound({ss, s})) << '\n'; 
  }


  return 0;
}
