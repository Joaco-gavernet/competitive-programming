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

const ll INF = 1e18;

int main() {
	FIN;
	ll n,m; cin>>n>>m;
	vector<pair<ll,ii>> ar(m);
	vi cost(n-1,INF);
	forn(i,m){
		cin>>ar[i].ss.ff>>ar[i].ss.ss>>ar[i].ff;
		ar[i].ss.ff--;
	}
	sort(all(ar)); reverse(all(ar));
	ll ans=0;
	ll enable=0;
	ll q; cin>>q;
	vector<ii> queries(q);
	forn(i,q) cin>>queries[i].ff, queries[i].ss=i;
	vi v(q);
	sort(all(queries));
	reverse(all(queries));
	ll w=ar[0].ff;
	ll punt=0;
	// while(punt<q and queries[punt].ff>w) v[queries[punt].ss]=ans, punt++;
	ll i=0;
	while(i<m){
		w=ar[i].ff;
		while(punt<q and queries[punt].ff>w){
			// DBG(queries[punt].ff); DBG(enable);
			if(enable<n-1) v[queries[punt].ss]=-1;
			else v[queries[punt].ss]=ans; 
			punt++;
		}
		if(punt==q) break;
		while(i<m and ar[i].ff == w){
			if(cost[ar[i].ss.ff]==INF) enable++;
			else ans-=cost[ar[i].ss.ff];
			cost[ar[i].ss.ff]=min(cost[ar[i].ss.ff],ar[i].ss.ss);
			ans+=cost[ar[i].ss.ff];
			i++;
		}
		
	}
	while(punt<q) v[queries[punt].ss]=ans, punt++;
	forn(i,q){
		if(v[i]==-1) cout<<"impossible\n";
		else cout<<v[i]<<"\n";
	}
	return 0;
}
