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

  int n, a, b; cin >> n >> a >> b; 
  vi st; 
  vi p(n); forn(i,n) cin >> p[i], st.pb(p[i]); 
  sort(all(st)); 

  vector<ii> ans(n); 
  forn(i,n) {
    // busco presas 
    int up = p[i] -a, down = p[i] -b;
    int r = upper_bound(all(st), up) -st.begin(); r--; 
    int l = upper_bound(all(st), down) -st.begin();
    ans[i].snd = max(0, r -l +1); 

    // busco depredadores 
    up = p[i] +b, down = p[i] +a;
    r = upper_bound(all(st), up-1) -st.begin(); r--; 
    l = lower_bound(all(st), down) -st.begin();
    ans[i].fst = max(0, r -l +1); 
  } 

  for (auto &x: ans) cout << x.fst << ' ' << x.snd <<'\n'; 


  return 0;
}
