#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define SZ(x) int((x).size())
#define DBG(c) cerr << #c << " = " << c << endl
#define RAYA cerr << "========================= \n"

const ll MAXN = -1;
const ll MOD = -1;
const ll INF = -1;

vi dxu = {1,0,-1,0};
vi dyu = {0,-1,0,1};

void solve(ll x, ll y, ll dist, ll lado) {
  vi dx = {dist,dist,-dist,-dist};
  vi dy = {dist,-dist,dist,-dist};
  vi ans(4, (1LL<<60));

  forn(i,4) {
    if (x +dx[i] < 0) continue;
    if (x +dx[i] > 1e6) continue;
    if (y +dy[i] < 0) continue;
    if (y +dy[i] > 1e6) continue;
    cout << x +dx[i] << ' ' << y +dy[i] << endl;
    //~ DBG(dist); 
    //~ DBG(pow(1e6-(x+dx[i]),2) + pow(1e6-(y+dy[i]),2));
    cout.flush();
    cin >> ans[i];
    if (ans[i] == 0) return;
    else if (ans[i] == 1) {
      ll aux;
      forn(j,4) {
	if (x +dx[i] +dxu[j] < 0) continue;
	if (x +dx[i] +dxu[j] > 1e6) continue;
	if (y +dy[i] +dyu[j] < 0) continue;
	if (y +dy[i] +dyu[j] > 1e6) continue;
        cout << x +dx[i] +dxu[j] << ' ' << y +dy[i] +dyu[j] << endl;
        cout.flush();
        cin >> aux;
        if (aux == 0) return;
      }
      //~ cout << "aca\n";
    }
  }

  int best = 0;
  forr(i,1,4) {
    if (ans[i] < ans[best]) best = i;
  }

  solve(x +dx[best], y +dy[best], lado/2, lado-lado/2);
}

int main() {
  FIN;

  int n; cin >> n;
  while (n--) solve(5e5, 5e5, 250000, 250000);

  return 0;
}
