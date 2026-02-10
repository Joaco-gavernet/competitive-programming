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
	int n; cin >> n;
	vector <string> d(n);
	vi dx(n), dy(n);
	forn(i,n) cin >> d[i] >> dx[i] >> dy[i];
	int m; cin >> m;
	vector <string> kn(m);
	forn(i,m) cin >> kn[i];
	int q, _k; cin >> q >> _k;
	while(q--){
		int f; cin >> f;
		vector <string> s(f);
		forn(i,f) {cin >> s[i]; cout << s[i] << " ";}
		bool listo=false;
		for(int k=_k; k>0; k--){
			ll x=0, y=0;
			forn(i,m-k){
				bool anda=true;
				forr(j,i,i+k) if(s[f-k+j-i]!=kn[j]){anda=false; break;}
				if(!anda) continue;
				forn(j,n) if(d[j]==kn[i+k]) {x+=dx[j]; y+=dy[j]; listo=true;}
			}
			if(!listo) continue;
			ll ans=0;
			forn(i,n) if(dx[i]*x+dy[i]*y>dx[ans]*x+dy[ans]*y) ans=i;
			cout << d[ans] << "\n";
			break;
		}
		if(!listo) cout << "*\n";
	}

	return 0; 
} 
