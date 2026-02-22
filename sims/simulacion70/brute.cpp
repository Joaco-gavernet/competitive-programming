#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl 
#define RAYA cerr << "======================\n"

vector<vi> binomial(int n) {
  vector<vi> binom(n+1, vi(n+1)); 
  binom[0][0] = binom[1][0] = binom[1][1] = 1; 
  forr(i, 2, n + 1) {
    forn(j, i + 1) {
      if (j == 0 or j == i) binom[i][j] = 1;
      else binom[i][j] = binom[i-1][j-1] + binom[i-1][j]; 
    }
  }
  return binom; 
}

int main() {
  FIN;

  int n; cin >> n; 
  vector<vi> binom = binomial(n); 
  cerr << "   ";
  forn(j, n) printf("%5lld ", j); 
  cerr << '\n';
  forn(i, n) {
    cerr << i << ": "; 
    forn(j, n) printf("%5lld ", binom[j][i]); 
    cerr << '\n'; 
  }


  return 0; 
}