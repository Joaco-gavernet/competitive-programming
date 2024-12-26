#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++) 
#define forn(i,n) forr(i,0,n) 
#define pb push_back
#define esta(x,v) ((v).find(x) != (v).end()) 
#define SZ(x) int((x).size())
#define all(v) (v).begin(),(v).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define DBGV(v,n) forn(i,n) cerr << v[i] << ' '
#define RAYA cerr << "=================================\n"

const int INF=1e9+7;


void solve(){
  int n; cin>>n;
  vi servers(n); 
  int min=INF,posmin=-1;
  int dif=0;
  forn(i,n){
    cin>>servers[i];
    if(min>servers[i]){
      posmin=i;
      min=servers[i];
    }
  }
  forn(i,n){
    //~ cin>>servers[i];
      dif=dif+(servers[i]-servers[(i-1+n)%n]);
      //~ DBG(dif);
  }
  if(n==2){
    if(servers[0]>servers[1]) swap(servers[0],servers[1]);
    cout<<max((ll)0,servers[0]-(servers[1]-servers[0]))<<"\n";
  }else if(dif!=0){
    cout<<0<<"\n";
  }else{
    int pos=(posmin+n-1)%n;
    while(pos!=posmin){
      int izq=servers[pos],der=servers[(pos+1+n)%n];
      dif=izq-der;
      if(dif>0){
	servers[pos]-=2*((dif+1)/2);
	servers[(pos+n-1)%n]-=(dif+1)/2;
      }
      pos=(pos+n-1)%n;
      //~ DBGV(servers,n);
      //~ cout<<endl;
    }
    cout<<max((ll)0,servers[posmin])<<"\n";
  }
  return;
}

int main() {
  FIN; 
  int t; cin>>t;
  while(t--) solve();
  return 0; 
}


