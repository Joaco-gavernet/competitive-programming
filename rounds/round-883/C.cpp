#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i = 0; i < n; i++)

int main() {
	int t; cin >> t;

	forn(_,t) {
		int n,m,h; cin >> n >> m >> h; 
		int pos = 1, points = 0, penalty = 0;
		vector<int> v(n); forn(i,m) cin >> v[i];
                sort(v.begin(),v.end());
                forn(i,m) {
                      	if (v[i] + penalty > h) break;
                       	penalty += v[i];
                        points++;
                }

		forn(_,--n) {
			int poin = 0, pen = 0;
			vector<int> v(n); forn(i,m) cin >> v[i];
			sort(v.begin(),v.end());
			forn(i,m) {
				if (v[i] + pen > h) break;
				pen += v[i];
				poin++;
			}
			
			if (poin > points) pos++;
			if (poin == points and pen < penalty) pos++;

		}
		cout << pos << '\n';
	}

	return 0;
}
