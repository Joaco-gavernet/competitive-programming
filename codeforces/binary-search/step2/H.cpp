#include <bits/stdc++.h>
using namespace std;

// neal Debugger
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
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);

int main(){
	FIN;
	
	string recipe;
	vector<ll> needed(3,0);
	vector<ll> n(3);
	vector<ll> p(3);
	ll rubles;
	
	cin >> recipe;
	forn(i,3) cin >> n[i];
	forn(i,3) cin >> p[i];
	cin >> rubles;
	
	for (char u : recipe) {
		if (u == 'B') needed[0]++;
		if (u == 'S') needed[1]++;
		if (u == 'C') needed[2]++;
	}
	
	ll l = 0;
	ll r = 1e13;
	
	while (r > l + 1) {
		ll m = (l + r)/2;
		ll cost = 0;
		cost += max(0LL, (needed[0]*m - n[0])) * p[0];
		cost += max(0LL, (needed[1]*m - n[1])) * p[1];
		cost += max(0LL, (needed[2]*m - n[2])) * p[2];
		
		if (cost <= rubles) l = m;
		else r = m;
	}
	
	cout << l << "\n";
		
	return 0;
}









