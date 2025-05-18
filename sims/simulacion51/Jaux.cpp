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
  // unordered_map<ll,ll> firstap;
  vector<int> firstap(67108870,0);
  ll ans=1;
  ll actual=0;
  // vi histo(26,0);
  forr(i,1,n+1){
    char c=s[i-1];
    ll pos=c-'a';
    // if(histo[pos]%2) actual-=(1<<pos);
    // else actual+=(1<<pos);
    actual ^= (1<<pos); 
    // histo[pos]^=1;
    // DBG(actual);
    if(actual==0) ans=max(ans,i);
    if(firstap[actual]!=0) ans=max(ans,i-firstap[actual]);
    forn(letra,26){
      if(actual & (1<<letra)){
        ll auxi=actual-(1<<letra);
        if(firstap[auxi]!=0) ans=max(ans,i-firstap[auxi]);
      }
      if(actual == (1<<letra)) ans=max(ans,i);
    }
    if(firstap[actual]==0) firstap[actual]=i;
    // DBG(ans);
  }
  cout<<ans<<'\n';
  return 0; 
}