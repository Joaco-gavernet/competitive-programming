#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

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
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl


int ret() {
  cout << "conflict\n"; 
  return 0; 
} 

int main(){
  FIN;

  int n, m; cin >> n >> m; 

  vector<vi> dep(m+1); 
  vi cont(n);
  queue<int> zero;

  string aux, s; 
  getline(cin, aux); 
  vector<vi> vs(n); 
  forn(id,n) {
    getline(cin, aux); 
    stringstream S(aux); 
    vi v; 
    while (S >> s) {
      if (s == "->") continue; 
      int x = -1;
      if (s[0] == '!') x = -stoi(s.substr(1));
      else x = stoi(s); 
      v.pb(x); 
    } 
    vs[id] = v; 

    if (SZ(v) == 1) zero.push(v[0]); 
    else {
      int ref = *v.rbegin(); 
      if (ref < 0) ref *= -1;
      forn(i,SZ(v)-1) dep[v[i]].pb(id); 
      cont[id] = SZ(v) -1;
    } 
  } 

  string ans(m, 'x'); 
  while (SZ(zero)) {
    int x = zero.front(); zero.pop(); 
    if (x > 0) {
      if (ans[x-1] == 'F') return ret(); 
      else ans[x-1] = 'T'; 
    } else {
      if (ans[-x-1] == 'T') return ret(); 
      else ans[-x-1] = 'F'; 
    } 
    if (x > 0) {
      for (auto u: dep[x]) {
	cont[u]--; 
	if (cont[u] == 0) {
	  int z = *vs[u].rbegin(); 
	  if (z > 0) {
	    if (ans[z-1] == 'F') return ret(); 
	    if (ans[z-1] == 'x') zero.push(z); 
	    ans[z-1] = 'T'; 
	  } else {
	    if (ans[-z-1] == 'T') return ret(); 
	    if (ans[-z-1] == 'x') zero.push(z); 
	    ans[-z-1] = 'F'; 
	  } 
	} 
      } 
    }
  } 

  forn(i,m) if (ans[i] == 'x') ans[i] = 'F'; 
  cout << ans << '\n'; 


  return 0;
}
