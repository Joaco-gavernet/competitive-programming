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

const ll INF = 1e18;

void solve(){
	ll n,k; cin>>n>>k;
	vi histo(2*n,0);
	forn(i,n){
		ll x; cin>>x; x--;
		histo[x]++;
	}
	ll ans=0;
	ll last=2*n;
	set<ll> ceros;
	ceros.insert(2*n);
	for(ll pos=2*n-1;pos>=0;pos--){
		if(histo[pos]>0){
			ll aux=(histo[pos]-k);
			ll extras=aux;
			ll repetidos=histo[pos]-1;
			ll act=pos;
			// DBG(pos); DBG(extras); DBG(repetidos);
			while(repetidos and SZ(ceros)){
				ll prox=*(ceros.begin());
				// DBG(prox); DBG(act);
				if(extras>0) aux+=(prox-act)-1;
				extras--;
				repetidos--;
				ceros.erase(ceros.begin());
				act=prox;
			}
			// RAYA;
			if(SZ(ceros)==0){
				last+=repetidos +1;
				ceros.insert(last);
			}
			if(histo[pos]>k) ans=max(ans,aux);
		}else ceros.insert(pos);
	}
	cout<<ans<<"\n";
}

int main() {
	FIN;
	ll t; cin>>t;
	while(t--) solve();
	return 0;
}
