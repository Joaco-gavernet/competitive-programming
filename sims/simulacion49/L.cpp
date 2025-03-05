#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "================================\n" 


int dx[] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1, 0};



int main() {
	FIN;

	int h, w; cin >> h >> w; 
	const int W = w +2; 
	const int H = h +2;

	vector<vi> mat(H, vi(W)); 
	forn(i,H) forn(j,W) cin >> mat[i][j]; 

	vector<vector<char>> ans(h, vector<char>(w, '.')); 
	forn(y,h) {
		forn(x,w) {
			if (mat[y][x] > 0) {
				ans[y][x] = 'X';
				
				forn(i,9) {
					int xi = x +dx[i] +1;
					int yi = y +dy[i] +1;
					if (xi < 0 or xi > W or yi < 0 or yi > H) continue;
					mat[yi][xi]--;
				}
			}
		}
	}

	// check if impossible
	forn(y,H) forn(x,W) if (mat[y][x] != 0) {
		cout << "impossible\n";
		return 0;
	}

	for (auto v: ans) {
		for (auto x: v) cout << x; 
		cout << '\n'; 
	}

	return 0;
} 

