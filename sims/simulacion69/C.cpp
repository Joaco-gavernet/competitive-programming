#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << '\n'
#define RAYA cerr << "===========================\n"

const int num_bits = 32; 

int main() {
  FIN;

  unsigned long long n; cin >> n;
  vi ans; 
  while (n) {
    int x = n & (127);
    n >>= 7;
    // bitset<num_bits> binrep(x);
    // DBG(binrep.to_string());
    ans.pb(x);
  }

  if (SZ(ans) == 0) {
    cout << 0 << '\n';
    return 0;
  }
  bool ok = 0;
  reverse(all(ans));
  forn(i,SZ(ans)) {
    int x = ans[i];
    if (x > 0) ok = true;
    if (ok and i < SZ(ans)-1) x |= (1<<7);
    cout << x << ' ';
  }
  cout << '\n'; 

  return 0;
}