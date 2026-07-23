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
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "===============================\n"


struct nodo {
    int d, v, a;
    bool operator < (const nodo& next) const {
        return d > next.d; 
    }
}; 

int main() {
    FIN;
    int n, m; cin >> n >> m;
    vector<vector<pair<char,int>>> g(n);
    forn(i,m){
        int a, b; char c;
        cin >> a >> b >> c; a--; b--;
        g[a].pb({c,b}); g[b].pb({c,a});
    }
    
    // Dijkstra with path 
    vector<int> prev(n, -1);
    vector<char> prevc(n, '#'); 
    priority_queue<nodo> p; p.push({0, start, -1});
    


    return 0; 
}