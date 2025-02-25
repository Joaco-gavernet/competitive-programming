#include <bits/stdc++.h> 
using namespace std;


typedef long long ll;
typedef vector<ll> vi; typedef vector<bool> vb;
typedef pair<int,int> pi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define all(c) (c).begin(),(c).end()
#define pb push_back

const int MOD = -1;
const int MAXN = -1;
const int INF = -1;

vector<ll> pot2;

ll solve(ll *D,ll M, ll D1){
	if(*D>=D1){return 0;}
	else{ 
		/*
		ll k=1; ll var=2*(D1-*D);
		while((var<D1)and(k<M)){
			var=var*2; k++;
		}
		*D=(D1-var);
		*/
		ll var=D1/(D1-*D);
		if(D1%(D1-*D)!=0){var++;}
		ll k=0;
		while((pot2[k]<var)and(k<M)){k++;}
		*D=(D1-pot2[k]*(D1-*D));
		return k;
	}
}

int main() {
	FIN;
	ll D,M,D1,N,D2; cin>>D>>M>>D1>>N>>D2;
	ll ans=0;
	ll pot=1;
	forn(i,63){
		pot2.pb(pot);
		pot*=2;
	}
	if(M>0){ans=solve(&D,M,D1);}
	//cout<<D<<"   D\n";
	if(D>0){
		if(N>0){ans+=solve(&D,N,D2);}
	}
	if(D>0){ans=-1;}
	if(ans==0){ans--;}
	cout<<ans<<"\n";
	return 0;
}
