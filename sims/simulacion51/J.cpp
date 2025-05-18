#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 
#define forr(i,a,b) for(ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define pb push_back
#define all(v) begin(v), end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
  FIN; 
  ll n; cin>>n;
  string s; cin>>s;
  vector<int> firstap(67108870,-1);
  firstap[0]=0;
  ll ans=1;
  ll actual=0;
  forr(i,1,n+1){
    char c=s[i-1];
    ll pos=c-'a';
    actual ^= (1<<pos); 
    // if(actual==0) ans=max(ans,i);
    if(firstap[actual]!=-1) ans=max(ans,i-firstap[actual]);
    forn(letra,26){
      // if(actual & (1<<letra)){
        ll auxi=actual^(1<<letra);
        if(firstap[auxi]!=-1) ans=max(ans,i-firstap[auxi]);
      // }
    }
    if(firstap[actual]==-1) firstap[actual]=i;
  }
  cout<<ans<<'\n';
  return 0; 
}