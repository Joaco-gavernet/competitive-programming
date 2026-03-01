#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define NaN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "/////////////////////////////\n"


int main() {
  NaN;
  ll p,u; cin>>p>>u;
  ll n=p+u;
  vb pin(n,false);
  vi stackp,stacku;
  forn(i,p){
    ll x; cin>>x; x--;
    stackp.pb(x);
    pin[x]=true;
  }
  forn(i,u){
    ll x; cin>>x; x--;
    stacku.pb(x);
  }
  reverse(all(stackp));

  vb isunp(n,false);
  ll ans=0;
  ll pf,uf; cin>>pf>>uf;
  forn(i,pf){
    ll x; cin>>x; x--;
    while(SZ(stackp) and stackp.back()!=x){
      ans++;
      pin[stackp.back()]=false;
      isunp[stackp.back()]=true;
      stackp.pop_back();
    }
    if(SZ(stackp) and stackp.back()==x) stackp.pop_back();
    if(!pin[x]) ans++;
    pin[x]=true;
  }
  // DBG(ans);
  vi final;
  forn(i,uf){ll x; cin>>x; x--; final.pb(x);} reverse(all(final));
  forn(i,uf){
    ll x=final[i];
    while(SZ(stacku) and stacku.back()!=x){
      if(!pin[stacku.back()]){
        ans+=2;
        isunp[stacku.back()]=true;
      }
      stacku.pop_back();
    }
    if(SZ(stacku) and stacku.back()==x) stacku.pop_back();
    if(pin[x]) ans++;
    pin[x]=false;
  }
  cout<<ans<<'\n';

  return 0; 
}