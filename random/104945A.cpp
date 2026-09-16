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


struct card {
  char t; int x, id; 
}; 

int main(){
  NaN;

  ll n; cin >> n; 
  vector<card> v(n); 
  forn(i,n) {
    string aux; cin >> aux; 
    v[i] = {aux[0], stoi(aux.substr(1)), i};
  } 
  vector<card> u = v; 

  vector<char> ord = {'S', 'W', 'E', 'R'}; 
  sort(all(ord)); 

  vi val('Z'); 
  val['C'] = 4; 
  auto cmp = [&](const card& a, const card& b) -> bool {
    if (a.t == b.t) return a.x < b.x; 
    return val[a.t] < val[b.t]; 
  }; 

  ll best = 1ll<<60; 
  do {
    forn(i,4) val[ord[i]] = i; 
    sort(all(v), cmp); 

    vi id(n), a(n); 
    forn(i,n) id[v[i].id] = i; 
    forn(i,n) a[i] = id[u[i].id]; 

    vi lis; 
    for (auto x : a) {
      auto it = lower_bound(all(lis), x); 
      if (it == lis.end()) lis.pb(x); 
      else *it = x; 
    } 

    best = min(best, n - SZ(lis)); 
  } while (next_permutation(all(ord))); 

  cout << best << '\n'; 

  return 0;
}
