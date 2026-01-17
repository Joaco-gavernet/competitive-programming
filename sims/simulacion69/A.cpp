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
#define RAYA cerr << "===========================\n"
#define DBGV(v)  for(auto u:v) cerr<<u<<" "

// const ll MAXN = 1e6;

int main() {
  FIN;
  ll n; cin>>n;
  ll tot=0;
  vi sumasync,eqasync;
  ll firsteq=n+1;
  vector<pair<ii,bool>> ops(n);
  // RAYA;
  forn(i,n){
    char c; string s; ll x;
    cin>>c>>x>>s;
    tot+=x; 
    if(c=='+') ops[i].ff.ff=1;
    else firsteq=min(firsteq,i);
    ops[i].ff.ss=x;
    if(s[0]=='a'){
      ops[i].ss=true;
    }else ops[i].ss=false;
  }
  vi knapsack(tot+1,0);
  // knapsack[0]=1;
  ll cont=0;
  vi extras;
  // RAYA;
  if(firsteq>n){
    cout<<"1\n";
    return 0;
  }
  bool detras=false;
  for(ll i=n-1;i>=0;i--){
    if(ops[i].ff.ff==0){
      if(!detras){
        knapsack[ops[i].ff.ss+cont]=2;
        detras=true;
      }else if(ops[i].ss==true){
        knapsack[ops[i].ff.ss]=2;
      }
    }
    else{
      if(!detras){
        cont+=ops[i].ff.ss;
        extras.pb(cont);
      }else if(ops[i].ss==true){
        sumasync.pb(ops[i].ff.ss);
      }
      
    }
  }
  DBGV(sumasync); cerr<<endl;
  
  for(auto u:eqasync){
    // knapsack[u]=2;
    for(auto v:extras) knapsack[u+v]=2;
  }
  for(auto u:sumasync) for(ll pos=tot+1;pos>=u;pos--){
    if(knapsack[pos-u]) knapsack[pos]=2;
  }
  // for(auto u:eqasync) for(ll pos=tot+1;pos>u;pos--){
  //   if(knapsack[pos-u]) knapsack[pos]=1;
  // }

  ll ans=0;
  forr(i,1,tot+1){
    if(knapsack[i]==2){
      ans++;
      DBG(i);
    }
  }
  cout<<ans<<"\n";
  return 0;
}