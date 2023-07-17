#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

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

//~ bool good(ll x, ll burguers, vector<int> &n, vector<int> &p, vector<int> &needed, ll rubles) {
	//~ dbg(x,n,p,needed);
	//~ // x:      aproximation
	//~ // n:      vector of stocked ingredients
	//~ // p:      vector of prices
	//~ // needed: needed ingredients for recipe
	
	//~ // step 2: completion
	//~ forn(i,3) {
		//~ if (n[i] < needed[i]) {
			//~ int difference = needed[i] - n[i]; // items needed
			//~ if (rubles < (needed[i] - n[i]) * p[i]) break; // if there isn't enough to buy
			//~ else {
				//~ rubles -= (needed[i] - n[i]) * p[i];
				//~ n[i] += difference;
			//~ }
		//~ }
	//~ }
	//~ if (n[0] == needed[0] && n[1] == needed[1] && n[2] == needed[2]) burguers++;
	//~ cout << "step 2: " << burguers << "\n";
	
	//~ // step 3: block finishing
	//~ if (rubles > 0) {
		//~ int block = 0;
		//~ forn(i,3) block += needed[i] * p[i];
		//~ while (rubles >= block) burguers++,rubles-=block;
	//~ }
	
	//~ return burguers >= x;
//~ }


int main(){
	FIN;
	
	string recipe;
	vector<int> needed = {0,0,0};
	vector<int> n(3);
	vector<int> p(3);
	ll rubles;
	
	cin >> recipe;
	forn(i,3) cin >> n[i];
	forn(i,3) cin >> p[i];
	cin >> rubles;
	
	forn(i,recipe.length()) {
		if (recipe[i] == 'B') needed[0]++;
		else if (recipe[i] == 'S') needed[1]++;
		else if (recipe[i] == 'C') needed[2]++;
	}
	
	// step 1: initialization of burguers
	ll burguers = 0;
	int a = 0,b = 0,c = 0;
	if (needed[0] != 0 && n[0] % needed[0] == 0) // pair breads
		a = n[0] / needed[0];
	if (needed[1] != 0 && n[1] % needed[1] == 0) // pair sausage
		b = n[1] / needed[1];
	if (needed[2] != 0 && n[2] % needed[2] == 0) // pair cheese
		c = n[2] / needed[2];
	
	if (a != 0 && b != 0 && c != 0) {
		int homeBurguers = min({a,b,c});
		burguers += (ll)homeBurguers;
		forn(i,3) n[i] -= homeBurguers * needed[i];
	}
	
	// step 2: completion
	forn(i,3) {
		if (n[i] < needed[i]) {
			int difference = needed[i] - n[i]; // items needed
			if (rubles < (needed[i] - n[i]) * p[i]) break; // if there isn't enough to buy
			else {
				rubles -= (needed[i] - n[i]) * p[i];
				n[i] += difference;
			}
		}
	}
	if (n[0] >= needed[0] && n[1] >= needed[1] && n[2] >= needed[2]) burguers++;
	
	// step 3: block finishing
	if (rubles > 0) {
		int block = 0;
		forn(i,3) block += needed[i] * p[i];
		burguers += rubles/block;
	}
	
	// print answer
	cout << burguers << "\n";
	
	return 0;
}









