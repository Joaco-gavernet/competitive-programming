#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "================================\n" 


int main() {
	FIN;
	int n; cin >> n;
	map <ll, ll> m;
	forn(i,n){
		ll x; cin >> x;
		if(x==1 and m[1]!=0) {cout << m[x] << " " << i+1 << "\n"; return 0;}
		m[x]=i+1;
	}
	ll a=1, b=1;
	while(a+b<1000001){
		b+=a; swap(a,b);
		if(m[a]!=0 and m[b]!=0) {cout << m[b] << " " << m[a] << "\n"; return 0;}
	}
	cout << "impossible\n";
	return 0;
} 

