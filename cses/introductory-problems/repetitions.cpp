//~ g++ -std=c++17 -DLOCAL -O2 -g -Wshadow -Wextra -Wall -Wconversion -c %f
//~ g++ -std=c++17 -DLOCAL -O2 -g -Wshadow -Wextra -Wall -Wconversion -o %e %f

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "======================" << endl
#else
#define DBG(x)
#define RAYA
#endif

typedef long long ll;
typedef long double ld;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = a; i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define mp make_pair
#define pb push_back
#define SZ(x) int((x).size())
#define all(x) (x).begin(),(x).end()
#define esta(x,c) ((c).find(x) != (c).end())

const int INF = 1<<30;
const int MOD = 1e9+5;
const int MAXN = 2e5+5;

int main() {
  FIN;
  
  string s; cin >> s;
  
  ll act = 1, maxAct = 1;
  ll tot = SZ(s);
  forr(i,1,tot) {
    if (s[i-1] == s[i]) act++;
    else {
      maxAct = (act > maxAct) ? act : maxAct;
      act = 1;
    }
  }
  
  maxAct = (act > maxAct) ? act : maxAct;
  cout << maxAct << "\n";
  
  
  
  return 0;
}
