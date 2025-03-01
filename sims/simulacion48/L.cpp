#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb;
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define pb push_back
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=============================\n"
#define DBGV(v,n) cerr << #v << " = "; forn(_,n) cerr << v[_] << ' '; cerr << endl

void solve(){
// 	ll k,a,b,c,ab,bc,ac,abc,ans=0;
// 	cin >> k >> a >> b >> c >> ab >> bc >> ac >> abc;
// ans+=a/k+b/k+c/k;
// a%=k; b%=k; c%=k;
	vector <int> p(3);
	forn(i,3) p[i]=i;
	while(true){
		forn(i,3) cout << p[i] << " ";
		cout << endl;
		if(!next_permutation(all(p))) break;
	}
}

int main() {
	FIN; int t; cin >> t;
	while(t--) solve();
	return 0; 
} 
