#include <bits/stdc++.h>
using namespace std;

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=========================\n"


struct SCC {
    int n, scc;
    vector<vi> g, gr, ans;
    vb visto; 
    vi order, comp_act, component; 
    SCC(vector<vi> &_g) : n(SZ(_g)) {
        g = _g; 
        gr.resize(n), visto.resize(n), component.resize(n); 
        forn(v, n) for (auto u: g[v]) gr[u].pb(v); 
        find_scc(); 
    }
    void DFS1(int v) {
        visto[v] = true;
        for (int u: g[v]) if (!visto[u]) DFS1(u); 
        order.pb(v); 
    }
    void DFS2(int v) {
        visto[v] = true;
        comp_act.pb(v); 
        for (int u : gr[v]) if (!visto[u]) DFS2(u); 
    }
    void find_scc() {
        fill(all(visto), false); 
        forn(i,n) if (!visto[i]) DFS1(i); 
        fill(all(visto), false); 
        forn(i,n) {
            int v = order[n-1-i]; 
            if (!visto[v]) {
                DFS2(v); 
                ans.pb(comp_act); 
                comp_act.clear(); 
            }
        }
        scc = SZ(ans); 
        forn(i,scc) for (auto v : ans[i]) component[v] = i; 
    }
};

vi dsu, ptr, isSink, usedSink, aliveOut; 

void build(int n) {
    dsu.resize(n); 
    ptr.resize(n); 
    isSink.resize(n); 
    usedSink.resize(n); 
    aliveOut.resize(n); 
} 

int find(int x) {
    return dsu[x] == x or x == -1 ? x : dsu[x] = find(dsu[x]); 
} 

int getSink(int u, vector<vi> &gg) {
    u = find(u); // find current representative 
    if (u == -1) return -1; 

    if (isSink[u]) {
        if (!usedSink[u]) {
            usedSink[u] = true; 
            dsu[u] = -1; 
            return u; 
        } else return -1; // already used, then it's dead 
    } 

    while (true) {
        while (ptr[u] < SZ(gg[u])) {
            int v = find(gg[u][ptr[u]]); 
            if (v > -1) break; 
            ptr[u]++, aliveOut[u]--; 
        } 

        // no alive outgoing edges => dead path 
        if (ptr[u] == SZ(gg[u])) return (dsu[u] = -1); 

        if (aliveOut[u] == 1) {
            int only = find(gg[u][ptr[u]]); 
            dsu[u] = only; 
            return getSink(only, gg); 
        } 

        int v = find(gg[u][ptr[u]]); 
        int res = getSink(v, gg); 
        if (res > -1) return res; 
    } 
} 

int main() {
    FIN;
    int n, m; cin >> n >> m;
    vector <vi> g(n);
    forn(i,m){
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].pb(b);
    }
    SCC ds(g);
    const int N = ds.scc; 
    if (N == 1) {
        cout << "0\n"; 
        return 0; 
    } 

    vi rep(N);
    forn(i,n) rep[ds.component[i]] = i;

    vector<vi> gg(N); 
    vi in(N), out(N); 
    forn(v,n) for (auto u: g[v]) {
        int cv = ds.component[v]; 
        int cu = ds.component[u]; 
        if (cv != cu) {
            gg[cv].pb(cu); 
            in[cu]++, out[cv]++; 
        } 
    }

    build(N); 
    vi sources, sinks; 
    forn(v,N) {
        aliveOut[v] = SZ(gg[v]); 
        dsu[v] = v; 
        if (in[v] == 0) sources.pb(v); 
        if (out[v] == 0) sinks.pb(v), isSink[v] = true; 
    }

    vector<ii> match; 
    vi done(N); 
    for (auto s: sources) {
        int t = getSink(s, gg); 
        if (t > -1) done[s] = done[t] = 1, match.pb({s, t}); 
    } 

    vector<ii> ans; 
    vi psources, psinks; 
    for (auto s: sources) if (done[s] == 0) psources.pb(s); 
    for (auto t: sinks) if (done[t] == 0) psinks.pb(t); 
    while (SZ(psources) and SZ(psinks)) {
        ans.pb({psinks.back(), psources.back()}); 
        psinks.pop_back(), psources.pop_back(); 
    }
    for (auto s: psources) if (done[s] == 0) ans.pb({match[0].ss, s}); 
    for (auto t: psinks) if (done[t] == 0) ans.pb({t, match[0].ff}); 

    forn(i,SZ(match)-1) ans.pb({match[i].ss, match[i+1].ff}); 
    ans.pb({match.back().ss, match.front().ff}); 

    assert(SZ(ans) == max(SZ(sources), SZ(sinks))); 
    cout << SZ(ans) << '\n'; 
    for (auto [x, y]: ans) cout << rep[x] + 1 << ' ' << rep[y] + 1 << '\n'; 


    return 0;
}

