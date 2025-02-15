#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i<(ll)b; i++) 
#define forn(i,n) forr(i,0,n) 
#define all(v) (v).begin(), (v).end() 
#define pb push_back
#define SZ(x) int((x).size()) 
#define DBG(x) cerr << #x << " = " << x << endl
#define DBGV(v,n) forn(_,n) cerr << v[_] << ' '
#define RAYA cerr << "==============================\n"

ll digsum(ll n){
  ll ans=0;
  while(n){
    ans+=(n%10);
    n/=10;
  }
  return ans;
}

int main() {
  FIN; 
  ll d; cin>>d;
  string n=to_string(d);
  string ans;
  forn(i,d) ans+=n;
  //~ ll cont=d;
  //~ while(digsum(cont)%d) cont+=d;
  cout<<ans<<"\n";
  
  return 0; 
} 
