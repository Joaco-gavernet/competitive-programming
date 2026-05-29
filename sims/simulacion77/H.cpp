#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"


const ll INF = 1LL<<60; 

int main() {
  FIN;

  vector<string> v(3); forn(i,3) cin >> v[i]; 
  const int n = SZ(v[0]); 

  // hash all rotations of third row
  unordered_map<string, vi> h;
  string s = v[2]; 
  forn(i,n) {
    h[s].pb(i); 
    rotate(s.begin(), s.begin() + 1, s.end());
  }
  // for (auto [k, ops] : h) {
  //   cerr << k << " = "; 
  //   if (SZ(ops)) {
  //     for (auto x : ops) cout << x << ' '; 
  //     cout << '\n'; 
  //   }
  // }
  // RAYA; 

  // fix second row and check if any option is valid 
  ll best = INF; 
  char f[] = {'A', 'B', 'C'}; 
  int fi[] = {1, 2, 3}; 

  s = v[1]; 
  forn(i,n) {
    bool ok = true; 
    string rem = "";
    forn(j,n) {
      if (v[0][j] == s[j]) {
        ok = false;
        break; 
      }
      rem += f[(fi[v[0][j] - 'A'] ^ fi[s[j] - 'A']) - 1];
    }
    // cerr << i << " = " << v[0] << ' ' << s << ' ' << rem << '\n'; 
    rotate(s.begin(), s.begin() + 1, s.end()); 

    if (ok == false) continue; 
    if (h.count(rem) > 0) {
      vi ops = h[rem]; 
      ll tot = INF;

      tot = min(tot, max(i, ops[0])); // i, j
      tot = min(tot, i + n - ops.back()); // i, n - j
      tot = min(tot, n - i + ops[0]); // n - i, j
      tot = min(tot, max(n - i, n - ops.back())); // n - i, n - j
      
      best = min(best, tot); 
    }
  }

  if (best == INF) cout << "-1\n";
  else cout << best << '\n'; 

  return 0;
}