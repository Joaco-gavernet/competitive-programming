#include <bits/stdc++.h> 
using namespace std; 


typedef long long ll; 
typedef vector<ll> vi; 
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++) 
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define SZ(x) int((x).size())
#define esta(v,x) (v).find(x) != (v).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "================================\n"

struct distancia{
  int j,b;
  ll d;
  bool operator <(distancia x) const{
    if(d==x.d){
      if(j==x.j){
	return b<x.b;
      }else return j<x.j;
    } else return d<x.d;
  }
};

int main() {
  FIN; 
  int n,m,p; cin>>n>>m>>p;
  vector<bool> vistoj(n,false),vistot(m,false),vistof(p,false);
  vector<ii> juez(n),tar(m),feather(p);
  forn(i,n) cin>>juez[i].first>>juez[i].second;
  forn(i,m) cin>>tar[i].first>>tar[i].second;
  forn(i,p) cin>>feather[i].first>>feather[i].second;
  set<distancia> distar,disfe;
  forn(i,n){
    forn(j,m){
      distancia aux;
      aux.j=i; aux.b=j;
      ll difh,difv;
      difh=juez[i].first-tar[j].first;
      difv=juez[i].second-tar[j].second;
      aux.d=difh*difh+difv*difv;
      distar.insert(aux);
    }
    forn(j,p){
      distancia aux;
      aux.j=i; aux.b=j;
      ll difh,difv;
      difh=juez[i].first-feather[j].first;
      difv=juez[i].second-feather[j].second;
      aux.d=difh*difh+difv*difv;
      disfe.insert(aux);
    }
  }
  long double ans=0;
  for(auto u:distar){
    //~ cout<<u.d<<endl;
    if(!vistoj[u.j] and !vistot[u.b]){
      vistoj[u.j]=true; vistot[u.b]=true;
      //~ cout<<u.j<<" "<<u.b<<endl;
      ans+=sqrtl(u.d);
    }
  }
  //~ cout<<ans<<endl;
  forn(i,n) vistoj[i]=false;
  for(auto u:disfe){
    //~ cout<<u.d<<endl;
    if(!vistoj[u.j]and!vistof[u.b]){
      vistoj[u.j]=true; vistof[u.b]=true;
      //~ cout<<u.j<<" "<<u.b<<endl;
      ans+=sqrtl(u.d);
    }
  }
  cout<<fixed<<setprecision(9);
  cout<<ans<<"\n";
  return 0; 
}
