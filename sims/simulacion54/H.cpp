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
#define RAYA cerr << "==========================\n"
#define DBGV(v,n) cerr << #v << " = "; forn(_,n) cerr << v[_] << ' '


int main() {
  FIN;
  int n, t; cin >> n >> t;
  vector <ii> v(n);
  forn(i,n) cin >> v[i].first >> v[i].second;
  sort(all(v));
  int j=0, a=0;
  multiset <int> s;
  while(j<n or SZ(s)!=0){
    while(j<n and v[j].first<=a){
      s.insert(v[j].second);
      j++;
    }
    DBG(j);
    if(SZ(s)==0){
      cout << "no\n";
      return 0;
    }
    int k=*s.begin();
    if(k<a+t){
      cout << "noo\n";
      return 0;
    }
    s.erase(s.find(k));
  }
  cout << "yes\n";
  return 0;
}