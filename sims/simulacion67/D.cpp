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
	ll n; cin>>n;
	vi nums(n);
	vi histo(n+1);
	forn(i,n){
		cin>>nums[i];
		histo[nums[i]]++;
	}
	ll ans=0;
	forn(i,n+1){
		if(histo[i]>i) ans+=(histo[i]-i);
		else if(histo[i]<i) ans+=histo[i];
	}
	cout<<ans<<"\n";

	return 0;
}
