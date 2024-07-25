#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define forr(i,a,b) for (int i = (a); i < b; i++)
#define forn(i,n) forr(i,0,n)
#define all(c) (c).begin(),(c).end()

int main() {

	int t; cin >> t;
	while (t--) {
		int n,m,k; cin >> n >> m >> k;
		for (int i = n; i > m; i--) cout << i << ' ';
		for (int i = 1; i <= m; i++) cout << i << ' ';
		cout << endl;
	}


	return 0;
}
