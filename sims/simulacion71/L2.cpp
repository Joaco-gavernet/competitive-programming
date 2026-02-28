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
  ll cap=k;
  ll cost=-1;
  while(SZ(stack1) or SZ(stack2)){
    // DBG(cap);
    // DBG(cost);
    if(cap==0){
      cap=k;
      ans+=cost;
      cost=-1; 
    }
    // DBG(ans);

    if(SZ(stack1) and SZ(stack2)){
      if(stack1.back().ff > stack2.back().ff or cap==1){
        ll completo=(stack1.back().ss / k);
        ans+=(stack1.back().ff * completo);
        (*(--stack1.end())).ss-=(completo*k);
        if(stack1.back().ss == 0){stack1.pop_back(); continue;}
        
        if(cost==-1) cost=stack1.back().ff;
        ll cant=min(cap,stack1.back().ss);
        cap-=cant;
        if(cant==stack1.back().ss) stack1.pop_back();
        else (*(--stack1.end())).ss-=cant;
      }else{
        ll completo=(stack2.back().ss / (k/2));
        ans+=(stack2.back().ff * completo);
        (*(--stack2.end())).ss-=(completo*k);
        if(k%2 == 1 and SZ(stack1)){
          (*(--stack1.end())).ss--;
          if(stack1.back().ss == 0){stack1.pop_back();}
        }
        if(stack2.back().ss == 0){stack2.pop_back(); continue;}

        if(cost==-1) cost=stack2.back().ff;
        ll cant=min(cap/2,stack2.back().ss);
        cap-=(2*cant);
        if(cant==stack2.back().ss) stack2.pop_back();
        else (*(--stack2.end())).ss-=cant;
      }
    }else if(SZ(stack1)){
      ll completo=(stack1.back().ss / k);
      ans+=(stack1.back().ff * completo);
      (*(--stack1.end())).ss-=(completo*k);
      if(stack1.back().ss == 0){stack1.pop_back(); continue;}

      if(cost==-1) cost=stack1.back().ff;
      ll cant=min(cap,stack1.back().ss);
      cap-=cant;
      if(cant==stack1.back().ss) stack1.pop_back();
      else (*(--stack1.end())).ss-=cant;
    }else{
      ll completo=(stack2.back().ss / (k/2));
      ans+=(stack2.back().ff * completo);
      (*(--stack2.end())).ss-=(completo*k);
      if(stack2.back().ss == 0){stack2.pop_back(); continue;}

      if(cost==-1) cost=stack2.back().ff;
      ll cant=min(cap/2,stack2.back().ss);
      cap-=(2*cant);
      if(cant==stack2.back().ss) stack2.pop_back();
      else (*(--stack2.end())).ss-=cant;
    }
  }
  if(cost>-1) ans+=cost;
  cout<<ans<<"\n";
}

int main() {
  NaN;
  ll t; cin>>t;
  while(t--) solve();
  return 0;
}