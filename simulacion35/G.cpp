#include <bits/stdc++.h> 
using namespace std; 


typedef long long ll; 
typedef vector<ll> vi; 
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++) 
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define SZ(x) int((x).size())
#define esta(v,x) (v).find(x) != (v).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define DBGV(v,n) forn(i,n) cerr << v[i] << ' '
#define RAYA cerr << "================================\n"

vi seq; 
ll ans = 0; 
void f(int a, int b, ll mini, ll maxi) {
  if (b < a) return; 
  int mid = (b+a)/2; 
  // cerr << a << ' ' << b << endl; 
  // DBG(seq[mid]); 
  // cerr << mini << ' ' << maxi << endl; 
  if (mini < seq[mid] and seq[mid] < maxi) ans++; 
  f(a, mid-1, mini, min(seq[mid], maxi)); 
  f(mid+1, b, max(seq[mid], mini), maxi); 
}

int main() {
  FIN; 
  
  ll n, m, a, c, x0; 
  cin >> n >> m >> a >> c >> x0; 
  seq.pb((a*x0 +c) %m); 
  while (SZ(seq) < n) {
    seq.pb((a*(*seq.rbegin()) +c) %m); 
  }
  // DBGV(seq, SZ(seq)); cerr << endl; 
  // RAYA; 

  f(0,n-1,-1,m); 
  cout << ans << '\n'; 


  return 0; 
}
