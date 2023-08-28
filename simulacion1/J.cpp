/*   AUTHOR: Estufa en Piloto   */
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
const int MAXN  = 2e5+5;

int main(){  
    FIN;
    int n, k;
    cin >> n >> k;
    k--;
    vector<vector<int>> v(n, vector<int>(13,0));
    forn(i,n){
      forn(j,4){
	char s;
	cin >> s;
	int t=s-'2';
	if(s=='A') v[i][0]++;
	else if(s=='D') v[i][9]++;
	else if(s=='J') v[i][10]++;
	else if(s=='Q') v[i][11]++;
	else if(s=='K') v[i][12]++;
	else v[i][t]++;
      }
    }
    bool fin=false;
    int wild=k;
    bool wildb=false;
    int ans;
    while(!fin){
      if(wild==k and wildb==true){
	wild=(k+1)%n;
	wildb=false;
      }
      else{
	wildb=true;
	ll pase=-1;
	int cant=5;
	forn(i,13){
	  if(v[k][i]!=0 and v[k][i]<cant){
	    pase=i;
	    cant=v[k][i];
	  }
	  if(v[k][i]==4){
	    fin=true;
	    ans=k+1;
	  }
	}
	v[k][pase]--;
	v[(k+1)%n][pase]++;
      }
      k=(k+1)%n;
    }
    cout << ans << "\n";
    return 0;
}
