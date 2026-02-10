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
	int n; cin >> n;
	vector <pair<ll,ii>> v(n);
	ll b=0, c=0;
	forn(i,n){
		string s; cin >> s >> v[i].ss.ff >> v[i].ss.ss;
		b+=v[i].ss.ff;
		ll p=0;
		forn(j,SZ(s)) if(s[j]!='.'){
			p*=10;
			p+=s[j]-'0';
		}
		v[i].ff=p;
	}
	sort(all(v));
	ii ans={-1,-1};
	forn(i,n){
		c+=v[i].ss.ss;
		ii aux={min(b,c)*v[i].ff,v[i].ff};
		ans=max(ans,aux);
		b-=v[i].ss.ff;
	}

	if(ans.ff==-1 or ans.ff==0) cout << "impossible\n";
	else{
		cout << ans.ss/100 << ".";
		int k=ans.ss%100;
		if(k<10) cout << 0;
		cout << k;
		cout << " ";
		cout << ans.ff/100 << ".";
		k=ans.ff%100;
		if(k<10) cout << 0;
		cout << k;
		cout << "\n";
	}
	return 0;
}
