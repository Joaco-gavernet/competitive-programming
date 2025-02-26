#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0) 
#define forr(i,a,b) for(int i = a; i < b; i++)
#define forn(i,n) forr(i,0,n) 
#define all(v) begin(v), end(v)
#define SZ(x) int((x).size()) 
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "===============================\n" 
#define pb push_back


void check(int &best, int &fs, int &ss, map<int, vi> &r, int mx) {
  for (auto [k, st]: r) {
    sort(all(st)); 
    if (SZ(st) < best or SZ(st) == mx) continue; 

    forn(i, SZ(st)) {
      if (i +1 != st[i]) {
        if (best < SZ(st) -i) {
          best = SZ(st) -i; 
          fs = k; 
          ss = i +1;
        } 
        break; 
      } 
    } 

    int i = 0; 
    while (st[SZ(st) -1 -i] == mx -i) i++; 
    if (best < SZ(st) -i) {
      best = SZ(st) -i; 
      fs = k; 
      ss = mx -i;
    } 
  } 
} 

int main() {
  FIN; 

  int n, m, k; cin >> n >> m >> k; 

  map<int, vi> rx, ry; 
  forn(i,k) {
    int x, y; cin >> x >> y; 
    rx[x].pb(y); 
    ry[y].pb(x); 
  } 

  int best = 0;
  int ax = 0, ay = 0; 

  check(best, ay, ax, ry, n); 
  check(best, ax, ay, rx, m); 
  cout << best << '\n'; 
  cout << ax << ' ' << ay << '\n'; 

  return 0;
}
