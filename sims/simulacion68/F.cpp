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
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=========================\n"
#define all(v) begin(v),end(v)


int nan() {
  cout << "impossible\n";
  return 0;
}

void dfs(int v, vector<vi> &dir, vector<vi> &inv, vb &visto, vector<ii> &rems, vector<ii> &vals, int prev = -1) {
  visto[v] = true;
  
  for (auto u: dir[v]) {
    if (visto[u] == false) vals.pb({v, u}), dfs(u, dir, inv, visto, rems, vals, v);
    else if (u != prev) rems.pb({v, u}); 
  }
  for (auto u: inv[v]) {
    if (visto[u] == false) vals.pb({u, v}), dfs(u, dir, inv, visto, rems, vals, v);
    else if (u != prev) rems.pb({u, v}); 
  }
}

int main() {
  FIN;

  int n; cin >> n;
  vi a(n), b(n); 
  forn(i,n) cin >> a[i]; 
  priority_queue<ii> pq; 
  forn(i,n) {
    cin >> b[i]; 
    if (b[i]) pq.push({b[i], i});
  }
  
  if (n == 1) {
    if (a[0] or b[0]) cout << "impossible\n";
    else cout << "1 0\n"; 
    return 0; 
  }

  forn(i,n) if (a[i] == b[i] and a[i] == 0) return nan(); 

  
  // checks
  int A = 0, B = 0;
  forn(i,n) A += a[i];
  forn(i,n) B += b[i];

  if (A != B) return nan();

  // greedy for first version of the graph
  vector<vi> dir(n), inv(n);
  int i = 0;
  while (i < n) {
    if (i < n and a[i]) {
      vi act;
      while (SZ(pq) and a[i]) {
        act.pb(pq.top().ss);
        pq.pop(); 
        if (act.back() != i) a[i]--;
      }
      
      if (a[i]) return nan();
      
      while (SZ(act)) {
        int k = act.back();
        act.pop_back();
        if (k != i) {
          dir[i].pb(k);
          inv[k].pb(i);
          b[k]--;
        }
        if (b[k]) pq.push({b[k], k});
      }

      // DBG(i);
      // forn(i,n) cerr << a[i] << ' ';
      // cerr << '\n'; 
      // forn(i,n) cerr << b[i] << ' ';
      // cerr << '\n';
      if (a[i]) return nan();
    }
    i++;
  }

  // cerr << "graph dir debug: " << '\n';
  // forn(v,n) {
  //   cerr << v << ": ";
  //   for(auto u: dir[v]) cerr << u << ' ';
  //   cerr << '\n';
  // }
  // RAYA; 
  // cerr << "graph inv debug: " << '\n';
  // forn(v,n) {
  //   cerr << v << ": ";
  //   for(auto u: inv[v]) cerr << u << ' ';
  //   cerr << '\n';
  // }
  // RAYA; 

  // find spaning trees for each component and redundant edges
  typedef vector<ii> vii;
  vector<pair<vii, vii>> comp; // remainding and valid edges for each component (only the directed edge is included)
  vb visto(n);
  forn(v,n) {
    if (visto[v] == false) {
      vector<ii> rems, vals; 
      dfs(v, dir, inv, visto, rems, vals);
      sort(all(rems));
      rems.erase(unique(all(rems)), rems.end()); 

      // DBG(v);
      // for (auto [x, y]: rems) cerr << x << ':' << y << ' ';
      // cerr << '\n';
      comp.pb({vals, rems});
    }
  }
  // DBG(SZ(comp));

  auto custom = [&](pair<vii, vii> &a, pair<vii, vii> &b) {
    return SZ(a.ss) > SZ(b.ss); 
  };
  sort(all(comp), custom);

  // connect each weakly connected component having reminders with the less reminders ones 
  vector<pair<vii, vii>> alone; 
  while (SZ(comp) and SZ(comp.back().ss) == 0) {
    alone.pb(comp.back());
    comp.pop_back(); 
  }

  vii toprint; 
  while (SZ(comp) and SZ(alone)) {
    auto [rec, x] = alone.back(); alone.pop_back(); 
    auto [y, give] = comp.back(); comp.pop_back(); 
    
    // connect using operation: 
    // if a->b in weak-comp A and c->d in weak-comp C
    // do a->d and c->b
    auto [a, b] = give.back(); give.pop_back(); 
    auto [c, d] = rec.back(); rec.pop_back(); 
    rec.pb({a, d}); 
    rec.pb({c, b}); 

    if (SZ(x) != 0) { 
      unsigned int start = clock();
      while (clock() - start <= 30*CLOCKS_PER_SEC) {
        
      }
    } // x should be empty (SZ == 0) because otherwise it wouldn't be in alone[], rather in comp[]
    for (auto [a, b]: rec) toprint.pb({a, b});
    if (SZ(give)) comp.pb({y, give});
    else for (auto [a, b]: y) toprint.pb({a, b});
  }

  // DBG("cinco");
  // DBG(SZ(alone));
  // auto [rec, x] = alone.back();
  // for (auto [a, b]: rec) cerr << a << ' ' << b << ' ';
  // cout << '\n';
  // for (auto [a, b]: x) cerr << a << ' ' << b << ' ';
  // cout << '\n';

  if (SZ(alone) and SZ(comp)) return nan();
  if (SZ(comp) == 0) swap(comp, alone); 
  for (auto x: comp) {
    for (auto p: x.ff) toprint.pb(p);
    for (auto p: x.ss) toprint.pb(p);
  }

  cout << n << ' ' << SZ(toprint) << '\n'; 
  for (auto [a, b]: toprint) cout << a +1 << ' ' << b +1 << '\n';

  return 0;
}