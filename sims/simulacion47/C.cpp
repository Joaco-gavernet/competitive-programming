#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i<(ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "============================\n"
#define DBGV(v) cerr << #v << " = "; forn(_,SZ(v)) cerr << v[_] << ' '; cerr << '\n'


int main() {
  FIN; 
  ll n; cin>>n;
  vi ans;
  if(n%2){
    ans.pb(3);
    n-=3;
  }
  while(n>0){
    ans.pb(2);
    n-=2;
  }
  cout<<SZ(ans)<<"\n";
  for(auto u:ans) cout<<u<<" ";
  cout<<"\n";
  return 0; 
}
