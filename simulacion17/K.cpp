#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i< (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) (v).begin(),(v).end()
#define fs first
#define ss second
#define DBG(c) cerr << #c << " = " << c << endl
#define RAYA cerr << "===================\n"

const int MAXN = 1e5+5;
const int INF = -1;
const int MOD = -1;

vector<set<int>> g(MAXN);
vector<bool> visto(MAXN,false);
vector<bool> seusa(MAXN,false);

void cans(bool s){
  if(!s) cout<<"im";
  cout<<"possible\n";
}

int k;

bool ciclo=false;

bool dfs(int v,int padre){
  //cout<<v<<endl;
  visto[v]=true;
  //int grado=SZ(g[v]);
  int cont=0;
  for(auto u:g[v]) if(SZ(g[u])>1) cont++;
  if(cont>2) return false;
  for(auto u:g[v])if(u!=padre){
    if(visto[u]){
      //~ if(c){ cout<<"Encontro ciclo cuando ya habia mas de una componente \n"; return false;}
      //~ c=true;
      //~ forn(i,k){
	//~ if(seusa[i] and !visto[i]) {cout<<v<<"  "<<u<<""<<padre<<" Hay ciclo pero no estan todos\n"; return false;}
      //~ }
      //~ return true;
      ciclo=true;
    }else{
      //int gr=SZ(g[u])-1; if(gr>0){cont++;}
      //if(grado>=3 and cont>2){cout<<"+2 nodos hijos tienen grado 1 \n"; return false;}
      //else{
	dfs(u,v);
      //}
    }
  }
  return true;
}


int main() {
  FIN;
  int n; cin>>n>>k;
  forn(i,n){
    int a,b; cin>>a>>b; a--; b--;
    seusa[a]=true; seusa[b]=true;
    if(a!=b) {g[a].insert(b); g[b].insert(a);}
  }
  bool ans=true;
  bool hay=false;
  forn(i,k){
    if(!ans) break;
    if(!visto[i] and seusa[i]){
      ans=ans and dfs(i,-1);
      if(ciclo and hay) ans=false;
      if(ciclo){
	forn(j,k) if(!visto[j] and seusa[j]) ans=false;
      } 
      hay=true;
    }
    
  }
  if(ans){cout<<"possible\n";}else{cout<<"impossible\n";}
  //cans(ans);
  return 0;
}
