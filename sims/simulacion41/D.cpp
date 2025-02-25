#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi; 
typedef pair<ll,ll> ii; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define all(v) (v).begin(),(v).end()
#define esta(x,v) (v).find(x) != (v).end() 
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==================================\n"

//~ const ll INFN=1;
const ll INF=1e9+7;

int main() {
  FIN; 
  ll n; cin>>n;
  vector<ii> towers(n); 
  forn(i,n){
    cin>>towers[i].first;
    towers[i].second=i;
  }
  sort(all(towers));
  set<ll> towizq,towder;
  towizq.insert(INF); towder.insert(INF);
  ll ans=0;
  towizq.insert(-towers[n-1].second);
  towder.insert(towers[n-1].second);
  forn(i,n-1){
    ll num=towers[n-2-i].second;
    ll d1=*(towizq.lower_bound(-num));
    ll d2=*(towder.lower_bound(num));
    d1*=-1;
    ans+=min(num-d1,d2-num);
    towizq.insert(-num);
    towder.insert(num);
  }
  cout<<ans<<"\n";
  return 0; 
} 
