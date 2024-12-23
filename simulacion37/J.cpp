#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define pb push_back
#define esta(x,v) (v).find(x) != (v).end()
#define all(v) (v).begin(),(v).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "================================\n"
#define DBGV(v,n) forn(i,n) cerr << v[i] << ' '
#define fs first
#define ss second

struct tow {
  ll x, y, h, idx; 
  bool operator < (const tow &t) const {
    return h < t.h; 
  }
};

int main() {
  FIN;
  
  int n; cin >> n;
  vector<tow> v(n); 
  forn(i,n) {
    cin >> v[i].x >> v[i].y >> v[i].h; 
    v[i].idx = i; 
  }
  
  sort(all(v)); 
  reverse(all(v)); 
  
  vector<tow> used; 
  vi ans(n, -1); 
  forn(i,n) {
    ans[v[i].idx] = v[i].h; 

    // recorro las que ya quedaron fijas
    for (auto u: used) {
      ll act = ans[v[i].idx]; 
      ll dist = (u.x -v[i].x)*(u.x -v[i].x) + (u.y -v[i].y)*(u.y -v[i].y); 
      if (act*act > dist) 
	ans[v[i].idx] = sqrt(dist); 
    }
    
    used.pb({v[i]}); 
  }
  forn(i,n) cout << ans[i] << '\n'; 
  
  
  return 0;
}
