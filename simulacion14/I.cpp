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

const int MOD = -1;
const int MAXN = -1;
const int INF = -1;

int main() {
	FIN;

	int n; cin >> n;
	string s; cin >> s;
	
	int pos = 0;
	int neg = 0;
	int dud = 0;
	for (char x: s) {
		if (x == 'P') pos++;
		else if (x == 'N') neg++;
		else dud++;
	}
	
	string ans;
	if (pos > neg +dud) ans = "SI";
	else if (neg >= pos +dud) ans = "NO";
	else ans = "INDECISOS";
	
	cout << ans << endl;

	return 0;
}
