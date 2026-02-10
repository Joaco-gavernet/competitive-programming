#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 
typedef pair<ll,ll> ii; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size()) 
#define all(v) begin(v),end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "========================\n" 

int main() {
	FIN;
	int n; cin >> n;
	vi d(n-1);
	ll x, y; cin >> x >> y;
	forn(i,n-1){
		ll a, b;
		cin >> a >> b;
		d[i]=abs(a-x)+abs(b-y);
		x=a; y=b;
	}
	ll l=1, r=d[0]-1, s=0;
	forn(i,n-1){
		s+=d[i]*(1-i%2*2);
		if(i%2==0) r=min(r,s-1);
		else l=max(l,s+1);
	}
	if(r<l) cout << "-1\n";
	else cout << r << "\n";
	return 0; 
} 
