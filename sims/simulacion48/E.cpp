#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb;
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define pb push_back
// #define DBG(x) cerr << #x << " = " << x << endl
// #define RAYA cerr << "=============================\n"
// #define DBGV(v,n) cerr << #v << " = "; forn(_,n) cerr << v[_] << ' '; cerr << endl

const int MAXN = 305; 

void remover(pair<char,int> p, vector<multiset<pair<char,int>>> &c, vi &cartas) {
  if (p.first == '*' and p.second %2 == 1) c[2].erase(c[2].find(p)), cartas[2]--;
  if (p.first == '*' and p.second %2 == 0) c[1].erase(c[1].find(p)), cartas[1]--;
  if (p.first == '+' and p.second %2 == 1) c[0].erase(c[0].find(p)), cartas[0]--;
  if (p.first == '+' and p.second %2 == 0) c[2].erase(c[2].find(p)), cartas[2]--;
  return;
}

void change(int &m, pair<char,int> p) {
  // if (p.first == '*' and p.second %2 == 1) ;
  if (p.first == '*' and p.second %2 == 0) m = 0;
  if (p.first == '+' and p.second %2 == 1) m ^= 1;
  //~ if (p.first == '+' and p.second %2 == 0) ;
}

int main() {
  FIN; 
  
  int n, start; cin >> n;
  vector<pair<char,int>> v(n); 
  forn(i,n) cin >> v[i].first >> v[i].second; 
  cin >> start; start %= 2; 

  bool dp[2][MAXN][MAXN][MAXN]; 
  if (n %2 == 0) {
    dp[1][0][0][0] = true;
    dp[0][0][0][0] = false;
  } else {
    dp[1][0][0][0] = false;
    dp[0][0][0][0] = true;
  }

  forn(k,MAXN){
    forn(i,MAXN){
      forn(j,MAXN) {
        forn(m,2) {
          if(i==0 and j==0 and k==0) continue;
          bool ans = false;
          if (i > 0) ans = ans or (not dp[m ^1][i-1][j][k]) ;
          if (j > 0) ans = ans or (not dp[0][i][j-1][k]) ;
          if (k > 0) ans = ans or (not dp[m][i][j][k-1]) ;
          dp[m][i][j][k] = ans; 
        }
      }
    }
  }

  // forn(m,2){
  //   forn(i,2){
  //     forn(j,2) {
  //       forn(k,2) {
  //         DBG(m);DBG(i); DBG(j);DBG(k);DBG(dp[m][i][j][k]);
  //         RAYA;
  //       }
  //     }
  //   }
  // }

  vi cartas(3); 
  for (auto [c, x]: v) {
    if (c == '*' and x %2 == 1) cartas[2]++;
    if (c == '*' and x %2 == 0) cartas[1]++;
    if (c == '+' and x %2 == 1) cartas[0]++;
    if (c == '+' and x %2 == 0) cartas[2]++;
  }
  if (dp[start][cartas[0]][cartas[1]][cartas[2]]) cout << "me" << endl; 
  else cout << "you" << endl; 

  ll pos = dp[start][cartas[0]][cartas[1]][cartas[2]]; 
  vector<multiset<pair<char,int>>> c(3); 
  for (auto [cc, x]: v) {
    if (cc == '*' and x %2 == 1) c[2].insert({cc, x});
    if (cc == '*' and x %2 == 0) c[1].insert({cc, x});
    if (cc == '+' and x %2 == 1) c[0].insert({cc, x});
    if (cc == '+' and x %2 == 0) c[2].insert({cc, x});
  }

  int m = start; 
  forn(_,n) {
    // DBG(m); DBGV(cartas,SZ(cartas));
    if (pos == 0) {
      pair<char,int> p; cin >> p.first >> p.second; 
      remover(p, c, cartas); 
      change(m, p); 
    } else {
      auto i = cartas[0], j = cartas[1], k = cartas[2]; 
      if (i > 0 and not dp[m ^1][i-1][j][k]) {
        auto [x1, x2] = *(c[0].begin()); 
        cout << x1 << ' ' << x2 << endl; 
        remover({x1, x2}, c, cartas); 
        change(m, {x1, x2}); 
      } else if (j > 0 and not dp[0][i][j-1][k]) {
        auto [x1, x2] = *(c[1].begin()); 
        cout << x1 << ' ' << x2 << endl; 
        remover({x1, x2}, c, cartas); 
        change(m, {x1, x2}); 
      } else if (k > 0 and not dp[m][i][j][k-1]) {
        auto [x1, x2] = *(c[2].begin()); 
        cout << x1 << ' ' << x2 << endl; 
        remover({x1, x2}, c, cartas); 
        change(m, {x1, x2}); 
      }
    }
    pos ^= 1; 
  }

  
  return 0;  
} 
