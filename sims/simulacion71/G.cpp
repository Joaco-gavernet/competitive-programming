#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
#define NaN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define pb push_back
#define ff first
#define ss second
#define all(v) begin(v),end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "============================\n"



int main() {
  NaN;
  ll n,w,k; cin>>n>>w>>k;
  vi knap(w+1,0);
  vi extras(k+1,0);
  vii joyas(n);
  forn(i,n) cin>>joyas[i].ff>>joyas[i].ss;
  sort(all(joyas));
  forn(i,n){
    for(ll pos=k;pos>0;pos--){
      if(pos==1) extras[pos]=max(extras[pos],joyas[i].ss);
      else if(extras[pos-1]!=0) extras[pos]=max(extras[pos],extras[pos-1]+joyas[i].ss);
    }
    for(ll pos=w;pos>0;pos--){
      if(joyas[i].ff + pos > w){if(k>0) extras[1]=max(extras[1],knap[pos]+joyas[i].ss);}
      else knap[joyas[i].ff+pos]=max(knap[joyas[i].ff+pos],knap[pos]+joyas[i].ss);
    }
    knap[joyas[i].ff]=max(knap[joyas[i].ff],joyas[i].ss);
  }
  ll ans=0;
  forn(i,w+1) ans=max(ans,knap[i]);
  forr(i,1,k+1) ans=max(ans,extras[i]);
  cout<<ans<<"\n";
  return 0;
}