#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define DBG(x) cerr << #x << " = " << x << endl 
#define RAYA cerr << "=============================\n"



int main() {
  FIN;

  int n, m; cin >> n >> m; 
  vi v(m, n);
  forn(_,n) {
    int sz; cin >> sz; 
    forn(_,sz) {
      int beg, en; cin >> beg >> en;
      beg--, en--;
      forr(i,beg,en+1) v[i]--; 
    }
  }

  int tot = 0;
  forn(i,m) if (v[i] >= 3) tot++;
  cout << tot << '\n';

  return 0; 
}