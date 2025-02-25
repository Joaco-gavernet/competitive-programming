#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define pb push_back
#define esta(x,v) (v).find(x) != (v).end()
#define all(v) (v).begin(),(v).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "================================\n"
#define DBGV(v,n) forn(i,n) cerr << v[i] << ' '
#define fs first
#define ss second

int main() {
  FIN;
  
  int n; cin >> n; 
  
  cout << "? " << n << ' ' << 1 << endl;
  int k; cin >> k; 
  if (k == n) {
    cout << "! " << n << ' ' << 1 << endl;
  }
  
  cout << "? " << n-k << ' ' << 1 << endl;
  int m; cin >> m; 
  cout << "! " << k << ' ' << m << endl;

  
  return 0;
}
