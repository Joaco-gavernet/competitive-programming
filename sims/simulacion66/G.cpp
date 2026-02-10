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
	int n, m; cin >> n >> m;
	vector <string> v(n);
	forn(i,n) cin >> v[i];
	vector <vi> dp(n, vi(m));
	vector <vb> r(n, vb(m,false)), d(n, vb(m,false));
	for(int i = n-1; i>=0; i--) for(int j=m-1; j>=0; j--){
		if(i<n-1) d[i][j]=d[i][j] or d[i+1][j];
		if(j<m-1) r[i][j]=r[i][j] or r[i][j+1];
		if(i<n-1 and j<m-1){
			if(dp[i+1][j]!=dp[i][j+1]) dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
			else if(dp[i+1][j]>dp[i+1][j+1]) dp[i][j]=dp[i+1][j]+2;
			else if(dp[i+1][j]!=1) dp[i][j]=dp[i+1][j];
			else if(r[i][j] and d[i][j]) dp[i][j]=2;
			else dp[i][j]=1;
		}
		if(v[i][j]=='C') {r[i][j]=true; d[i][j]=true;}
		if(r[i][j]) dp[i][j]=max(dp[i][j],1LL);
		cout << i << " " << j << " " << dp[i][j] << endl;
	}
	cout << dp[0][0] << "\n";
	return 0;
}
