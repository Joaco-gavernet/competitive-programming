#include <bits/stdc++.h> 
using namespace std;


typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===========================\n"
#define DBG(x) cerr << #x << " = " << x << endl
#define DBGV(v,n) cerr << #v << " = "; forn(_,n) cerr << v[_] << ' '; cerr << '\n'

const ll INF=1LL<<60;

int main() {
  FIN;
  ll n; cin>>n;
  vi bets(n); forn(i,n) cin>>bets[i];
  sort(all(bets));
  reverse(all(bets));
  // RAYA;
  // DBG(n);
  // DBGV(bets,n); cout<<endl;
  ll j=bets[0];
  ll pos=1;
  ll ans=INF;
  ll m,x;
  ll offset=0;
  bool prim=true;
  while(pos<n){
    ll y=bets[pos];
    ll m2=1;
    while(bets[pos]==y) {m2++; pos++;}
    
    if(prim){ m=m2; x=y; prim=false;}
    else{
      x+=(x-y)*log2(m);
      m+=m2;
      offset+=(x-y)*(log2(m)+1);
    }
    ll k=log2(m);
    ll aux=(j-x)*(k+1)/k;
    if(aux>j) aux-=(j-x+1);
    ans=min(ans,aux);
  }
  cout<<ans<<"\n";
  return 0;
}
