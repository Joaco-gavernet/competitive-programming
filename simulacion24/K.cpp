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


bool check(vector<vector<ii>> &dishes, vi &ingr, int x) {
  for (auto [ing, cant] : dishes[x]) {
    if (ingr[ing] < cant) return false;
    else ingr[ing] -= cant;
  }
  return true; 
}

int main() {
  FIN; 

  int n,m,o; cin >> n >> m >> o; 
  vi ingr(n); forn(i,n) cin >> ingr[i]; 
  vector<vector<ii>> dishes(m);
  forn(i,m) {
    int tot; cin >> tot; 
    dishes[i].resize(tot); 
    forn(j,tot) {
      cin >> dishes[i][j].first >> dishes[i][j].second; 
      dishes[i][j].first--; 
    }
  }

  forn(k,o) {
    int tot; cin >> tot; 
    while (tot--) {
      int x; cin >> x; x--; 
      if (check(dishes, ingr, x) == false) {
        cout << k << '\n'; 
        return 0; 
      }
    }
  }

  cout << o << '\n';
  return 0;
}
