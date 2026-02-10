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

	int n = 10; 
	vi v(n); 
	vb visto(5,false);
	forn(i,n) cin >> v[i], visto[v[i]] = true; 
	int tot = 0;
	forr(i,1,5) if (visto[i] == false) tot++; 
	cout << tot << '\n'; 

	return 0; 
} 
