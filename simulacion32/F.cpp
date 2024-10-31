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
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define RAYA cerr << "===============================" << endl



const int MOD = 1e9+7; 

vector<vi> prod(vector<vi> &a, vector<vi> &b, int MOD) {
  const int n = SZ(a); 
  vector<vi> ans(n, vi(n,0)); 
  forn(i,n) forn(j,n) forn(k,n) {
    ans[i][j] += (a[i][k]*b[k][j]) %MOD; 
    if (ans[i][j] >= MOD) ans[i][j] -= MOD; 
  }
  return ans; 
}

vector<vi> be(ll k, vector<vi> mat, int MOD) {
  if (k == 1) return mat; 
  const int n = SZ(mat); 
  vector<vi> ans, aux; 
  aux = be(k/2, mat, MOD); 
  ans = prod(aux, aux, MOD); 
  if (k&1) ans = prod(ans, mat, MOD); 
  return ans; 
}

int main(){
  FIN;

  // modulate with matrix exponentiation and the formula B = M x A
  // B = [fn+k, fn+k-1, (n+k)^2, n+k, 1] si se generaliza a k pasos
  // A = [f1, f0, n^2, n, 1] si n = 1

  int q; cin >> q; 
  vector<vi> base = {{1, 1, 2, 0, 5}, 
                    {1, 0, 0, 0, 0}, 
                    {0, 0, 1, 2, 1}, 
                    {0, 0, 0, 1, 1}, 
                    {0, 0, 0, 0, 1}};  
  const int n = 5; 
  vi A = {1, 0, 4, 2, 1}; 

  while (q--) {
    ll k; cin >> k; 
    vector<vi> M = be(k,base,MOD); 

    // make the dot product B[0] = M[0] * A 
    ll b = 0; 
    forn(i,n) {
      b += (M[1][i]*A[i]) %MOD; 
      if (b >= MOD) b -= MOD; 
    }

    cout << b << '\n'; 
  }

  return 0;
}
