/*   AUTHOR: Estufa en Piloto   */
#include <bits/stdc++.h>
using namespace std;

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

#ifdef LOCAL
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "===============================" << endl
#else
#define DBG(x)
#define RAYA
#endif

typedef long long ll;
typedef vector<ll> vi; typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define SZ(x) int((x).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())


void find_divisors(ll x, unordered_set<ll> &divs) {
  for (ll i = 2; i*i <= x; i++) {
    if (x%i == 0) {
      divs.insert(i); 
      divs.insert(x/i); 
    }
  }
}

int main(){  
  FIN;

  ll l, r; cin >> l >> r; 
  for (ll i = l; i <= r; i++) {
    unordered_set<ll> divs; 
    find_divisors(i, divs); 
    ll tot = accumulate(all(divs), 0LL); 
    if (tot >= i) {
      cout << i << ' '; 
      break; 
    } else if (i == r) {
      cout << "-1 -1\n"; 
      return 0; 
    }
  }
  for (ll i = r; i > l; i--) {
    unordered_set<ll> divs; 
    find_divisors(i, divs); 
    ll tot = accumulate(all(divs), 0LL); 
    if (tot >= i) {
      cout << i << '\n'; 
      return 0; 
    }
  }
  cout << l << '\n'; 

  return 0;
}

