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
	ll n; cin>>n;
	vi bits(n+1);
	forn(i,n+1) cin>>bits[i];
	reverse(all(bits));
	ll aux=1;
	ll nro=0;
	forn(i,n+1){
		if(bits[i]==1) nro+=aux;
		aux*=2;
	}
	ll ans=0;
	while(nro>1){
		if(nro%2){
			ll doble=nro*2;
			nro=(nro^doble)-1;
			nro/=2;
			ans+=2;
		}else{
			nro/=2; ans++;
		}
	}
	cout<<ans<<"\n";



	return 0; 
} 
