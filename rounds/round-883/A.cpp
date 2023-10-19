#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i = 0; i < n; i++)

int main() {
	int t; cin >> t;

	forn(_,t) {
		int n; cin >> n;
		int a,b; 
		int tot = 0;
		forn(_,n) {
			cin >> a >> b;
			if (a - b > 0) tot++;
		}
		cout << tot << '\n';
	}

	return 0;
}
