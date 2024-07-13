#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(int i = int(a); i < int(b); i++) 
#define forn(i,n) forr(i,0,n)
#define all(v) (v).begin(),(v).end()


int main() {
  FIN;

  int n,m; cin >> n >> m;

  vi g(n+1,0);
  string ans(m,'0');
  forn(i,m) {
    int a,b; cin >> a >> b;
    if (g[a] == 0 and g[b] == 0) {
      ans[i] = '1';
      g[a] = 1;
      g[b] = -1;
    } else if (g[a] != 0 and g[b] == 0) {
      if (g[a] == 1) g[b] = -1, ans[i] = '1';
      else g[b] = 1, ans[i] = '0';
    } else if (g[a] == 0 and g[b] != 0) {
      if (g[b] == 1) g[a] = -1, ans[i] = '0';
      else g[a] = 1, ans[i] = '1';
    } else if (g[a] + g[b] != 0) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  cout << ans << '\n';

  return 0;
}
