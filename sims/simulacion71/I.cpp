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
#define ff first
#define ss second
void solve(){
  int n, m; cin >> n >> m;
  vector <pair<ll,ll>> v(m+1);
  forn(i,m) cin >> v[i].ff >> v[i].ss;
  sort(all(v));
  forr(i,1,m+1){
    if(v[i].ss!=0 and v[i].ff-v[i-1].ff<=v[i].ss and v[i].ff-v[i-1].ff!=v[i].ss-v[i-1].ss){cout << "No\n"; return;}
    if(v[i].ss==0 and v[i].ff-v[i-1].ff<v[i].ss and v[i].ff-v[i-1].ff!=v[i].ss-v[i-1].ss){cout << "No\n"; return;}
  }
  cout << "Yes\n";
}

int main() {
  NaN;
  int t; cin >> t;
  while(t--) solve();
  return 0;
}