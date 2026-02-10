#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
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
	cout<<fixed<<setprecision(10);
	ll d,s,e; cin>>d>>s>>e;
	ld ans=(d-s);
	ans/=d;
	// DBG(ans);
	if(s < d-s-e){
		ans*=s;
		ans/=(d-e-s);
		// DBG(ans);
	}else{
		ld aux=2*s+e-d;
		aux/=d;
		ans+=aux;
		// DBG(ans);
	}
	cout<<ans<<"\n";
	return 0;
}
