#include <bits/stdc++.h>
using namespace std;



int main() {
	int t; cin >> t;
	while (t--) {
		int n,m; cin >> n >> m;
		string a,b; cin >> a >> b;

		int i = 0, j = 0;
		while (i < n and j < m) {
			while (j < m and a[i] != b[j]) j++;
			if (j < m and a[i] == b[j]) i++;
			j++;
		}
		cout << i << '\n';
	}

	return 0;
}


/*
 
3 3
100
110

*/
