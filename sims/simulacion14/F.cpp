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

int main() {
	FIN;
	int n, m;
	cin >> n >> m;
	vi v(m);
	int cont=0;
	forn(i,n){
		int a;
		cin >> a;
		a--;
		if(v[a]==0) cont++;
		v[a]++;
	}
	sort(all(v));
	if(m==4 and cont==3 and v[0]+v[1]+v[2]+v[3]==3) cout << 3 << "\n";
	else if(cont==1) cout << 1 << "\n";
	else if(cont==m) cout << 0 << "\n";
	else if(cont>2) cout << m << "\n";
	else{
		int k=0;
		if(v[m-1]!=1) k++;
		if(v[m-2]!=1) k++;
		cout << m-2+k << "\n";
	}
	return 0;
}
