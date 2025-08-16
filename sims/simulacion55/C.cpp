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
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=====================================\n"

__int128 exp(__int128 x,ll e){
  if(e==0) return 1;
  __int128 aux=exp(x,e/2);
  aux*=aux;
  if(e%2) aux*=x;
  // DBG(aux);
  return aux;
}

int main() {
  FIN;
  vi caps={0,0,0,0,0,0,3981,1000,372,177,100,63,43,31,24,19,15,13,11,10,8,7,7,6,6,5,5,4,4,4,
  3,3,3,3,3,3,3,3};
  while(SZ(caps)<62) caps.pb(2);

  ll n,m; cin>>n>>m;
  if(n>61){cout<<"impossible\n"; return 0;}
  forr(b,2,caps[n]+1){
    __int128 b2=b;
    forr(a,1,b){
      __int128 a2=a;
      // DBG(a); DBG(b);
      __int128 t0den;
      t0den=(exp(b2,n)-exp(b2-a2,n));
      t0den/=a2;
      if( m % t0den != 0) continue;
      cout<<a<<" "<<b<<"\n";
      return 0;
    }
  }
  cout<<"impossible\n";
  return 0;
}
