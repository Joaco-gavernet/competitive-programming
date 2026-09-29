#include <bits/stdc++.h>
using namespace std;

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
#define NaN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define ff first
#define ss second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl




int main(){
  NaN;

  ll n; cin >> n; 
  string s; cin >> s; 
  ll F = 0, add = 0, sub = 0; 
  for (auto c : s) {
    F += (c == '+' ? 1 : -1); 
    add += (c == '+'); 
    sub += (c == '-'); 
  } 

  auto f = [&](ll x, ll y) -> ll {
    return - F * y / (x - y); 
  }; 

  ll q; cin >> q; 
  forn(_,q) {
    ll a, b; cin >> a >> b; 
    bool ok = (a == b and sub == add); 
    if (a != b and F * b % (a - b) == 0 and -sub <= f(a, b) and f(a, b) <= add) ok = true; 
    swap(a, b); 
    if (a != b and F * b % (a - b) == 0 and -sub <= f(a, b) and f(a, b) <= add) ok = true; 
    cout << (ok ? "YES" : "NO") << '\n'; 
  } 

  return 0;
}
