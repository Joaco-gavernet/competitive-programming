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
	
	int n; cin >> n;
	vi v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	
	vi ref(n, -5e5);
	for (int i = 0; i < n; i++) ref[i] += i; 

	vi act(n);
	for (int i = 0; i < n; i++) act[i] = ref[i] - v[i];

	sort(all(act));
	ll med = act[n/2]; 
	ll ans = 0;
	for (auto x: act) ans += abs(x -med);

	cout << ans << '\n'; 


	return 0; 
} 
