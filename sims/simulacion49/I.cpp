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
	ll n; cin>>n;
	vi h(n),v(n);
	forn(i,n) cin>>h[i]; 
	forn(i,n) cin>>v[i];
	ll ans=v[0]-h[0];
	if(ans<0) cout<<"0\n";
	else{
		ll pos=0;
		while(pos<n and h[pos]+ans == v[pos]) pos++;
		if(pos==n or h[pos] +ans > v[pos]) cout<<ans<<"\n";
		else cout<<ans+1<<"\n";
	}
	return 0;
} 

