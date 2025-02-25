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

void solve(){
  int n; cin>>n;
  vector<ii> mounts(n);
  forn(i,n) cin>>mounts[i].first;
  forn(i,n) cin>>mounts[i].second;
  sort(all(mounts));
  ll cont=0;
  forn(i,n){
    if(mounts[i].second-mounts[i].first-cont < 0){
      cout<<-1<<"\n";
      return;
    }else cont+=(mounts[i].second-mounts[i].first-cont);
  }
  cout<<cont<<"\n";
  return;
}

int main() {
  FIN; 
  int t; cin>>t;
  forn(i,t) solve();
  return 0; 
}


