#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
#define forr(i,a,b) for(int i = a; i < b; i++)
#define forn(i,n) forr(i,0,n) 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0) 
#define pb push_back
#define all(v) begin(v), end(v)
#define SZ(x) int((x).size())
#define DBG(x) cout << #x << " = " << x << '\n'


int main() {
  FIN; 

  int n, a1, k, p; 
  cin >> n >> a1 >> k >> p; 

  vi v = {a1}; 
  forr(i,1,n) {
    assert(i-1 >= 0 and i < n); 
    v.pb((v.back() *k) %p);
  }
  sort(all(v)); 
  forn(i,5) cout << v[n -5 +i] << ' ';
  cout << '\n'; 



  return 0;
}
