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

const ll INF = 1LL<<60; 

struct node {
    ll u, prev, w = INF; 
    bool operator < (const node &e) const {
        return w > e.w; 
    }
}; 

vi dijkstra(int st, int n, vector<vector<ii>> &g) {
    vi ans(n);  
    priority_queue<node> pq; pq.push({st, -1, 0}); 
    vb visto(n); 
    while (SZ(pq)) {
        auto [u, prev, w] = pq.top(); pq.pop(); 
        if (visto[u]) continue; 
        ans[u] = w; 
        visto[u] = true; 
        for (auto [v, wv]: g[u]) if (visto[v] == false) pq.push({v, u, w + wv}); 
    }
    return ans; 
}

struct point {
    ll x, y, z, id; 
    bool operator < (const point &p) const {
        if (x == p.x) {
            if (y == p.y) return z < p.z; 
            else return y < p.y; 
        } else return x < p.x; 
    }
    bool operator == (const point &p) const {
        return x == p.x and y == p.y and z == p.z; 
    }
}; 

struct Struc {
    map<ll,ll> mp; 
    bool dominates(point p) {
        auto it = mp.upper_bound(p.y); 
        if (it == mp.begin()) return true; 
        it--; 
        return p.z < (*it).second; 
    }
    bool insert(point p) {
        auto it = mp.upper_bound(p.y); 
        while (it != mp.end() and (*it).second >= p.z) {
            auto aux = it++; 
            mp.erase(aux); 
        }
        mp[p.y] = p.z; 
        return true; 
    } 
}; 

int main() {
  FIN;

  int n, m; cin >> n >> m; 
  vector<vector<ii>> g(n); 
  forn(i,m) {
      int a, b, w; cin >> a >> b >> w; 
      g[a].pb({b, w}); 
      g[b].pb({a, w}); 
  }

  vi d[3]; 
  forn(i,3) d[i] = dijkstra(i, n, g); 
  vector<point> v(n); 
  forn(i,n) v[i] = { d[0][i], d[1][i], d[2][i], i }; 

  sort(all(v)); 
  ll tot = 0; 
  Struc ds; 
  forn(i,n) {
      int j = i; 
      while (j < n and v[i] == v[j]) j++; 
      auto p = v[i]; 
      auto [x, y, z, id] = p; 
      if (ds.dominates(p)) {
          tot += j - i;
          ds.insert(p); 
      }
  }

  cout << tot << '\n'; 


  return 0;
}
