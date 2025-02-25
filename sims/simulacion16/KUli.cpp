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
  int n; cin>>n;
  vector<int> p1(n),p2(n),ans1(n),ans2(n);
  forn(i,n){cin>>p1[i];}
  forn(i,n){cin>>p2[i];}
  set<pair<int,int>,greater<pair<int,int>>> len;
  len.insert({0,1});
  forn(i,n){
    
  }
  
  
  forn(i,n){
    cout<<ans1[i]<<" ";
  }cout<<"\n";
  forn(i,n){
    cout<<ans1[i]<<" ";
  }cout<<"\n";
  return 0;
}
