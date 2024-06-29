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
    string s; cin >> s;

    if (n < 3) cout << stoi(s) << '\n';
    else if (n == 3 and (s[0] == '0' or s[2] == '0')) cout << "0\n";
    else {
      int mi = INF;
      bool zero = false;
      bool dif = false;
      forn(i,n) {
        if (zero == false) zero = (int(s[i]-'0') == 0);
        if (i < n-1) mi = min(mi,int(s[i] -'0'));
        if (int(s[i] -'0') > 1) dif = true;
      }

      if (n > 3 and zero == true) cout << "0\n";
      else {
        int act = 0;
        forn(i,n) {
          dbg(act);
          if (int(s[i] -'0') == mi) {
            if (dif == true) {
              if (int(s[i+1] -'0') > mi or i == n-2) {
                if (mi*10 + int(s[i +1] -'0') != 1) {
                  act += mi*10 + int(s[++i] -'0');
                  mi = INF;
                }
              } else {
                if (i == 0 and s[i] == '1') act += 1;
                else if (s[i] != '1') act += int(s[i] -'0');
              }
            } else {
              if (mi*10 + int(s[i +1] -'0') != 1) {
                act += mi*10 + int(s[++i] -'0');
                mi = INF;
              }
            }
          } else {
            if (i == 0 and s[i] == '1') act += 1;
            else if (s[i] != '1') act += int(s[i] -'0');
          }
        }
        cout << act << '\n';
      }
    }
    RAYA;
  }
  
  
  return 0;
}
