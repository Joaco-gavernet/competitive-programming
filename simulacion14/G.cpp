#include <bits/stdc++.h> 
using namespace std;


typedef long long ll;
typedef vector<ll> vi; typedef vector<bool> vb;
typedef pair<int,int> pi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fs first
#define ss second

const int MOD = -1;
const int MAXN = -1;
const int INF = -1;

int main() {
	FIN;

	int n; cin >> n;
	vector<pi> v(n); forn(i,n) cin >> v[i].fs >> v[i].ss;
	
	ll tot = 0;
	forn(i,n) {
		int x = v[i].fs;
		int y = v[i].ss;
		
		forn(j,n) {
			if (j == i) continue;
			forn(k,n) {
				if (k == j or k == i) continue;
				ll a = (v[j].fs -x) * (v[k].fs -x);
				ll b = (v[j].ss -y) * (v[k].ss -y);
				ll aux = a + b;
				if (aux == 0) tot++;
			}
		}
	}
	
	cout << tot/2 << endl;

	return 0;
}
