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
	vector<int> base={4,6,2};
	vector<int> patron={4,8,3,2,6,1,2,2};
	forn(i,4){
		int x; cin>>x;
		x--;
		if(x<3){
			cout<<base[x];
		}else{
			x=x-3;
			cout<<patron[x%8];
		}
	}
	cout<<"\n";
	return 0;
}
