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
  ll l,r; l=0; r=1e12+1;

  ll z=1e12/2;
  ll inp;
  ll ans=31415;
  int cont =1;
  while((r-l)>1) {
    // tomo decision
    // envio decision
    cont++;
    cout << "? " << z << endl; 
    // recibo respuesta
    //fflush(stdout);
    //cin >> inp;
    inp=z%ans;
    cout<< "AA " << l << " " << r << " " << inp<<"\n";
    if(inp==z%r){
      l=z%r;
      z=z+((r-l)/2);
    }else{
      r=(z-inp)%r;
      z=(z/r+1)*r+((r-l)/2);
    }  
  }

  cout << "! " << r << endl;
  cout << cont << endl;
  
  return 0;
}
