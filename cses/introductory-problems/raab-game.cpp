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


void solve() {
    int n, a, b; cin >> n >> a >> b; 

    if (a+b > n or (a > 0 and b == 0) or (b > 0 and a == 0)) cout << "NO\n";  
    else {
        int la = 1, ra = n; 
        int lb = 1, rb = n; 
        int draws = n - (a+b); 

        vi ansa, ansb; 
        forn(_,draws) ansa.pb(la++), ansb.pb(lb++); 
        forn(i,a) ansa.pb(ra-a+i+1), ansb.pb(lb++); 
        ra -= a; 
        while (la <= ra) ansa.pb(la++), ansb.pb(lb++); 

        cout << "YES\n"; 
        for (auto &x: ansa) cout << x << ' '; cout << '\n';
        for (auto &x: ansb) cout << x << ' '; cout << '\n';
    }
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
