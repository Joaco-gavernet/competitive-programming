/*   AUTHOR: Estufa en Piloto   */
#include <bits/stdc++.h>
using namespace std;

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
typedef vector<ll> vi; typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define SZ(x) int((x).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())
const int INF = 1<<30; // const ll INF = (1LL<<60);
const int MOD = 1e9+7;  // const int MOD = 998244353;
const int MAXN  = 2e5+5;

struct arista {
	int start;
	int end;
	int w;
};

struct query {
	int start;
	int end;
	int x;
	int id;
};

vector <vector<int>> solve(int start_node, vector <arista> &edges, int n) {
	vector <vector<int>> ans;
	vector <int> dist(n,INF); dist[start_node] = 0;
	ans.pb(dist);
	forr(i,1,n) {
		vector <int> next_dist(n,INF);
		for(arista u : edges) {
			next_dist[u.end] = min(next_dist[u.end],dist[u.start]+u.w);
		}
		ans.pb(next_dist);
		dist = next_dist;
	}
	return ans;
}

int main(){  
    FIN;

	int n, m, q;
	cin >> n >> m >> q;
	vector <arista> lista_aristas(m);
	forn(i,m) {
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		lista_aristas[i] = {u,v,w};
	} 
	
	vector <vector <query>> queries(n+5);
	
	forn(i,q) {
		int u, v, x;
		cin >> u >> v >> x;
		u--; v--;
		queries[u].pb({u,v,x,int(i)});
	}
	
	vector <int> ans(q);
	
	forn(i,n) {
		vector <vector <int>> dist = solve(int(i),lista_aristas, n);
		
		for(query u : queries[i]) {
			int ans_aux = INF;
			forn(j,n) {
				ans_aux = min(ans_aux,dist[j][u.end] + u.x*(int(j)+1));
			}
			ans[u.id] = ans_aux;
		}
	}
	
	forn(i,q) {
		if(ans[i] == INF) {
			cout << "-1\n";
		}
		else {
			cout << ans[i] << "\n";
		}
	}

    return 0;
}
