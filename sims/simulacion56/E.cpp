#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v), end(v)
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=================================\n"



int main() {
  FIN;

  int n, k; cin >> n >> k;

  ll ans = 0;
  string s;
  map<string, int> m;
  forn(_,k+1) {
    getline(cin, s);
    stringstream S(s);

    int cont = 0;
    while (S >> s) {
      if (s == "Re:") cont++;
      else {
        if (cont -m[s] +1 > 0) {
          ans += cont +1 -m[s]; 
          m[s] = cont +1;
        }
      }
    }
  }
  if (ans <= n) cout << "YES\n";
  else cout << "NO\n";
  
  return 0; 
}
