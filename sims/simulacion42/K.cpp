#include <bits/stdc++.h> 
using namespace std; 

typedef unsigned long long ll; 
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


int main() {
  FIN; 
  ll t; cin>>t;
  while(t--){
    ll n; cin>>n;
    ll ans=-1;
    ll bit=(1LL<<60);
    ll seq=(1LL<<60);
    seq--;
    seq+=bit;
    bit=60;
    while(n>0){
      //~ DBG((1<<bit)-1);
      while(n>=seq){
	n-=seq;
	ans++;
	//~ DBG(n);
      }
      ll aux=(1LL<<bit);
      seq-=aux;
      bit--;
      //~ DBG(n);
    }
    cout<<ans<<"\n";
  }
  return 0; 
} 
