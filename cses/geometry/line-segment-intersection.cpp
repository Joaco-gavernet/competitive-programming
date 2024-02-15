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


typedef ll C;
typedef complex<C> P;
#define X real()
#define Y imag()
#define r(x) (x).real()

bool sameLine(P a, P b, P c, P d) {
  if ((conj(a)*c).Y == 0 and (conj(a)*d).Y == 0) return 1;
  else return 0;
}

bool correctOrder(P a, P b, P c, P d) {
  if (min(r(a),r(b))<=min(r(c),r(d)) and max(r(c),r(d))<=max(r(a),r(b))) return 1;
  else if (min(r(c),r(d))<= min(r(a),r(b)) and max(r(a),r(b))<=max(r(c),r(d))) return 1;
  else if (min(r(a),r(b))<=r(c) and r(c)<=max(r(a),r(b))) return 1;
  else if (min(r(a),r(b))<=r(d) and r(d)<=max(r(a),r(b))) return 1;
  else return 0;
}

ll side(P x, P y, P z) {
  return (conj(z-x)*(z-y)).Y; // cross product (z-x) x (z-y) 
}

bool intersect(P a, P b, P c, P d) {
  ll res1 = side(a,b,c);
  if (res1 == 0) return 1;
  ll res2 = side(a,b,d);
  if (res2 == 0) return 1;
  ll res3 = side(c,d,a);
  if (res3 == 0) return 1;
  ll res4 = side(c,d,b);
  if (res4 == 0) return 1;

  if ((res1<=0 and res2>=0) or (res1>=0 and res2<=0)){
    if ((res3<=0 and res4>=0) or (res3>=0 and res4<=0)) return 1;
    else return 0;
  }
  else return 0;
}


int main(){
  FIN;

  // There are three possible cases for valid intersections: 
  // 1. They intersect exactly in one vertex. 
  // 2. Segments are in the same line and they overlap each other.
  // 3. They intersect in the middle. 

  int t; cin >> t;

  ll x,y;
  while (t--) {
    cin >> x >> y;
    P a = {x,y};
    cin >> x >> y;
    P b = {x,y};
    cin >> x >> y;
    P c = {x,y};
    cin >> x >> y;
    P d = {x,y};

    dbg(sameLine(a,b,c,d));
    dbg(correctOrder(a,b,c,d));

    if (a == c or a == d or b == c or b == d) cout << "YES\n"; 
    else if (sameLine(a,b,c,d) and correctOrder(a,b,c,d)) cout << "YES\n";
    else if (intersect(a,b,c,d)) cout << "YES\n";
    else cout << "NO\n";
  }


  return 0;
}
