#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll;
typedef long double ld;
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n) 
#define SZ(x) int((x).size()) 
#define all(v) begin(v),end(v)
#define pb push_back
#define ff first
#define ss second 
#define DBG(x) cerr << #x << " = " << x << endl 
#define RAYA cerr << "========================\n" 

void solve(){
  int n; cin >> n;
  vector <ii> v(n);
  ld sx=0, sy=0;
  forn(i,n){
    cin >> v[i].ff >> v[i].ss;
    sx+=v[i].ff; sy+=v[i].ss;
  }
  sx=sx/n; sy=sy/n;
  ld d=0;
  forn(i,n) d=max(d,sqrtl((v[i].ff-sx)*(v[i].ff-sx)+(v[i].ss-sy)*(v[i].ss-sy)));
  d/=2;
  ld cont=0;
  forn(i,n) if(sqrtl((v[i].ff-sx)*(v[i].ff-sx)+(v[i].ss-sy)*(v[i].ss-sy))<d) cont++;
  ld ans=((ld) n)/cont;
  if(fabsl(ans-4) <fabsl(ans-2.5)) cout << "circle\n";
  else cout << "square\n";
}

int main() {
  FIN; 
  int t; cin >> t;
  while(t--) solve();
  return 0; 
} 
