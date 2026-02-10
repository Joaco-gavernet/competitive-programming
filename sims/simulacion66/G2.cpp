#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
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


int main() {
	FIN;
	int n, m; cin >> n >> m;
	vector <string> v(n);
	forn(i,n) cin >> v[i];
	set <int> s;
	for(int i = n-1; i>=0; i--) for(int j=m-1; j>=0; j--) if(v[i][j]=='C'){
		auto p=s.lower_bound(j);
		if(p!=s.end()) s.erase(p);
		s.insert(j);
	}
	cout << SZ(s) << "\n";
	return 0;
}
