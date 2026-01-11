#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define pb push_back
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=================================\n"

#define MAXN 4905

void solve(){
	int n, m; cin >> n >> m; 
	vector<vi> orig(n, vi(m));
	vector<bitset<MAXN>> v(n);
	vi ans = {0}; 

	map<ll,ll> connect;
	
	forn(i,n) {
		forn(j,m) {
			cin >> orig[i][j];
			if(j>0) connect[orig[i][j-1]]= orig[i][j];
			v[i][orig[i][j]] = 1;
		}
	}

	if(n==1){
		forn(i,m/2) cout<<orig[0][i]<<" ";
		cout<<"\n";
		return;
	}

	if(m==1){
		forn(i,n/2) cout<<i+1<<" ";
		cout<<"\n";
		return;
	}

	bitset<MAXN> act = v[0], aux;
	forr(i,1,n) {
		aux = act;
		aux &= v[i];
		if (aux.count() == 0) {
			act |= v[i];
			ans.pb(i);
		}
	}

	if (n%2) {
		int prox = -1;

		// encuentro el inicio de la permutacion
		forr(i,1,n) {
			aux = act;
			aux &= v[i];
			if (aux.count() == m/2 and aux[orig[i][0]] == 0) {
				act |= v[i];
				ans.pb(i);
				prox = orig[i][m/2];
				break;
			}
		}

		// recorro el grafo e imprimo filas
		ll tam = SZ(ans);
		forn(_,tam-1){
			for(auto u:ans) if(orig[u][0]==prox){
				for (auto x: orig[u]) cout << x << ' ';
				prox=connect[orig[u][m-1]];
				auto it = find(all(ans), u);
				ans.erase(it);
				break;
			}
		}
		forn(j,m/2) cout << orig[ans[0]][j] << ' ';
	} else for (auto x: ans) for (auto y: orig[x]) cout << y << ' ';
	cout << '\n';
}

int main() {
	FIN;
	ll t; cin>>t;
	while(t--) solve();
	return 0;
}
