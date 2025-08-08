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


int main(){
  FIN;

  int n, k; cin >> n >> k; 
  int x, a, b, c; cin >> x >> a >> b >> c; 
  vi v = {x}; 
  forn(i,n-1) v.pb((a*v.back() +b) %c); 

  ll ans = 0; 
  priority_queue<ll> st; 
  forn(i,k) st.push(-v[i]); 
  unordered_map<int,int> toerase; 
  dbg(v); 
  forn(i,n-k+1) {
      dbg(SZ(st), st.top()); 
      while (toerase[-st.top()] > 0) toerase[-st.top()]--, st.pop(); 
      ll aux = -st.top(); 
      dbg(i, aux); 
      ans ^= aux; 
      if (i+k+1 < n) toerase[v[i+k+1]]++; 
  }
  cout << ans << '\n'; 

  return 0;
}

  /*
  ll ans = 0; 
  multiset<ll> st; 
  forn(i,k) st.insert(v[i]); 
  forn(i,n-k+1) {
      ll aux = *st.begin(); 
      ans ^= aux; 
      st.erase(st.find(v[i])); 
      if (i+k+1 < n) st.insert(v[i+k+1]); 
  }
  */ 

