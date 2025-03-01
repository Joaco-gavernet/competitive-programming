#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb;
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define pb push_back
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=============================\n"
#define DBGV(v,n) cerr << #v << " = "; forn(_,n) cerr << v[_] << ' '; cerr << endl

struct ola{
	ll p,l,a;
	ola(){}
	ola(ll x,ll b,ll c){
		p=x;
		l=b;
		a=c;
	}
};

int main() {
	FIN; 
	ll n,w; cin>>n>>w;
	vector<ola> waves;
	forn(i,n){
		char c; cin>>c;
		if(c=='!'){
			ll p,l,a; cin>>p>>l>>a;
			waves.pb(ola(p,l,a));
		}else{
			ll ans=0;
			ll pos; cin>>pos;
			for(auto u:waves){
				if(u.p <=pos and u.p+u.l-1 >=pos and (pos-u.p)%2==0){
					if((pos-u.p)%4==0) ans+=u.a;
					else ans-=u.a;
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0; 
} 
