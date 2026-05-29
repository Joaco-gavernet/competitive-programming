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


const ll INF = 1LL<<60; 
const ll MOD = 998244353;


ll be(ll a, ll b, ll p=MOD){
  if(b==0) return 1;
  ll k=be(a,b/2,p);
  if(b%2==0) return k*k%p;
  else return k*k%p*a%p;
}


vi min_prime;
void criba(ll n) {
  vb prime(n + 1, true); 
  min_prime.resize(n + 1, INF); 
  for (ll p = 2; p * p <= n; p++) {
    if (!prime[p]) continue; 
    for (ll i = p * p; i <= n; i += p) {
      prime[i] = false;
      min_prime[i] = min(min_prime[i], p);
    }
  }
  forr(i, 2, n + 1) if (prime[i]) min_prime[i] = i; 
}


int main() {
  FIN;
  ll m, k; cin >> m >> k;
  if(m==1){cout << "3\n"; return 0;}
  ll c=2*k+1;
  vi phi(k+1);
  criba(k+5);
  forr(i,2,k+1){
    if(min_prime[i]==i) phi[i]=i-1;
    else phi[i]=phi[i/min_prime[i]]*min_prime[i];
    c=(c+2*phi[i])%MOD;
  }
  cout << (2*c*(be(2*k+1,m-1)-1)%MOD*be(2*k,MOD-2)%MOD+3)%MOD << "\n";
  return 0;
}