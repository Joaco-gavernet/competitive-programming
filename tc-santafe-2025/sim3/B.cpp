#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii; 
typedef vector<bool> vb;
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define DBG(x) cout << #x << " = " << x << '\n'
#define RAYA cout << "=====================" << '\n'

struct event {
  ll  x;
  int id;
  ll z; 

  bool operator < (const struct event e) const {
    return (x == e.x ? z > e.z : x < e.x); 

    // The following lines ruined the ACC in contest: 
    // if (x == e.x) return (z >= 1) or (z == 0 and e.z < 1); 
    // else return x < e.x; 
  }
};

int main() {
  FIN; 

  int n, m; cin >> n >> m;
  vector<event> seq;
  seq.reserve(2*n + m +30);
  // island start {l, 1}
  // island end {r, -1}
  // bridge available {a, 0}

  vi il(n), ir(n); 
  forn(i,n) {
    cin >> il[i] >> ir[i]; 
    if (i > 0) {
      ll  mn = il[i] - ir[i-1], mx = ir[i] - il[i-1];
      seq.emplace_back(mn, i-1, mx); 
      seq.emplace_back(mx, i-1, -1); 
    }
  } 
  ll aux;
  forn(i,m) {
    cin >> aux; 
    seq.emplace_back(aux, i, 0);
  }

  // sweep line 
  sort(all(seq)); 
  vb visto(n-1,false); 
  vi ans(n-1,0);
  priority_queue<ii, vector<ii>, greater<ii>> pending; 
  for (auto &[x, id, z]: seq) {
    if (z == 0) {
      // new available bridge
      if (SZ(pending)) {
	auto [pz, pid] = pending.top();
	visto[pid] = true;
	pending.pop(); 
	ans[pid]=id; 
      }
    } else {
      if (z >= 1) pending.push({z, id}); 
      else if (!visto[id]) {
	cout << "No" << '\n';
	return 0;
      }
    }
  }
  if (SZ(pending)) cout << "No" << '\n';
  else {
    cout << "Yes" << '\n'; 
    for (ll u : ans) cout << u +1 << ' ';
    cout << '\n'; 
  }


  return 0; 
}
