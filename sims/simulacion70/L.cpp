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
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl 
#define RAYA cerr << "======================\n"


const int MAXN = 1005; 
vector<string> v; 

int main() {
  FIN;

  int n; cin >> n; 
  
  map<string, int> mp; 
  vector<vi> app(MAXN, vi(12)); 
  
  auto cmp = [&](vi &xv, vi &yv) {
    // cerr << v[xv.back()] << " = "; 
    // forn(j,12) cerr << xv[j] << ' ';
    // cerr << '\n';
    
    // cerr << v[yv.back()] << " = "; 
    // forn(j,12) cerr << yv[j] << ' ';
    // cerr << '\n'; 
    forn(i,11) {
      if (xv[i] == yv[i]) continue; 
      else return xv[i] > yv[i]; 
    }
    return false; 
  }; 


  forn(_,n) {
    forn(i,10) {
      string s; cin >> s; 
      if (mp[s] == 0) {
        mp[s] = SZ(mp); 
        v.pb(s); 
        app[mp[s]-1][11] = mp[s] - 1; 
      }
      int id = mp[s]-1; 
      // cerr << s << ' ' << id << '\n'; 
      app[id][i+1]++; 
      app[id][0]++; 
    }
  }

  // DBG("debug");
  // forn(i,20) {
  //   cerr << v[app[i].back()] << " = "; 
  //   forn(j,12) cerr << app[i][j] << ' ';
  //   cerr << '\n'; 
  // }
  // RAYA; 

  sort(all(app), cmp); 

  // check if tie
  bool tie = true; 
  forn(i,11) {
    if (app[0][i] != app[1][i]) {
      tie = false; 
      break;
    }
  }

  if (tie) cout << "tie\n";
  else cout << v[app[0][11]] << '\n'; 

  return 0; 
}