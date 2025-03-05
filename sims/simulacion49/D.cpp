#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "================================\n" 


int main() {
	FIN;
	ll n; cin>>n;
	vi v(n); forn(i,n) cin>>v[i];
	ll p1=0,p2=v[0];
	forn(i,n){
		if(v[i]<p1 and v[i]<p2){cout<<"0\n"; return 0;}
		p1=max(v[i]-p1,(ll)0);
		p2=max(v[i]-p2,(ll)0);
	}
	cout<<abs(p1-p2)+1<<"\n";
	return 0;
} 

