#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 
#define forr(i,a,b) for(ll i = (ll)a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define pb push_back
#define all(v) begin(v), end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define DBGV(v) forn(_,SZ(v)) cerr << v[_] << " "
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)


int main() {
  FIN; 
  
  ll k,n; cin>>k;
  vi ing(k); forn(i,k) cin>>ing[i];
  cin>>n;
  vector<vi> orders(n,vi(k,0));
  vi cycle(k,0);
  forn(i,n){
    ll ingred;
    forn(j,k){
      cin>>ingred;
      orders[i][j]=ingred;
      cycle[j]+=ingred;
    }
  }
  ll ciclos=1e13;
  forn(i,k) if(cycle[i]>0) ciclos=min(ciclos,ing[i]/cycle[i]);
  forn(i,k) ing[i]-=(cycle[i]*ciclos);
  bool sigo=true;
  ll pos=0;
  // DBGV(ing); cerr<<endl;
  while(sigo and pos<n){
    ll cont=0;
    forn(i,k){
      if(orders[pos][i]<=ing[i]){
        cont++;
        ing[i]-=orders[pos][i];
      }
    }
    if(cont<k) sigo=false;
    pos++;
  }
  cout<<ciclos+1<<" "<<pos<<"\n";
  return 0; 
}