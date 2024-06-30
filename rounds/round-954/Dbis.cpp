#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef long long ll;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);


int main(){
  FIN;

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    string aux; cin >> aux;
    vector<int> s(n);
    forn(i,n) {
      s[i] = int(aux[i] -'0');
    }

    // procesar mi
    bool zero = false;
    bool one = false;
    int mi = INF;
    forn(i,n) {
      if (zero == false) zero = (s[i] == 0);
      if (i < n-1) mi = min(mi,s[i]);
    }

    dbg(zero);
    dbg(mi);
    dbg(s);
    if (n < 3) cout << stoi(aux) << '\n';
    else if (n > 3 and zero == true) cout << "0\n";
    else if (n == 3 and (s[0] == 0 or s[n-1] == 0)) cout << "0\n";
    else {
      int act = 0;
      forn(i,n) {
        if ((mi != INF and i == n-2) or (s[i] == mi and (s[i+1] != mi or (s[i] != 1 and s[i+1] == mi and i+2<n and s[i+2] == 1)))) {
          if (mi*10 + s[i+1] > 1) {
            act += mi*10 + s[++i];
            mi = INF;
          } else one = true;
        } else if (s[i] != 1) act += s[i];
        dbg(i, s[i], act, mi);
      }

      if (one == true and act == 0) act = 1;
      cout << act << '\n';
    }

    RAYA;
  }



  return 0;
}
