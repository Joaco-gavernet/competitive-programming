#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "===========================\n"



int main() {
  FIN;
  ll n,k,c; cin>>n>>k>>c;
  vector<vector<vi>> infect(k+1,vector<vi>(n));
  vi infday(n);
  vb rta(n);
  
  vi ans;
  forn(i,c){
    ll a,b,day; cin>>a>>b>>day;
    a--; b--;
    infday[a]=max(infday[a],day-1);
    infday[b]=max(infday[b],day-1);
    infect[day][a].pb(b);
    infect[day][b].pb(a);
  }
  forn(patzero,n){
    vb sure(n),poss(n);
    if(infday[patzero]==0) sure[patzero]=true;

    forr(day,1,k-1){
      vb sureaux=sure;
      forn(pers,n) for(auto u:infect[day][pers]){
        if(infday[pers] <= day and infday[u] <= day){
          if(sure[pers]) sureaux[u]=true;
          if(sure[u]) sureaux[pers]=true;
        }
      }
      sure=sureaux;
    }

    forn(pers,n) for(auto u:infect[k-1][pers]){
      if(!sure[u] and sure[pers]) poss[u]=true;
      if(!sure[pers] and sure[u]) poss[pers]=true;
    }

    forn(pers,n) for(auto u:infect[k][pers]){
      // DBG(pers); DBG(u); DBG(poss[pers]); DBG(poss[u]);
      if(k==1 or poss[pers]) rta[u]=true;
      if(k==1 or poss[u]) rta[pers]=true;
    }
  } 
  
  forn(i,n) if(rta[i]) ans.pb(i+1);

  sort(all(ans));
  cout<<SZ(ans)<<"\n";
  forn(i,SZ(ans)) cout<<ans[i]<<"\n";

  return 0;
}