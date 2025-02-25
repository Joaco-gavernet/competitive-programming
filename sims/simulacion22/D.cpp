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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_random(int l, int r){ // Random number in [l, r]
  return uniform_int_distribution<int>(l, r)(rng);
}

int solve() {
  ll cx = my_random(0,1e6);
  ll cy = my_random(0,1e6);
  cout << cx << ' ' << cy << endl;
  cout.flush();
  ll d; cin >> d;
  if (d == 0) return 1;

  for (ll x = 0; x*x <= d; x++) {
    ll z = d -x*x;
    ll y = sqrtl(z);
    while (y*y < z) y++;
    if (y*y != z) continue;
    ll dx[] = {x,x,-x,-x};
    ll dy[] = {y,-y,y,-y};
    forn(i,4) {
      if (cx +dx[i] < 0 or 1e6 < cx +dx[i]) continue;
      if (cy +dy[i] < 0 or 1e6 < cy +dy[i]) continue;
      cout << cx +dx[i] << ' ' << cy +dy[i] << endl;
      cout.flush();
      cin >> d;
      if (d == 0) return 1;
    }
  }

  return 0;
}


int main() {
  FIN;

  int n; cin >> n;
  for (int cont = 0; cont < n; ) cont += solve();

  return 0;
}
