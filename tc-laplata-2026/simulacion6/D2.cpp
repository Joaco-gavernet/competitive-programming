#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define mp make_pair
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==================================\n"


struct DSU {
    vi link, sz;
    DSU(int tam) {
        link.resize(tam + 5), sz.resize(tam + 5);
        forn(i, tam + 5) link[i] = i, sz[i] = 1;
    }
    ll find(ll x) { return (link[x] == x ? x : find(link[x])); }
    bool same(ll a, ll b) { return find(a) == find(b); }
    void join(ll a, ll b) {
        a = find(a), b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        link[b] = a; 
    }
};

int n, m;
vector <vi> v(200,vi(200));

bool solve(ii p){
    DSU d(n+m);
    forn(i,n) forn(j,m){
        if(mp(i,j)<p){
            if(v[i][j]==0) d.join(i,j+n);
        }
        else{
            if(v[i][j]==1) d.join(i,j+n);
        }
    }
    forn(i,n) forn(j,m){
        if(mp(i,j)<p){
            if(v[i][j]==1 and d.same(i,j+n)) return false;
        }
        else{
            if(v[i][j]==0 and d.same(i,j+n)) return false;;
        }
    }
    cout << "YES\n";
    vb visto(n+m);
    forn(i,n+m) if(!visto[d.find(i)])
    return true;
}

int main() {
    FIN;
    cin >> n >> m;
    forn(i,n) forn(j,m) cin >> v[i][j];
    forn(i,n) forn(j,m) if(solve(mp(i,j))) return 0;
    if(solve(n,m)) return 0;
    cout << "NO\n";

    return 0;
}