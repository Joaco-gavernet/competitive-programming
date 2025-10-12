#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define DBG(x) cerr << #x << " = " << x << endl 
#define RAYA cerr << "=============================\n"


const ll INF = 1LL<<60;

int main() {
  FIN;

  int n, m, s, p, q; 
  cin >> n >> m >> s >> p >> q; 
  
  const int N = (n +m -1) /m;
  vector<vb> active(N, vb(m)), need(N, vb(m));
  vi si(N);
  forn(i,p) {
    int x; cin >> x; x--;
    active[x/m][x%m] = true;
  }
  forn(i,q) {
    int x; cin >> x; x--;
    need[x/m][x%m] = true;
    si[x/m]++;
  }

  vi tochange(N, INF);
  forn(i,N) {
    int sobra = 0, falta = 0; 
    for (int j = 0; j < m and i*m +j < n; j++) {
      if (need[i][j] and active[i][j] == false) falta++;
      else if (active[i][j] and need[i][j] == false) sobra++;
    }

    tochange[i] = falta + sobra;
    tochange[i] = min(tochange[i], 1LL +si[i]);
    int auxi = m;
    if (i == N-1) {
      auxi = n %m; 
      if (auxi == 0) auxi = m;
    }
    tochange[i] = min(tochange[i], 1LL +(auxi -si[i]));
  }

  // forn(i,N) cerr << i << " = " << tochange[i] << '\n';
  // RAYA;
  
  s--;
  int beg = s, en = s; 
  forn(i,N) if (tochange[i] > 0) {
    beg = i; 
    break;
  }
  for (int i = N-1; i >= 0; i--) if (tochange[i] > 0) {
    en = i; 
    break;
  }

  int d1 = max(0, s -beg), d2 = max(0, en -s); 
  ll ans = d1 + d2 +min(d1, d2);
  forn(i,N) if (tochange[i] < INF) ans += tochange[i]; 

  cout << ans << '\n'; 

  return 0; 
}