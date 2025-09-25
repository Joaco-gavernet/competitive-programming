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
  int t;
  cin >> t;
  while(t--){
    int n, k;
    cin >> n >> k;
    int pos=0, neg=0;
    vi v;
    forn(i,n){
      int a;
      cin >> a;
      if(a==0) continue;
      v.pb(a);
      if(a<0) neg++;
      else pos++;
    }
    n=SZ(v);
    if(n==0){cout << 0 << "\n"; continue;}
    sort(all(v));
    if(-v[0]>v[n-1]){
      forn(i,n) v[i]*=-1;
      swap(pos,neg);
      reverse(all(v));
    }
    ll ans=v[n-1];
    if(neg>0){
      ans+=-2*v[0];
      int c=k;
      while(c<n and v[c]<0){ans+=-2*v[c]; c+=k;}
    }
    //cout << "HOALA " << pos << " " << neg << " " << ans << endl;
    int c=n-1-k;
    while(c>-1 and v[c]>0){ans+=2*v[c]; c-=k;}
    cout << ans << "\n";
  }
  
  
  
  
  return 0;
}
