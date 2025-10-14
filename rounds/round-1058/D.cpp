#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl


int query(vi &a, int l, int r) {
  vi toprint; 
  forr(i,l,r+1) if (a[i] == -1) toprint.pb(i); 
  cout << "? " << SZ(toprint) << ' '; 
  for (auto &x: toprint) cout << x +1 << ' ';
  cout << '\n'; cout.flush();  
  int mad; cin >> mad; 
  return mad; 
} 

int query2(vi &base, int pos) {
  cout << "? " << SZ(base) +1 << ' '; 
  for (auto &x: base) cout << x +1 << ' ';
  cout << pos +1 << ' ';
  cout << '\n'; cout.flush(); 
  int mad; cin >> mad; 
  return mad; 
} 

void solve() {
  int n; cin >> n; 

  const int N = 2*n; 
  vi a(N, -1); 
  forr(i,1,N) {
    int aux = 0; 
    while (i < N and (aux = query(a, 0, i)) == 0) i++;  
    if (aux > 0) a[i] = aux; 
  } 
  vi base; 
  forn(i,N) if (a[i] > -1) base.pb(i); 
  forn(i,N) if (a[i] == -1) a[i] = query2(base, i); 

  cout << "! "; 
  for (auto &x: a) cout << x << ' '; 
  cout << '\n'; cout.flush(); 
}


int main(){
  // FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
