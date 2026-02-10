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
	int n, a, b; cin >> n >> a >> b;
	vi v(n+1), u(n+1), l(n+1), r(n+1);
	forn(i,a) cin >> v[i];
	forn(i,b) cin >> v[n-i];
	forn(i,n+1){
		u[v[i]]=i;
		l[i]=i-1;
		r[i]=i+1;
	}
	ll ans=0;
	forr(i,1,n+1){
		int j=u[i];
		if(l[j]==u[0] or r[j]==u[0]) ans++;
		if(l[j]>-1) r[l[j]]=r[j];
		if(r[j]<n+1) l[r[j]]=l[j];
	}
	cout << ans << "\n";
	return 0;
}
