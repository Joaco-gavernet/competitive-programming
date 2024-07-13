#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
#define forr(i,a,b) for(int i = int(a); i < int(b); i++) 
#define forn(i,n) forr(i,0,n)
#define all(v) (v).begin(),(v).end()

bool comp(int a, int b) {
  return a > b;
}

int main() {
  int n; cin >> n;
  vi v(n); forn(i,n) cin >> v[i]; 
  sort(all(v),comp);

  if (n == 1) {
    cout << v[0] << endl;
    return 0;
  }

  vi ps(n+1);
  forr(i,1,n+1) ps[i] = v[i-1] + ps[i-1];

  ll ans = ps[n];
  while (n > 2) {
    cerr << n << endl;
    ans += ps[n--];
  }
  ans += ps[2];

  cout << ans << endl;


  return 0;
}
