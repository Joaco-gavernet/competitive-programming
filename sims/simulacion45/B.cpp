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
#define all(v) (v).begin(), (v).end()
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===========================\n"
#define DBG(x) cerr << #x << " = " << x << endl
#define DBGV(v,n) cerr << #v << " = "; forn(_,n) cerr << v[_] << ' '; cerr << '\n'

vi tsort(vector<vi> &g, int n){
  vi r; priority_queue<ll> q;
  vi d(2*n);
  forn(i,n) for(ll j:g[i]) d[j]++;
  forn(i,n) if(!d[i]) q.push(-i);
  // RAYA;
  while(!q.empty()){
    ll x=-q.top(); q.pop(); r.pb(x);
    // DBG(x);
    for(ll j: g[x]){
      d[j]--;
      if(!d[j]) q.push(-j);
    }
    // DBG(x);
  }
  return r;
}

int main() {
  FIN;
  ll n; cin>>n;
  vector<vi> gi(n),go(n);
  vi minutes(n);
  ll maxi=0;
  // RAYA;
  forn(i,n){
    cin>>minutes[i];
    maxi=max(maxi,minutes[i]);
    ll d; cin>>d;
    while(d--){
      ll aux; cin>>aux;
      aux--;
      gi[i].pb(aux);
      go[aux].pb(i);
    }
  }
  // RAYA;
  vi orden=tsort(gi,n);
  // RAYA;
  // reverse(all(orden));
  ll m=maxi;
  ll l=-1,r=(n+m),med=(l+r)/2;
  while(l+1<r){
    // DBG(med);
    // vi vals(n); forn(i,n) vals[i]=med-minutes[i];
    // forn(i,n) DBG(med-minutes[i]); cout<<endl;
    vi atend(n+m+5,0);
    vi dp(n,1e6); forn(i,n) dp[i]=med-minutes[i];
    vi pref(n+m+5,0);
    bool fail=false;
    forn(i,n){
      ll pos=orden[i];
      for(auto u:go[pos]) dp[pos]=min(dp[pos],dp[u]-1);
      // atend[pos]=med-minutes[pos]-dp[pos];
      atend[pos]=dp[pos];
      if(atend[pos]<0){
        fail=true;
        l=med;
        // DBG(atend[pos]); DBG(pos); DBG(minutes[i]);
      }else pref[atend[pos]]++;
      // dp[pos]++;
    }
    // DBGV(dp,n); cout<<endl;
    ll pre=0;
    if(!fail) forn(i,n+m+5){
      if(i>0) pref[i]+=pre;
      // DBG(pref[i]);
      if(pref[i]>(i+1)){
        l=med; fail=true;
        // DBG(i);
        break;
      }
      pre=pref[i];
      // DBG(pre);
    }
    if(!fail){
      r=med;
      // DBG(r);
    }
    med=(l+r)/2;
  }
  cout<<r<<"\n";
  return 0;
}
