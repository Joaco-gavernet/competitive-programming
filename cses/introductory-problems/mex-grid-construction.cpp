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

const int MAXN = 105; 

int main(){
  FIN;

  int n; cin >> n; 

  vector<vi> ans(n); 
  vector<vb> row(MAXN, vb(2*MAXN+5,false)), col(MAXN, vb(2*MAXN+5,false)); 
  forn(i,n) col[SZ(ans[0])][i] = true, ans[0].pb(i); 

  forr(j,1,n) {
    forn(_,n) {
      int num = 0; 
      forn(k,2*MAXN+5) if (!row[j][k] and !col[SZ(ans[j])][k]) { 
        row[j][k] = col[SZ(ans[j])][k] = true; 
        num = k; 
        break; 
      }
      ans[j].pb(num); 
    }
  }
  for (auto &v: ans) {
    for (auto &x: v) cout << x << ' '; 
    cout << '\n'; 
  }


  return 0;
}
