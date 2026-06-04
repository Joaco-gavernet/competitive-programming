#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size()) 
#define all(v) begin(v),end(v)
#define DBG(x) cerr << #x << " = " << endl
#define RAYA cerr << "================================\n"
#define ff first
#define ss second 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
vi v;
ll k;

struct querie{
  ll m,s,t;
  bool operator < (querie q) const {return m<q.m;}
};

ll solve(ll l, ll r){
  if(l>r) return 0;
  if(l==r){
    if(v[l]==0) return 1;
    else return 0;
  }
  ll med=(r+l)/2;
  ll ans=0;
  ll sum=0, maxi=0;
  vector <querie> q;
  for(int i=med; i>=l; i--){
    sum+=v[i];
    maxi=max(maxi,v[i]);
    q.pb({maxi,sum,0});
  }
  sum=0; maxi=0;
  forr(i,med+1,r+1){
    sum+=v[i];
    maxi=max(maxi,v[i]);
    q.pb({maxi,sum,1});
  }
  sort(all(q));
  indexed_set ss[2];
  ll i=0;
  for(auto [m,s,t] : q){
    auto it=ss[1-t].lower_bound({(k+1)*m-s,-1});
    if(it!=ss[1-t].end()) ans+=SZ(ss[1-t])-ss[1-t].order_of_key(*it);
    ss[t].insert({s,i});
    i++;
  }
  ans+=solve(l,med)+solve(med+1,r);
  return ans;
}

int main() {
  FIN;
  ll n;
  cin >> n >> k;
  vi a(n), h(n);
  forn(i,n) cin >> h[i];
  forn(i,n) cin >> a[i];
  forn(i,n){
    if(h[i]>=a[i]) v.pb(h[i]-a[i]);
    else v.pb(-k*(a[i]-h[i]));
  }
  cout << solve(0,n-1) << "\n";
  return 0; 
} 
