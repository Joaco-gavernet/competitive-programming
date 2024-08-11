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
#define fs first
#define ss second

const int MOD = -1;
const int MAXN = -1;
const int INF = -1;

int main() {
	FIN;

	int n,m; cin >> n >> m;
	
	ll k = (n*(n-1)-(m-1)*(m-2)) / (n -m +1);
	k++;
	
	if (k %2 == 0) cout << k/2 << ".0" << endl;
	else cout << k/2 << ".5" << endl;

	return 0;
}
