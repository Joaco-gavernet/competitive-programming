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
#define RAYA cerr << "==================================\n"


int main() {
  FIN;

  int t; cin >> t; 
  if (t <= 360) cout << 0 << endl;
  else if (t <= 540) cout << min(t-360, 30) << endl; 
  else if (t <= 600) cout << max(min(t-540, 45), 30) << '\n';
  else cout << max(45, t-600) << endl; 

  return 0; 
}
