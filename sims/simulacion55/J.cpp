#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=====================================\n"

const ll MAXN = 3e4+5;

vi tam(MAXN,0);
vi grado(MAXN,0);
// vector<char> type(MAXN,'$');
vector<vi> fats(MAXN,vi());
vector<vi> sons(MAXN,vi());
ll m,n,q; 

ll solve(ll x,ll k){
  ll ans;
  // DBG(x); DBG(k);
  if(tam[x] < k) return -1;
  if(x==0) return k;
  if(SZ(fats[x])==1){
    ll p=fats[x][0];
    if(sons[p][0]==x) return solve(fats[x][0],2*k-1);
    else return solve(fats[x][0],2*k);
  }else{
    // DBG(fats[x][0]); DBG(fats[x][1]);
    ll sl=tam[fats[x][0]];
    ll sr=tam[fats[x][1]];
    // DBG(sl); DBG(sr);
    ll mins=min(sl,sr);
    // DBG(mins);
    if(k <= 2 * mins){
      if(k%2==1) return solve(fats[x][0],(k+1)/2);
      else return solve(fats[x][1],k/2);
    }else if(sl > sr) return solve(fats[x][0],k-sr);
    else return solve(fats[x][1],k-sl);
  }
}

int main() {
  FIN;
  cin>>m>>n>>q;
  tam[0]=m;
  // RAYA;
  forn(i,n){
    char c; cin>>c;
    ll x,y,z; cin>>x>>y>>z;
    x--; y--; z--;
    if(c=='S'){
      sons[x].pb(y);
      sons[x].pb(z);
      fats[y].pb(x);
      fats[z].pb(x);
      grado[y]=1;
      grado[z]=1;
    }else{
      sons[x].pb(z);
      sons[y].pb(z);
      fats[z].pb(x);
      fats[z].pb(y);
      grado[z]=2;
    }
  }
  // RAYA;
  queue<ll> prox;
  prox.push(0);
  while(SZ(prox)){
    ll u=prox.front();
    // DBG(u);
    prox.pop();
    if(SZ(sons[u])==1){
      ll hijo=sons[u][0];
      grado[hijo]--;
      if(grado[hijo]==0) prox.push(hijo);
      tam[hijo]+=tam[u];
      // DBG(n); DBG(tam[n]);
    }else if (SZ(sons[u])==2){
      ll x=sons[u][0];
      ll y=sons[u][1];
      grado[x]--; grado[y]--;
      if(grado[x]==0) prox.push(x);
      if(grado[y]==0) prox.push(y);
      tam[x]+=(tam[u]+1)/2;
      tam[y]+=tam[u]/2;
      // DBG(x); DBG(tam[x]);
      // DBG(y); DBG(tam[y]);
    }
  }
  // RAYA;
  while(q--){
    ll x,k; cin>>x>>k;
    x--;
    ll rta=solve(x,k);
    if(rta==-1) cout<<"none\n";
    else cout<<rta<<"\n";
  }

  return 0;
}
