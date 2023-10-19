#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i = 0; i < n; i++)

int main() {
	
	int t; cin >> t;
	vector<string> v(3);

	forn(_,t) {
		string res = "DRAW";
		forn(i,3) cin >> v[i];
		forn(i,3) if (v[i][0] == v[i][1] and v[i][1] == v[i][2]) res = v[i][1];
		forn(i,3) if (v[0][i] == v[1][i] and v[1][i] == v[2][i]) res = v[1][i];
		if (v[1][1] == v[0][0] and v[0][0] == v[2][2]) res = v[1][1];			
		if (v[1][1] == v[0][2] and v[0][2] == v[2][0]) res = v[1][1];			
		cout << res << '\n';
	}

	return 0;
}
