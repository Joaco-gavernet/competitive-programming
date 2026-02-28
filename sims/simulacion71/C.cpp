#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define NaN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define pb push_back
#define all(v) begin(v),end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "============================\n"

void solve(){
  ll p, m; cin >> p >> m;
  ll t=m/p;
  ll ans=t;
  if(((p-1)^(t*p+1))<=m) ans++;
  if(((p-1)^(t*p+p+1))<=m) ans++;
  cout << ans << "\n";
}

int main() {
  NaN;
  int t; cin >> t;
  DBG(t);
  while(t--) solve();
  return 0;
}