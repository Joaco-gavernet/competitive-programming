#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define pb push_back
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=================================\n"


int main() {
	FIN;
	ll n, q; cin >> n >> q;
	string s; cin >> s;
	vi a(n+1), b(n+1);
	forn(i,n){
		a[i+1]+=a[i];
		b[i+1]+=b[i];
		if(s[i]=='4') a[i+1]++;
		else b[i+1]++;
	}
	while(q--){
		ll l, r, x, y; cin >> l >> r >> x >> y;
		x=abs(x); y=abs(y);
		l--; r--;
		ll t=a[r+1]-a[l], p=b[r+1]-b[l];
		x-=p; y-=p;
		x=max(x,0LL); y=max(y,0LL);
		if(x+y<=t) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
