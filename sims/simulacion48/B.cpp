#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb;
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) forr(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define pb push_back
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=============================\n"
#define DBGV(v,n) cerr << #v << " = "; forn(_,n) cerr << v[_] << ' '; cerr << endl


int main() {
	FIN; 
	ll n,h; cin>>n>>h;
	ll ans=0;
	while(n--){
		vi dims(3); cin>>dims[0]>>dims[1]>>dims[2];
		sort(all(dims));
		if(dims[0]>h){
			cout<<"impossible\n";
			return 0;
		}
		if(dims[1]>h) ans+=dims[1];
		else ans+=dims[0];
	}
	cout<<ans<<"\n";
	return 0; 
} 
