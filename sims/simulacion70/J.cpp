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
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl 
#define RAYA cerr << "======================\n"

int main() {
  FIN;
  ll n,k,q; cin>>n>>k>>q;
  // vector<pair<ll,ii>> trips(q);
  vector<ii> salidas,llegadas;
  forn(i,q){
    ll p,l,r; cin>>p>>l>>r;
    // trips[i].ff=p;
    // trips[i].ss.ff=l;
    // trips[i].ss.ss=r;
    salidas.pb({l,i});
    llegadas.pb({r,i});
  }
  sort(all(salidas));
  sort(all(llegadas));
  vi keys(q);
  ll ps=0,pl=0;
  ll contp=n;
  forn(i,2*q){
    if(ps<q and salidas[ps].ff<llegadas[pl].ff){
      // DBG(salidas[ps].ff);
      // DBG(llegadas[pl].ff);
      contp--;
      ps++;
    }else{
      // DBG(contp);
      if(contp==0) keys[llegadas[pl].ss]=1;
      contp++;
      pl++;
    }
  }
  ll contk=k;
  ps=0; pl=0;
  forn(i,2*q){
    if(ps<q and salidas[ps].ff<llegadas[pl].ff){
      // DBG(salidas[ps].ff); DBG(llegadas[pl].ff); DBG(contk);
      if(keys[salidas[ps].ss]==1){
        if(contk==0){cout<<"impossible\n"; return 0;}
        else contk--;
      }
      ps++;
    }else{
      // DBG(contk);
      if(keys[llegadas[pl].ss]==1) contk++;
      pl++;
    }
  }

  forn(i,q) cout<<keys[i];
  cout<<"\n";
  return 0; 
}