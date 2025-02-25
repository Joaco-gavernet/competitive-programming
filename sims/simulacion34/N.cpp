#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(int i = (ll)a; i <(ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define DBG(x) cerr << #x << " = " << x << endl
#define DBGV(v,n) forn(i,n) cerr << v[i] << ' '
#define RAYA cerr << "================================\n"

vector<vi> binomial(int n) {
  vector<vi> binom(n+1, vi(n+1)); 
  binom[0][0] = binom[1][0] = binom[1][1] = 1; 
  forr(i,2,n+1) {
    forn(j,i+1) {
      if (j == 0 or j == i) binom[i][j] = 1; 
      else binom[i][j] = binom[i-1][j-1] + binom[i-1][j]; 
    }
  }
  return binom; 
}

int main() {
  FIN;

  vector<vi> binom = binomial(50); 

  ll tot = 0; 
  ll n, k; cin >> n >> k; 
  forr(m, max(0LL,k-n), min(k,n) +1) {
    if (n %2 == 0 and m %2 == 1) {
      tot += binom[n][m] /2; 
      if (k %2 == 0 and m == k/2) tot += binom[n][m] /2; 
    }
    else {
      tot += (binom[n][m] + binom[n/2][m/2]) /2; 
      if (k %2 == 0 and m == k/2) tot += (binom[n][m] + binom[n/2][m/2]) /2; 
    }
  }
  cout << tot << '\n'; 

  
  return 0; 
}
