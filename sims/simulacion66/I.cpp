#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i<(ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define ff first
#define ss second 
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "===========================\n"

ll n,m;

vector<vector<vi>> func;
vi state;

bool solve(ll i,ll j){
	vector<vector<vector<vi>>> g(n,vector<vector<vi>>(m,vector<vi>(m,vi(m,0))));
	// if(func[i][j][k]!=state[0]) return false;
	// g[0][i][j][k]=1;
	forn(a,m) if(func[i][j][a]==state[0]){
		if(n==1) return true;
		else g[0][i][j][a]=1;
	}
	forr(next,0,n) forn(x,m) forn(y,m) forn(z,m) if(g[next][x][y][z]){
		forn(a,m) if(func[y][z][a]==state[(next+1)%n]){
			if(next==n-1){
				if(z==j and y == i) return true;
			}
			else g[next+1][y][z][a]=1;
		}
	}
	// forn(p,n) forn(i,m) forn(j,m) forn(k,m) if(g[p][i][j][k]){
	// 	cerr<<p<<" "<<i<<" "<<j<<" "<<k<<"\n";
	// } 
	// RAYA;
	return false;
}

int main() {
	FIN;
	cin>>n>>m;
	vector<vector<vi>> aux(m,vector<vi>(m,vi(m)));
	forn(i,m) forn(j,m) forn(k,m) cin>>aux[i][j][k];
	forn(i,n){
		ll x; cin>>x;
		state.pb(x);
	}
	func=aux;
	forn(i,m) forn(j,m){
		// if(func[i][j][k]==state[0]) DBG(i), DBG(j), DBG(k);	
		if(solve(i,j)){
			cout<<"yes\n";
			return 0;
		}
	}
	cout<<"no\n";
	return 0;
}


// 1 1 2 1

// 1 2 1 2