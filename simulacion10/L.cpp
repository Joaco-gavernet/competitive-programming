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

ll gcd(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1; y =0;
    return a;
  }

  ll x1, y1;
  ll d = gcd(b, a%b, x1, y1);
  x = y1;
  y = x1 - y1*(a/b);
  return d;
}


int main(){  
  FIN;
    int t,w,n; cin>>t>>w>>n;
    char res[100][100];
    if((t*w)%n){
      cout<<"impossible"<<"\n";
      return 0;
    }
    //DBG(n);
    int a,b,ta,tb;
    a=gcd(w,n);
    b=n/a;
    ta=w/a; tb=t/b;
    char letra='A';
    forn(i,a){
      forn(j,b){
	forr(k,ta*(i),ta*(i+1)){
	  forr(l,tb*j,tb*(j+1)){
	    res[l][k]=letra;
	  }
	}
	letra++;
      }
    }
    //DBG(a);
    forn(i,t){
      forn(j,w){
	cout<<res[i][j];
      }
      cout<<"\n";
    }
  return 0;
}
