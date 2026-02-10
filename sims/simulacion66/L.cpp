#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef vector<int> vi;
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

const string word = "WALDO";
bool check(vi &act) {
	for (char c: word) if (act[c -'A'] == 0) return false;
	return true; 
}

int main() {
	FIN;

	int h, w; cin >> h >> w; 
	vector<string> mat(h); forn(i,h) cin >> mat[i];
	
	if (h < w) {
		// transpose matrix
		vector<string> aux(w, string(h, '#'));
		forn(y,h) forn(x,w) aux[x][y] = mat[y][x];
		// forn(y,w) DBG(aux[y]);
		swap(h, w);
		mat = aux; 
	}

	// debug
	// forn(y,h) DBG(mat[y]);
	
	ll best = 1<<20;
	vector<vi> v(h, vi(26));
	forr(l,0,w) {
		forr(r,l,w) {
			// preprocessing 
			forr(y,0,h) v[y][mat[y][r] -'A']++;

			vi act(26);
			int up = 0, down = 0;
			
			while (up < h) {
				while (down < h and check(act) == false) {
					for (char c: word) act[c-'A'] += v[down][c-'A'];
					down++;
				}
				if(down==h and !check(act)) break;
				ll tot = (r -l +1) * (down -up);
				while (up < down -1 and check(act)) {
					best = min(best, tot);
					for (char c: word) act[c-'A'] -= v[up][c-'A'];
					tot -= (r -l +1);
					up++;
				}
			}
		}
		forn(_,h) for (char c: word) v[_][c-'A']=0;
	}
	if(best>w*h) cout << "impossible\n";
	else cout << best << '\n'; 
	
	return 0;
}
