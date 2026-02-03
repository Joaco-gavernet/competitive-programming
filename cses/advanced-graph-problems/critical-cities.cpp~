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
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "===========================\n"


vi bfs (int st, vector<vi> &adj) {
    const int n = SZ(adj); 
    queue<int> q; q.push(st);  
    const ll ini = 1e6; 
    vi dist(n, ini); dist[st] = 0; 
    while (SZ(q)) {
        int v = q.front(); q.pop(); 
        for (auto u: adj[v]) if (dist[u] == ini) {
            dist[u] = dist[v] + 1; 
            q.push(u); 
        }
    }
    return dist; 
}; 

int main() {
    FIN;

    int n, m; cin >> n >> m; 
    vector<vi> g(n), gr(n);
    forn(i,m) {
        int a, b; cin >> a >> b;
        g[--a].pb(--b);
        gr[b].pb(a); 
    }
    vi dist = bfs(n-1, gr); 

    vi key; 
    vb visto(n); 
    visto[0] = true; 
    auto comp = [&dist] (int u, int v) { return dist[u] < dist[v]; }; 
    priority_queue<ll, vi, decltype(comp)> pq(comp); 
    pq.push(0); 
    set<ll> active; 
    while (SZ(pq)) {
        auto x = pq.top(); pq.pop(); 
        for (auto y: g[x]) if (not visto[y]) {
            pq.push(y); 
            visto[y] = true; 
            active.insert(y); 
        }
        active.erase(x); 
        if (x == n-1) break; 
        else if (SZ(active) == 1) key.pb(*active.begin()); 
    }

    key.pb(0);
    sort(all(key)); 

    cout << SZ(key) << '\n'; 
    for (auto x: key) cout << x + 1 << ' ';
    cout << '\n'; 


    return 0; 
}
