#include <bits/stdc++.h>
using namespace std; 


typedef long long ll; 
typedef vector<ll> vi;
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define esta(v,x) (v).find(x) != (v).end()
#define SZ(x) int((x).size())
#define pb push_back
#define all(v) (v).begin(), (v).end() 
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=============================\n"
#define DBGV(v,n) forn(_,n) cerr << v[_] << ' '

const ll INF=1e9+7;

int main() {
  FIN;
  // RAYA;
  ll n; cin>>n;
  vector<ii> canvas(n); forn(i,n) cin>>canvas[i].first>>canvas[i].second;
  map<ll,bool> ispeg;
  ll p; cin>>p;
  vi pegs(p);
  forn(i,p){
    cin>>pegs[i];
    ispeg[pegs[i]]=true;
  }
  vi ans;
  vi histopc(n,0);
  ll pp=0;
  vector<ii> pendientes;
  forn(i,n){
    while(pp<p and pegs[pp]<canvas[i].second){
      if(pegs[pp]>=canvas[i].first) histopc[i]++;
      pp++;
    }
    if(pp<p and pegs[pp]==canvas[i].second) histopc[i]++;
    if(canvas[i].second==(canvas[i].first+1)){
      if(!ispeg[canvas[i].first]){
        ans.pb(canvas[i].first); 
        ispeg[canvas[i].first]=true; 
        histopc[i]++;
        if(i>0 and canvas[i-1].second==canvas[i].first) histopc[i-1]++;
      }
      if(!ispeg[canvas[i].second]){
        ans.pb(canvas[i].second); 
        ispeg[canvas[i].second]=true; 
        histopc[i]++;
        if(i<n-1 and canvas[i+1].first==canvas[i].second) histopc[i+1]++;
      }
    }else if(canvas[i].second==(canvas[i].first+2)){
      pendientes.pb({i,canvas[i].first});
    }
  }
  forn(i,SZ(pendientes)){
    ii elem=pendientes[i];
    if(!pegs[elem.second]){
      if(elem.first ==0 or histopc[elem.first-1]<2){
        histopc[elem.first]++;
        if(elem.first>0) histopc[elem.first-1]++;
        ans.pb(elem.second);
        pegs[elem.second]=true;
      }else if(!pegs[elem.second+2]){
        histopc[elem.first]++;
        if(elem.first<n-1) histopc[elem.first+1]++;
        ans.pb(elem.second+2);
        pegs[elem.second+2]=true;
      }
    }
  }
  forn(i,n) if(histopc[i]>2){cout<<"impossible\n"; return 0;}
  forn(i,n){
    ii canva=canvas[i];
    if(histopc[i]<2){
      if(!ispeg[canvas[i].second] and i<n-1 and canvas[i].second==canvas[i+1].first and histopc[i+1]<2){
        ispeg[canvas[i].second]=true;
        histopc[i]++; histopc[i+1]++;
        ans.pb(canvas[i].second);
      }
      ll cont=canvas[i].first+1;
      while(histopc[i]<2 and cont<canvas[i].second){
        if(!ispeg[cont]){
          ispeg[cont]=true;
          histopc[i]++;
          ans.pb(cont);
        }
        cont++;
      }
      if(histopc[i]<2){cout<<"impossible\n"; return 0;}
    }
  }
  sort(all(ans));
  cout<<SZ(ans)<<"\n";
  forn(i,SZ(ans)) cout<<ans[i]<<" ";
  cout<<"\n";
  return 0;
} 
