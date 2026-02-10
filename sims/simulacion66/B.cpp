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
	string s; cin>>s;
	ll n=SZ(s);
	ll corte=1;
	forn(i,n-1){
		// DBG(s[n-1-i]);
		if(s[n-1-i]=='a' or s[n-1-i]=='e' or s[n-1-i]=='i' or s[n-1-i]=='o' or s[n-1-i]=='u'){
			corte=n-i;
			break;
		}
		// DBG(corte);
	}
	string ans=s.substr(0,corte);
	ans+="ntry";
	cout<<ans<<"\n";
	return 0;
}
