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

const int MAXN = 2e5+5;

vector<int> bfs(vector<vector<pair<char,int>>>& g) {
    const int n = SZ(g); 
    vector <int> v(n);
    bitset<MAXN> visto;
    queue <int> q;
    q.push(n-1); visto[n-1]=true;
    while(SZ(q)>0){
        int x=q.front(); q.pop();
        for(auto &[c,u] : g[x]) if(!visto[u]){
            visto[u]=true;
            q.push(u);
            v[u]=v[x]+1;
        }
    }
    return v; 
}

int main() {
    FIN;
    int n, m; cin >> n >> m;
    vector<vector<pair<char,int>>> g(n);
    forn(i,m){
        int a, b; char c;
        cin >> a >> b >> c; a--; b--;
        g[a].pb({c,b}); g[b].pb({c,a});
    }
    vector<int> v = bfs(g);
    
    vector<int> path, prev(n);
    vector<char> prevc(n,'z'+1);
    vector<pair<char,int>> next;
    string s;
    vi act={0};
    prev[0]=-1;
    char z;
    while(act[0]!=n-1){
        z='z';
        for(auto &x : act){
            for(auto &[c,u] : g[x]) if(v[u]==v[x]-1 and c<prevc[u]){
                next.pb({c,u});
                z=min(z,c);
                prev[u]=x;
                prevc[u]=c;
            }
            g[x].clear();
        }
        act.clear();
        for(auto &[c,u] : next) if(c==z) act.pb(u);
        s+=z;
        next.clear();
    }
    int x=n-1;
    while(prev[x]!=-1){
        path.pb(x);
        x=prev[x];
    }
    path.pb(0);
    reverse(all(path));
    cout << SZ(path)-1 << "\n";
    for(auto &u : path) cout << u+1 << " ";
    cout << "\n";
    cout << s << "\n";
    return 0; 
}