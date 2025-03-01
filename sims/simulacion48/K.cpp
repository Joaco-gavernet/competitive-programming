#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb;
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) forr(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define pb push_back
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=============================\n"
#define DBGV(v,n) cerr << #v << " = "; forn(_,n) cerr << v[_] << ' '; cerr << endl

void f1(string &s) {
	for (char &c: s) {
		if (c == 'q') c = 'p';
		else if (c == 'p') c = 'q';
		else if (c == 'b') c = 'd';
		else if (c == 'd') c = 'b';
	}
	reverse(all(s)); 
}

void f2(string &s) {
	for (char &c: s) {
		if (c == 'q') c = 'd';
		else if (c == 'p') c = 'b';
		else if (c == 'b') c = 'p';
		else if (c == 'd') c = 'q';
	}
}

void f3(string &s) {
	for (char &c: s) {
		if (c == 'q') c = 'b';
		else if (c == 'p') c = 'd';
		else if (c == 'b') c = 'q';
		else if (c == 'd') c = 'p';
	}
	reverse(all(s)); 
}


int main() {
	FIN; 

	string s; cin >> s;
	string ops; cin >> ops; 

	map<char,int> tr; 
	tr['h'] = 1;
	tr['v'] = 2;
	tr['r'] = 3; 

	vi st; 
	for (char c: ops) st.pb(tr[c]);

	int z = 0; 
	for (int x: st) z ^= x; 

	if (z == 1) f1(s);
	else if (z == 2) f2(s);
	else if (z == 3) f3(s); 
	
	cout << s << '\n'; 

	return 0; 
} 
