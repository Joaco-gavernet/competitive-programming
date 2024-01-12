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

// Compresion de coordenadas
// Complejidad: O(n log n) para construir, O(log n) para obtener
struct compresion {
    vector<ll> todos;
    compresion(vector<ll> v) {
        todos = v; sort(all(todos));
        todos.erase(unique(all(todos)),todos.end());
    }
    ll obtener(ll x) { // Esto se podria hacer tambien con un unordered_map en O(1)
        return (ll)(lower_bound(all(todos),x)-todos.begin());
    }
};

// Mo's Algorithm for range queries
// Time: O(n*sqrt(n))
// Usage: mo mo; mo.read_queries(m); mo.get_mo(v);

struct query{
    int l, r, ind;
    bool operator <(query q) const {
        return r < q.r;
    }
};

struct mo {
    const int block = 448; // sqrt(MAXN)
    vector<vector<query>> q;
    vector<ll> ans, cont;

    mo(){
        ans.resize(MAXN), cont.resize(MAXN);
        q.resize(MAXN/block+5);
    }

    void read_queries(int m) { // m --> number of queries
        ans.resize(m,0);
        forn(i, m) {
            int l, r; cin >> l >> r;
            l--; r--; // For 0-indexed 
            q[l / block].pb({l,r,(int)i});
        } 
    }

    void add(ll &sum, ll val) {
        if(cont[val] == 0) sum++;
        cont[val]++;
    }

    void erase(ll &sum, ll val) {
        if(cont[val] == 1) sum--;
        cont[val]--;
    }

    void get_mo(vector<ll> &v) { 
        ll sum = 0;
        forn(i,q.size()) {
            sort(all(q[i])); 
            int l, r; l = r = block * i; 
            for(query u : q[i]) { // Solve for [l,r]
                while(r <= u.r) add(sum,v[r]), r++;
                while(l <= u.l) erase(sum,v[l]), l++;
                while(l > u.l) l--, add(sum,v[l]);
                ans[u.ind] = sum;     
            }
            while(l < r) erase(sum,v[l]), l++;
        }
    }
};

int main(){
  FIN;
  
  ll n, q;
  cin >> n >> q;
  vector<ll> v(n);
  forn(i,n) cin >> v[i];
  compresion c(v);
  forn(i,n) v[i] = c.obtener(v[i]);
  
  mo m;
  m.read_queries(q); 
  m.get_mo(v);
  
  forn(i,q) cout << m.ans[i] << '\n';
  
  return 0;
}





