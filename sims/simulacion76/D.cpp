#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cout << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"


int main() {
  FIN;
  ll n,k; cin>>n>>k;
  vi probs(n); forn(i,n) cin>>probs[i];
  map<ll,ll> cant;
  forn(i,n) cant[probs[i]]++;
  // RAYA;
  sort(all(probs));
  // RAYA;
  probs.erase(unique(all(probs)),probs.end());
  n = SZ(probs);
  // RAYA;
  vector<vector<vi>> cantseq(k+1,vector<vi>(n,vi(n,0)));
  // RAYA;
  forn(i,n) forr(j,i+1,n) cantseq[2][i][j]=cant[probs[i]]*cant[probs[j]];
  // RAYA;
  forn(act,n) forr(prev,0,act+1){
    // RAYA;
    // DBG(act);
    if(act!=prev){
      ll minimo=probs[act]-probs[prev];
      ll pos=(lower_bound(all(probs),minimo)-probs.begin());
      // DBG(minimo); DBG(pos);
      for(ll dup=prev; dup>=pos; dup--) for(ll c=k; c>=3; c--){
        cantseq[c][prev][act]+=cantseq[c-1][dup][prev];
      }
      for(ll c=k; c>=3; c--) cantseq[c][prev][act]*=cant[probs[act]];
      if(cant[probs[act]]>1){
        ll celems=cant[probs[act]];
        forr(c,3,k+1){
          ll base=(cantseq[c-1][prev][act]*(celems-1)/2);
          cantseq[c][act][act]+=base;
          // RAYA;
          for(ll rep=1; c+rep <=k && rep+2 <=celems; rep++){
            base=base*(celems-(rep+1))/(rep+2);
            cantseq[c+rep][act][act]+=base;
          }
        }
      }
    }
    if(act==prev and cant[probs[act]]>1){
      ll c=cant[probs[act]];
      ll base=(c)*(c-1)/2;
      cantseq[2][act][act]=base;
      forr(j,3,min(c+1,k+1)){
        base=base*(c-(j-1))/j;
        cantseq[j][act][act]+=base;
      }
    }
  }
  ll ans=0;
  // RAYA;
  forn(i,n) forr(j,i,n){
    ans+=cantseq[k][i][j];
    // DBG(i); DBG(j); DBG(cantseq[k][i][j]);
  }
  cout<<ans<<'\n';
  return 0; 
}