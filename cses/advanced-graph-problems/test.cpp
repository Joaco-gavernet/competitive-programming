#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb; 
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl
#define ff first
#define ss second
#define RAYA cerr << "==========================" << endl

struct UnionFind {
    int n,comp;
    vector<int> uf,si,c;
    UnionFind(int n=0):n(n),comp(n),uf(n),si(n,1){
        forr(i,0,n)uf[i]=i;}
    int find(int x){return x==uf[x]?x:find(uf[x]);}
    bool join(int x, int y){
        if((x=find(x))==(y=find(y)))return false;
        if(si[x]<si[y])swap(x,y);
        si[x]+=si[y];uf[y]=x;comp--;c.pb(y);
        return true;
    }
    int snap(){return c.size();}
    void rollback(int snap){
        while(c.size()>snap){
            int x=c.back();c.pop_back();
            si[uf[x]]-=si[x];uf[x]=x;comp++;
        }
    }
};
 
struct Edge { int a, b; ll w; };
struct Node { /// lazy skew heap node
	Edge key;
	Node *l, *r;
	ll delta;
	void prop() {
		key.w += delta;
		if (l) l->delta += delta;
		if (r) r->delta += delta;
		delta = 0;
	}
	Edge top() { prop(); return key; }
};
 
Node *merge(Node *a, Node *b) {
	if (!a || !b) return a ?: b;
	a->prop(), b->prop();
	if (a->key.w > b->key.w) swap(a, b);
	swap(a->l, (a->r = merge(b, a->r)));
	return a;
}
void pop(Node*& a) { a->prop(); a = merge(a->l, a->r); }
 
pair<ll, vi> dmst(int n, int r, vector<Edge>& g) {
	UnionFind uf(n);
	vector<Node*> heap(n);
	for (Edge e : g) heap[e.b] = merge(heap[e.b], new Node{e});
	ll res = 0;
	vi seen(n, -1), path(n), par(n);
	seen[r] = r;
	vector<Edge> Q(n), in(n, {-1,-1}), comp;
	deque<tuple<int, int, vector<Edge>>> cycs;
	forr(s,0,n) {
		int u = s, qi = 0, w;
		while (seen[u] < 0) {
			if (!heap[u]) return {-1,{}};
			Edge e = heap[u]->top();
			heap[u]->delta -= e.w, pop(heap[u]);
			Q[qi] = e, path[qi++] = u, seen[u] = s;
			res += e.w, u = uf.find(e.a);
			if (seen[u] == s) { /// found cycle, contract
				Node* cyc = 0;
				int end = qi, time = uf.snap();
				do cyc = merge(cyc, heap[w = path[--qi]]);
				while (uf.join(u, w));
				u = uf.find(u), heap[u] = cyc, seen[u] = -1;
				cycs.push_front({u, time, {&Q[qi], &Q[end]}});
			}
		}
		forr(i,0,qi) in[uf.find(Q[i].b)] = Q[i];
	}
 
	for (auto& [u,t,comp] : cycs) { // restore sol (optional)
		uf.rollback(t);
		Edge inEdge = in[u];
		for (auto& e : comp) in[uf.find(e.b)] = e;
		in[uf.find(inEdge.b)] = inEdge;
	}
	forr(i,0,n) par[i] = in[i].a;
	return {res, par};
}

ll cont=1;

void solve(){
    ll n; cin>>n;
    ll m; cin>>m;
    vector<Edge> fonos(n);
    forn(i,m){
        ll a,b,c; cin>>a>>b>>c;
				fonos.pb({a, b, c}); 
    }
    pair<ll,vi> ans = dmst(n, 0, fonos);
    cout<<"Case #"<<cont<<": ";
    if(ans.ff ==-1) cout<<"Possums!"<<"\n";
    else cout<<ans.ff <<"\n";
}

int main() {
    FIN;
    ll t; cin>>t;
    while(t--) solve(),cont++;
    return 0; 
}