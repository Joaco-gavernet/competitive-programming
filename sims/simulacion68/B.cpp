#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb; 
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=========================\n"
#define all(v) begin(v),end(v)


int main() {
  FIN;
  int n, H, W; cin >> n >> H >> W; 
  vii book(n);
  vector<pair<ii,ll>> book2(n);
  forn(i,n) cin >> book[i].ff >> book[i].ss;
  forn(i,n){
    book2[i].ff=book[i];
    book2[i].ss=i;
  }
  sort(all(book));
  sort(all(book2));
  vi corresp(n);
  forn(i,n){
    corresp[i]=book2[i].ss+1;
  }
  forn(i,n) {
    // fixing i-th book as base for the stack 
    vb isupr(n,false);
    vi upright,stacked,indecise;
    ll ancho=W-book[i].ff;
    ll alto=H-book[i].ss;
    ll sum=0;
    forn(x,i){
      if(book[x].ff > H){
        stacked.pb(x);
        alto-=book[x].ss;
      }else{
        indecise.pb(x);
        sum+=book[x].ss;
      }
    }
    if(book[i].ff >= W) continue;
    stacked.pb(i);
    bool todook=true;
    forr(x,i+1,n){
      if (book[x].ff > book[i].ff) {
        if(book[x].ff > H) todook=false;
        ancho-=(book[x].ss);
        if(ancho<0) todook=false; 
        upright.pb(x); isupr[x]=true;
      } else{
        if(book[x].ff > H){
          stacked.pb(x);
          alto-=book[x].ss;
        }else{
          indecise.pb(x);
          sum+=book[x].ss;
        }
      }
    }
    if(alto<0 or ancho<0) todook=false;
    if(!todook) continue;

    // knapsack to check if possible
    ll minancho=sum-alto;
    if(minancho>ancho) continue;
    vii knap(ancho+1,{-1,-1});
    ll tam=SZ(indecise);
    forn(i,tam){
      ll b=indecise[i];
      ll an=book[b].ss;
      for(ll ind=ancho;ind>=an;ind--) if((knap[ind].ss==-1)and(ind==an or knap[ind-an].ss!=-1)) knap[ind]={ind-an,b};
    }
    // RAYA;
    forr(ans,max(minancho,(ll)0),ancho+1){
        if(knap[ans].ff!=-1){
        ll punt=ans;
        upright.pb(knap[punt].ss); isupr[knap[punt].ss]=true;
        while(knap[punt].ff!=0){
          punt=knap[punt].ff;
          upright.pb(knap[punt].ss); isupr[knap[punt].ss]=true;
        }
        for(auto u:indecise) if(!isupr[u]) stacked.pb(u);

        vii pila;
        for(auto u:stacked) pila.pb({book[u].ff,u});
        sort(all(pila));
        reverse(all(pila));

        cout<<"upright ";
        for(auto u:upright) cout<<corresp[u]<<" ";
        cout<<"\n";
        cout<<"stacked ";
        for(auto u:pila) cout<<corresp[u.ss]<<" ";
        cout<<"\n";
        return 0;
      }
    }
    if(SZ(upright) and sum<=alto){
      for(auto u:indecise) if(!isupr[u]) stacked.pb(u);
      vii pila;
      for(auto u:stacked) pila.pb({book[u].ff,u});
      sort(all(pila));
      reverse(all(pila));

      cout<<"upright ";
      for(auto u:upright) cout<<corresp[u]<<" ";
      cout<<"\n";
      cout<<"stacked ";
      for(auto u:pila) cout<<corresp[u.ss]<<" ";
      cout<<"\n";
      return 0;
    }
    // RAYA;
    
    
  }

  cout<<"impossible\n";
  return 0;
}