#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "===============================" << endl
#else
#define DBG(x)
#define RAYA
#endif
 
typedef long long ll;
typedef vector<ll> vi; typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define SZ(x) int((x).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())
const int INF = 1<<30; // const ll INF = (1LL<<60);
const int MOD = 1e9+7;  // const int MOD = 998244353;
//const int MAXN = 1e6;		//Poner esto en 1e6

#ifdef LOCAL
const int MAXN=100;
const int loga=6;
#else
const int MAXN=1e6;
const int loga=20;
#endif


int main(){  
	FIN;
	vector<int> sumas(MAXN+10,0);

	int q=0;
	forn(i,MAXN/10+1){
		forn(j,10){
			sumas[10*i+j]=sumas[q]+j;
		}
		q++;
	}
	int jmp[MAXN+5][loga];
	forn(i,MAXN+5){
		jmp[i][0]=i-sumas[i];
	}
	forr(j,1,loga){
		forn(i,MAXN+5){
			jmp[i][j]=jmp[jmp[i][j-1]][j-1];
		}
	}

	int n,k; cin>>n>>k;
	vector<int> pollen(n);
	forn(i,n) cin>>pollen[i];

	int l=-1,r=MAXN+1;
	int moves;
	int med;

	while(1<r-l){
		med=(l+r)/2;
		moves=0;
		forn(i,n){
			int m2=0;
			int u=pollen[i];
			if(u>med){m2++;}
			forn(j,loga){
				if(jmp[u][loga-1-j]>med){
					m2+=1<<(loga-1-j);
					u=jmp[u][loga-1-j];
				}
			}
			moves+=m2;
		}
		if(moves>=k) l=med;
		else r=med;
	}
	cout<<sumas[r]<<"\n";

	return 0;
}
