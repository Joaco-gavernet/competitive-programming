#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define NaN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "/////////////////////////////\n"


void debug(vector<vi> &tab) {
  for (auto v: tab) {
    for (auto x: v) cerr << x << ' ';
    cerr << '\n'; 
  }
}

ll solve(vector<vi> &tab, vi v) {
  // debug(tab);
  const int n = SZ(tab);
  const int m = SZ(tab[0]); 
  
  vi valids(n + m - 1); 
  forn(y,n) forn(x,m) if (tab[y][x] != -1) valids[y + x]++;
  
  ll tot = 0;
  vector<unordered_map<ll,ll>> cnt(n + m - 1); 
  int i = 0;
  while (SZ(v)) {
    while (SZ(v) and valids[i] > 0) {
      cnt[i][v.back()]++; 
      v.pop_back(); 
      valids[i]--; 
    }
    i++; 
  }
  assert(SZ(v) == 0 and i <= m + n); 
  
  forn(y,n) forn(x,m) if(tab[y][x]!=-1){
    tot += (cnt[x + y][tab[y][x]] <= 0);
    cnt[x + y][tab[y][x]]--; 
  }
  
  // DBG(tot); 
  // RAYA;
  return tot; 
}

int main() {
  NaN;


  int n, m; cin >> n >> m; 
  vector<vi> tab(n, vi(m));
  vi v; 
  forn(y,n) forn(x,m) {
    cin >> tab[y][x]; 
    if (tab[y][x] != -1) v.pb(tab[y][x]); 
  }
  
  ll best = 1LL<<60; 
  sort(all(v)); 
  // DBG(SZ(v)); 
  // for (auto x: v) cerr << x << ' ';
  // cerr << '\n';
  // RAYA; 

  best = min(best, solve(tab, v));
  reverse(all(v));
  best = min(best, solve(tab, v));
  
  forn(y,n) reverse(all(tab[y]));
  best = min(best, solve(tab, v));
  reverse(all(v));
  best = min(best, solve(tab, v));

  cout << best << '\n';

  return 0; 
}