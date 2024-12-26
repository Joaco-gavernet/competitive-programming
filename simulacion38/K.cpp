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
#define RAYA cerr << "=================================\n"

const int INF=1e9+7;

int main() {
  FIN; 
  int n,e; cin>>n>>e;
  vector<string> cadenas(n);
  vi ans(e,0);
  vi tam(n);
  //~ DBG(n);
  forn(i,n){
    string aux; cin>>aux;
    cadenas[i]=aux;
    tam[i]=SZ(aux);
    bool loop=true;
    int cont=1;
    forn(j,SZ(aux)-1){
      if(aux[j]!=aux[j+1]) {
	loop=false;
	break;
      }
      cont++;
    }
    if(loop) ans[aux[0]-'a']=INF;
    else ans[aux[0]-'a']+=cont;
  }
  ll rfin=INF,lfin=INF;
  forn(i,e){
    if(ans[i]<rfin){
      rfin=ans[i];
      lfin=i;
      //~ DBG(ans[i]);
    }
  }
  if(rfin<INF){
    char c='a'+lfin;
    forn(i,rfin+1) cout<<c;
    cout<<"\n";
  }else cout<<"NO\n";
  return 0; 
}


