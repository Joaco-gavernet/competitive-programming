/*   AUTHOR: Estufa en Piloto   */
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "===============================" << endl
#else
#define DBG(x)
#define RAYA
#endif

typedef long long ll;
typedef vector<ll> vi; typedef pair<int,int> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define SZ(x) int((x).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())
#define f first
#define s second
const int INF = 1<<30; // const ll INF = (1LL<<60);
const int MOD = 1e9+7;  // const int MOD = 998244353;
const int MAXN  = 2e5+5;


bool comp(ii &a, ii &b) {
  if (a.f > b.f) return true;
  else if (a.f == b.f and a.s < b.s) return true;
  else return false;
}


int main(){  
  FIN;
  
  
  int n; cin >> n;
  vector<ii> v(n);
  forn(i,n) {
    cin >> v[i].f;
    v[i].s = i;
  }
  sort(all(v),comp);
  forn(i,n) DBG(v[i].f);

  vector<vector<int>> ans(n, vector<int>());
  set<ii> pq;
  RAYA;

  forn(k,n) {
    DBG(k);
    pq.insert({v[k].s, v[k].f});
    for (auto ptr: pq) {
      ans[k].pb(ptr.second);
    }
  }

  RAYA;
  int m; cin >> m;
  while (m--) {
    int kj, pos; cin >> kj >> pos;
    DBG(pos);
    DBG(kj);
    cout << ans[--kj][--pos] << '\n';
  }
  
  
  
  return 0;
}
