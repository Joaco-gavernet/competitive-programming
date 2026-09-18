#include <bits/stdc++.h>
using namespace std;

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

using ll = long long; 
using vi = vector<ll>; 
using vb = vector<bool>; 
using ii = pair<ll,ll>; 
#define NaN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define SZ(x) int((x).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()


const ll INF = 1LL<<60; 
const ll MAXN = 1e7; 

// Criba lineal, obtiene los primos menores al parametro
vi min_prime; // min_prime[i] contiene el menor primo que divide a i, util para factorizar en log(i)

vi criba(ll n) {
  vb prime(n+1,true);
  min_prime.resize(n+1,INF);
  vi primos;
  for(ll p=2; p*p<=n; p++){
    if(!prime[p]) continue;
    for(ll i=p*p; i<=n; i += p) {
      prime[i] = false;
      min_prime[i] = min(min_prime[i],p);
    }
  }
  forr(i, 2, n+1){
    if(prime[i]) primos.pb(i), min_prime[i] = i;
  }
  return primos; // lista de primos hasta n
}


int main(){  
  NaN;

  ll Q; cin >> Q; 
  ll q = Q; 
  vi prims = criba(MAXN); 

  vi divs; 
  for (ll d = 2; d * d <= q; d++) if (min_prime[d] == d and q % d == 0) {
    divs.pb(d); 
    while (q % d == 0) q /= d; 
  } 
  if (q > 1) divs.pb(q); 
  sort(all(divs)); 

  if (SZ(divs) == 0 or (SZ(divs) == 1 and divs[0] == Q)) cout << "1\n0\n"; 
  else if (SZ(divs) == 2 and divs[0] * divs[1] == Q) cout << "2\n"; 
  else if (SZ(divs) == 1 and divs[0] * divs[0] == Q) cout << "2\n"; 
  else if (SZ(divs) == 1) cout << "1\n" << divs[0] * divs[0] << '\n'; 
  else cout << "1\n" << divs[0] * divs[1] << '\n'; 

  return 0;
}
