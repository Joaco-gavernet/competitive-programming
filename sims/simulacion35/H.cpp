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
#define RAYA cerr << "================================\n"
#define f(k) (a*b*k -2*a*k*k -2*b*k*k +4*k*k*k) 

int main() {
  FIN; 
  
  int a, b, c, d, e, f, g; 
  cin >> a >> b >> c >> d >> e >> f >> g; 
  vi st; 
  for (ll k = 1; 2*k < a; k++) st.pb(f(k)); 
  sort(all(st)); 
  ll v1 = st[SZ(st)-1]; 
  ll v2 = st[SZ(st)-2]; 
  ll v3 = st[SZ(st)-3]; 

  int r = -1; 
  forn(i,v2) {
    if ((i*v1 +c) %v2 == d) {
      r = (i*v1 +c); 
      break; 
    }
  }
  ll q = v1*v2/__gcd(v1,v2);

  forn(i,v3) {
    if ((i*q +r) %v3 == e) {
      r = (i*q +r); 
      break; 
    }
  }
  ll m = q*v3/__gcd(q,v3); 

  ll p = (f -r +m -1) /m; 
  cout << p*m +r << '\n'; 


  return 0; 
}
