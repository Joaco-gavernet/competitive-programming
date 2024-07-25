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
		vi v(3); forn(i,3) cin >> v[i];

		forn(_,5) {
			sort(all(v));
			forn(i,3) cerr << v[i] << ' ';
			cerr << endl;
			v[0]++;
		}

		/*
		int tot = 5;
		int dif = v[1] - v[0];
		if (dif >= tot) tot = 0, v[0] += 5;
		else {
			tot -= dif;
			v[0] += dif;

			dif = v[2] - v[0];
			while (tot > 0) {
				v[1]++; tot--;
				if (tot > 0) v[0]++, tot--;
			}

		}
		*/

		cout << v[0] * v[1] * v[2] << endl;
	}


	return 0;
}
