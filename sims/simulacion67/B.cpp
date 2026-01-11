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

void solve(){
	ll n,l,r; cin>>n>>l>>r;
	vi bets(n);
	forn(i,n) cin>>bets[i];
	sort(all(bets));
	ll pl=0,pr=n-1;
	ll ans=0;
	while(pl<pr and bets[pr]>l and bets[pl]<r){
		ll a=bets[pl],b=bets[pr];
		ans+=(b-a);
		pl++; pr--;
	}
	if(bets[pr]<=l){
		forr(i,pl,pr+1) ans+=(l-bets[i]);
	}if(bets[pl]>=r){
		forr(i,pl,pr+1) ans+=(bets[i]-r);
	}
	cout<<ans<<"\n";
}

int main() {
	FIN;
	ll t; cin>>t;
	while(t--) solve();

	return 0;
}
