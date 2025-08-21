#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v), end(v)
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=================================\n"

int main() {
  FIN;
  ll n; cin>>n;
  vi lisa(n),lisb(n);
  vi posa(n),posb(n);
  forn(i,n){
    cin>>lisa[i];
    posa[--lisa[i]]=i;
  }
  forn(i,n){
    cin>>lisb[i];
    posb[--lisb[i]]=i;
  }
  vector<vi> inicios(n,vi());
  forn(i,n){
    vb visto(n,false);
    visto[lisa[i]]=true;
    // DBG(i);
    ll turnb=1;
    forn(i,n-2){
      if(turnb){
        ll plisa=0; while(visto[lisa[plisa]]) plisa++;
        ll pprev=lisa[plisa];
        ll priprev=posb[pprev];
        plisa++;
        bool endturn=false;
        while(plisa < n){
          while(plisa<n and visto[lisa[plisa]]) plisa++;
          if(plisa==n) break;
          ll pact=lisa[plisa];
          ll priact=posb[pact];
          // DBG(pact);
          // DBG(pprev);
          // DBG(priact);
          // DBG(priprev);
          if(priact < priprev){visto[pprev]=true; endturn=true;}
          if(endturn) break;
          pprev=pact; priprev=priact;
          plisa++;
        }
        if(!endturn){
          ll plisb=n-1; while(visto[lisb[plisb]]) plisb--;
          visto[lisb[plisb]]=true;
          // DBG(lisb[plisb]);
        }
      }else{
        ll plisb=0; while(visto[lisb[plisb]]) plisb++;
        ll pprev=lisb[plisb];
        ll priprev=posa[pprev];
        plisb++;
        bool endturn=false;
        while(plisb < n){
          while(plisb<n and visto[lisb[plisb]]) plisb++;
          if(plisb==n) break;
          ll pact=lisb[plisb];
          ll priact=posa[pact];
          // DBG(pact);
          // DBG(pprev);
          // DBG(priact);
          // DBG(priprev);
          if(priact < priprev){visto[pprev]=true; endturn=true;}
          if(endturn) break;
          pprev=pact; priprev=priact;
          plisb++;
        }
        if(!endturn){
          ll plisa=n-1; while(visto[lisa[plisa]]) plisa--;
          visto[lisa[plisa]]=true;
          // DBG(lisa[plisa]);
        }
      }
      turnb^=1;
    }
    ll ans=0; while(visto[ans]) ans++;
    // DBG(ans);
    inicios[ans].pb(lisa[i]);
  }
  ll chosen=0;
  while(SZ(inicios[lisa[chosen]])==0) chosen++;
  chosen=lisa[chosen];
  cout<<chosen+1<<"\n";
  sort(all(inicios[chosen]));
  cout<<SZ(inicios[chosen])<<"\n";
  for(auto u:inicios[chosen]) cout<<u+1<<" "; cout<<"\n";
  return 0; 
}
