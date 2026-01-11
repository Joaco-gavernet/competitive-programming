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
	ll n, m; cin >> n >> m;
	vi a(n), b(m);
	forn(i,n) cin >> a[i];
	forn(i,m) cin >> b[i];
	vector <vector<vb>> dp(m,vector<vb>(n,vb(2,false)));
	forr(j,b[0]-1,n) dp[0][j][0]=true;
	if(a[0]==b[0]) dp[0][0][1]=true;
	int last=n+1, last2=n+1;
	forn(j,n) if(dp[0][j][0] or dp[0][j][1]) {last=j; break;}
	forn(j,n) if(dp[0][j][0]) {last2=j; break;}
	if(last==n+1){cout << "NO\n"; return;}
	forr(i,1,m){
		forr(j,last+b[i],n) dp[i][j][0]=true;
		forn(j,n) if(j>0 and b[i]==a[j] and (j>last2 or dp[i-1][j-1][1])) dp[i][j][1]=true;
		last=n+1; last2=n+1;
		forn(j,n) if(dp[i][j][0] or dp[i][j][1]) {last=j; break;}
		forn(j,n) if(dp[i][j][0]) {last2=j; break;}
		if(last==n+1){cout << "NO\n"; return;}
	}
	if(dp[m-1][n-1][0] or dp[m-1][n-1][1]) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	FIN;
	ll t; cin>>t;
	while(t--) solve();
	return 0;
}
