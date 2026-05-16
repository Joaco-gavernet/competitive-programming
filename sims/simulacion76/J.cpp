#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cout << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"

const ll INF = 1LL<<60; 

typedef vector<vi> Matrix; 

Matrix ones(int n) {
  Matrix r(n, vi(n, INF)); 
  forn(i,n) r[i][i] = 0;
  return r; 
}

Matrix operator*(Matrix &a, Matrix &b) {
  int n = SZ(a), m = SZ(b[0]), z = SZ(a[0]); 
  Matrix r(n, vi(m, INF)); 
  forn(i,n) forn(j,m) forn(k,z) r[i][j] = min(r[i][j], a[i][k] + b[k][j]);
  return r;
}

Matrix be(Matrix b, ll e) {
  Matrix r = ones(b.size());
  while (e) { if (e&1LL) r = r * b; b = b * b; e /= 2; }
  return r;
}


int main() {
  FIN;

  int n, k; cin >> n >> k; 
  unordered_map<string,ll> val; 
  vector<pair<string,ll>> ops(n); 
  forn(i,n) cin >> ops[i].ff >> ops[i].ss, val[ops[i].ff] = ops[i].ss; 
  
  Matrix mat(26, vi(26, INF)); 
  forn(i,n) {
    auto [s, w] = ops[i]; 
    string sr = s;
    reverse(all(sr)); 
    if (val[s] and val[sr]) mat[s[0] - 'a'][s[1] - 'a'] = val[s] + val[sr]; 
  }

  // forn(y,26) {
  //   forn(x,26) cout << mat[y][x] << ' ';
  //   cout << '\n'; 
  // }

  ll best = INF; 
  Matrix state = be(mat, (k - 1) / 2); 
  forn(y,26) {
    forn(x, 26) {
      string center(2, 'a' + y); 
      if (k % 2 == 0 and val[center] == 0) continue; 
      best = min(best, val[center] * (k % 2 == 0) + state[y][x]);
      // cerr << center << ' ' << val[center];
      // cerr << ('a'+y) << ('a'+x) << ' ' << state[y][x] << '\n'; 
    }
  }
  
  if (best >= INF) best = -1;
  cout << best << '\n';
  
  return 0; 
}