#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"

int main() {
  FIN;
  ll n, p, q, s; cin >> n >> p >> q >> s;
  vi x(p), y(q);
  forn(i,p) cin >> x[i];
  forn(i,q) cin >> y[i];
  sort(all(x)); sort(all(y));
  set <ii> v;
  forn(i,q) v.insert({y[i],i});
  ll l=-1, r=s+1;
  while(r-l>1){
    ll med=(r+l)/2;
    vi a(q), b(q+1);
    ll tot=0;
    RAYA; DBG(med);
    forn(i,p){
      if(x[i]-med>s-x[i]) continue;
      auto it=v.lower_bound({x[i]-med,0}), it2=v.lower_bound({min(s-x[i],x[i]+med)+1,0});
      if(it==v.end() or it2==it) continue;
      cout << (*it).ss << " ";
      a[(*it).ss]++;
      if(it2!=v.end()) {cout << (*it2).ss; b[(*it2).ss]++;}
      else cout << q;
      cout << endl;
    }
    ll cola=0, match=0;
    forn(i,q){
      cola+=a[i];
      cola-=max(0LL,b[i]-match);
      match-=min(match,b[i]);
      if(cola>0){tot++;match++;cola--;}
    }
    DBG(tot);
    if(tot<n) l=med;
    else r=med;
  }
  if(r==s+1) cout << "-1\n";
  else cout << r << "\n";
  return 0;
}