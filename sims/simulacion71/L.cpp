#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
#define NaN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define pb push_back
#define all(v) begin(v),end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "============================\n"
#define ff first
#define ss second

void updstack(vii &stack, ll &cost, ll &cap, ll w){
  if(cost==-1) cost=stack.back().ff;
  ll cant=min(cap/w,stack.back().ss);
  cap-=(w*cant);
  if(cant==stack.back().ss) stack.pop_back();
  else (*(--stack.end())).ss-=cant;
}

void solve(){
  ll n,k; cin>>n>>k;
  ll ans=0;
  unordered_map<ll,ll> peso1,peso2;
  forn(i,n){
    ll c,w,f; cin>>c>>w>>f;
    if(w==1) peso1[f]+=c;
    else peso2[f]+=c;
  }
  vii stack1,stack2;
  for (auto u:peso1) stack1.pb({u.ff,u.ss});
  for (auto u:peso2) stack2.pb({u.ff,u.ss});
  sort(all(stack1));
  sort(all(stack2));

  vii auxi;
  for(auto u:stack2){
    ll completo=( u.ss / (k/2));
    ans+=(u.ff * completo);
    u.ss-=(completo*(k/2));
    if(u.ss !=0) auxi.pb({u.ff,u.ss});
  }
  stack2=auxi;
  auxi.clear();
  for(auto u:stack1){
    ll completo=(u.ss / k);
    ans+=(u.ff * completo);
    u.ss-=(completo*k);
    if(u.ss !=0) auxi.pb({u.ff,u.ss});
  }
  stack1=auxi;

  ll cap=k;
  ll cost=-1;
  while(SZ(stack1) or SZ(stack2)){
    if(cap==0 or (cap==1 and SZ(stack1)==0)){
      cap=k; ans+=cost; cost=-1; 
    }
    if(SZ(stack1) and SZ(stack2)){
      if(stack1.back().ff > stack2.back().ff or cap==1) updstack(stack1,cost,cap,1);
      else updstack(stack2,cost,cap,2);
    }else if(SZ(stack1)) updstack(stack1,cost,cap,1);
    else updstack(stack2,cost,cap,2);
  }
  if(cost>-1) ans+=cost;
  cout<<ans<<"\n";
  return;
}

int main() {
  NaN;
  ll t; cin>>t;
  while(t--) solve();
  return 0;
}