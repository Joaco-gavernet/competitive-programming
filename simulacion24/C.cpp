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
#define DBGV(v,n) forn(i,n) cerr << v[i] << ' '
#define RAYA cerr << "==============================\n"


ll check(const int n, vi &pages, vi &profit) {
  ll best = 0; 
  forn(i,n) {
    vi dp(500, -1); 
    dp[0] = 0; 
    forn(j,n) {
      if (i == j) continue; 
      for (int t = 160; t >= 0; t--) 
        if (t-pages[j] >= 0 and dp[t-pages[j]] != -1) 
          dp[t] = max(dp[t], dp[t-pages[j]] +profit[j]); 
    }

    // check if possible to finish in extra time with book i
    for (int t = 260; t >= 0; t--) 
      if (t-pages[i] >= 0 and dp[t-pages[i]] != -1) 
        dp[t] = max(dp[t], dp[t-pages[i]] +profit[i]); 

    best = max(best, *max_element(all(dp))); 
  }
  return best; 
}

int main() {
  FIN; 

  int n; cin >> n; 
  vi pages(n), pleasure(n), fame(n); 
  forn(i,n) cin >> pages[i]; 
  forn(i,n) cin >> pleasure[i]; 
  forn(i,n) cin >> fame[i]; 

  ll pp = check(n, pages, pleasure); 
  ll ff = check(n, pages, fame); 

  if (pp == ff) cout << "EITHER\n";
  else if (pp > ff) cout << "PLEASURE\n"; 
  else cout << "FAME\n"; 

  return 0;
}
