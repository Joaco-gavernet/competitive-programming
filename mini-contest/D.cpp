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

typedef long double tipo; 

struct dev {
  tipo a, b, off; 
  bool operator < (const dev b) const {
    return off < b.off; 
  } 
}; 

ostream &operator << (ostream &os, const dev &x) {
  return os << "(" << x.a << ',' << x.b << ',' << x.off << ")"; 
} 


int main(){
  FIN;

  int n, p; cin >> n >> p; 
  vector<dev> v(n); forn(i,n) cin >> v[i].a >> v[i].b; 

  tipo l = 0, r = 1e20; 
  forn(_,100) {
    tipo mid = (l + r) /2; 

    bool ok = true; 
    tipo charge_time = mid * p; 
    forn(i,n) {
      tipo kill = v[i].b / v[i].a;
      if (kill < mid) { 
        tipo time = (v[i].a * mid - v[i].b); 
        charge_time -= time; 
        if (charge_time < 0) break; 
      }
    } 

    if (charge_time < 0) r = mid; 
    else l = mid; 
  } 
  if (l >= 1e18) l = -1; 
  cout << fixed << setprecision(10); 
  cout << l << '\n'; 


  return 0; 
}
