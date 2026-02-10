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
#define RAYA cerr << "==================================\n"


int main() {
  FIN;
  ll n,d; cin>>n>>d;
  vi histo(n,0);
  vector<vi> oc(n,vi());
  forn(i,n){
    ll x; cin>>x;
    histo[x]++;
    oc[x].pb(i+1);
  }
  forn(i,n){
    if(histo[i]<=1){cout<<i<<"\n"; return 0;}
    //RAYA;
    vector<ii> interv;
    ll in=-1;
    ll prev=-1;
    bool pos=true;
    for(auto u:oc[i]){
      if(in==-1){
        in=u;
        prev=u;
      }else if(u-prev<d){
        prev=u;
      }else{
        if(prev-in >= d){pos=false; break;}
        else interv.pb({in,prev}); 
        //DBG(in); DBG(prev);
        in=u; prev=u;
      }
    }
    if(prev-in >= d) pos=false; 
    else interv.pb({in,prev}); 
    if(!pos) continue;
    //RAYA;
    if(SZ(interv)==1){cout<<i<<"\n"; return 0;}
    //DBG(interv[0].ss); DBG(interv[1].ss); DBG(interv[2].ss); DBG(interv[3].ss); DBG(interv[4].ss); DBG(interv[5].ss); 
    ll final=max(interv[0].ss,d);
    forr(j,1,SZ(interv)){
      //DBG(final);
      //DBG(interv[j].ff);
      if(final+d >= interv[j].ff){pos=false; break;}
      final=max(interv[j].ss,final+d+d);
    }
    if(pos){cout<<i<<"\n"; return 0;}
  }
  return 0; 
}
