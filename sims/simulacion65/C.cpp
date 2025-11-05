#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << '\n'
#define RAYA cerr << "==============================\n"

const ll INF=1e18;

int main() {
  FIN;
  int n,m,k; cin>>n>>m>>k;
  vector<ii> ladoa(n); vector<ii> ladob(m);
  forn(i,n) cin>>ladoa[i].ff, ladoa[i].ss=i;
  forn(i,m) cin>>ladob[i].ff, ladob[i].ss=i;
  sort(all(ladoa)); sort(all(ladob));
  ll tot=n+m;
  ll base=0;
  ll l=-1,r=1e10;
  ll med=(l+r)/2;
  vector<pair<ll,ii>> ans;
  while(l+1<r){
    //DBG(med);
    vector<pair<ll,ii>> aux;
    ll iz=0;
    ll pua=0,pub=0;
    ll tbase=med;
    ll remn=n,remm=m;
    //bool ina=true;
    while(remn>remm){
      if(ladoa[pua].ff<=tbase){  
        iz++; aux.pb({tbase,{0,ladoa[pua].ss+1}});
      }else break;
      tbase+=k;
      pua++;
      remn--;
      if(pub<m and ladob[pub].ff<=tbase){  
        iz++; aux.pb({tbase,{1,ladob[pub].ss+1}}); pub++; remm--; 
      }
      if(remn>0) tbase+=k;
      //if(remn>remm) tbase+=k;
    }
    while(remn<remm){
      if(ladob[pub].ff<=tbase){
        iz++; aux.pb({tbase,{1,ladob[pub].ss+1}});
      }else break;
      tbase+=k;
      pub++;
      remm--;
      if(pua<n and ladoa[pua].ff<=tbase){  
        iz++; aux.pb({tbase,{0,ladoa[pua].ss+1}}); pua++; remn--;
      }
      if(remm>0) tbase+=k;
    }
    //Caso igual
    ll c1=0,c2=0;
    ll pua1=pua,pua2=pua,pub1=pub,pub2=pub;
    vector<pair<ll,ii>> aux1,aux2;
    ll tbase1=tbase,tbase2=tbase;
    while(remn==remm and remn>0){
      if(n>m){
        if(ladoa[pua].ff<=tbase){
          iz++; aux.pb({tbase,{0,ladoa[pua].ss+1}}); pua++;
        }
        remn--;
        tbase+=k;
        if(ladob[pub].ff<=tbase){
          iz++; aux.pb({tbase,{1,ladob[pub].ss+1}}); pub++;
        }
        remm--;
        tbase+=k;
      }else if(n<m){
        if(ladob[pub].ff<=tbase){
          iz++; aux.pb({tbase,{1,ladob[pub].ss+1}}); pub++;
        }
        remm--;
        tbase+=k;
        if(ladoa[pua].ff<=tbase){
          iz++; aux.pb({tbase,{0,ladoa[pua].ss+1}}); pua++;
        }
        remn--;
        tbase+=k;
      }else{
        // Primero
        if(ladoa[pua1].ff<=tbase1){
          c1++; aux1.pb({tbase1,{0,ladoa[pua1].ss+1}}); pua1++;
        }
        tbase1+=k;
        if(ladob[pub1].ff<=tbase1){
          c1++; aux1.pb({tbase1,{1,ladob[pub1].ss+1}}); pub1++;
        }
        tbase1+=k;
        
        // Segundo
        if(ladob[pub2].ff<=tbase2){
          c2++; aux2.pb({tbase2,{1,ladob[pub2].ss+1}}); pub2++;
        }
        tbase2+=k;
        if(ladoa[pua2].ff<=tbase2){
          c2++; aux2.pb({tbase2,{0,ladoa[pua2].ss+1}}); pua2++;
        }
        tbase2+=k;

        remn--; remm--;
        //if(remn>0) tbase1-=k, tbase2-=k;
        //DBG(c1); DBG(c2);

        //compare
        if(c1==tot){
          tbase=tbase1;
          aux=aux1;
          iz=c1;
        }else if(c2==tot){
          tbase=tbase2;
          aux=aux2;
          iz=c2;
        }
        
      }
      
    }
    if(iz==tot){
      r=med;
      base=tbase;
      ans=aux;
    }
    else l=med;
    med=(l+r)/2;
  }
  cout<<base<<"\n";
  for(auto u:ans) cout<<u.ff<<" "<<u.ss.ff<<" "<<u.ss.ss<<"\n";
  return 0;
}