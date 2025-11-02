#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i <(ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << '\n'
#define RAYA cerr << "============================\n"
#define ff first
#define ss second


int main() {
  FIN;

  int n; cin >> n; 
  vi A(n); forn(i,n) cin >> A[i];
  vi B(n); forn(i,n) cin >> B[i];

  // acummulate in w[] for x mod 3
  vi acc(3); 
  forn(x,n) acc[x%3] += A[x]; 

  ll ans[] = {0,0,0}; 
  forn(y,n) {
    forn(k,3) ans[(y+k)%3] += B[y] * acc[k]; 
  }

  cout << ans[1] << ' ' << ans[2] << ' ' << ans[0];
  cout << '\n'; 


  return 0; 
}