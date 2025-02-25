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

int lis(vector<int> &a, int strict = 0){
  vi temp; temp.pb(a[0]);
  forr(i,1,SZ(a)){
    ll x=a[i];
    if(x>= temp.back()+strict) temp.pb(x);
    else{
      auto it = upper_bound(all(temp),x-strict);
      *it=x;
    }
  }
  return SZ(temp);
}

vector<int> val={0,1,2,3};

bool amenb(pair<int,int> a, pair<int,int> b){
  if(a.first == b.first){
    return a.second<b.second;
  }else{
    return val[a.first]<val[b.first];
  }
}


int main(){  
  FIN;
  int n; cin>>n; int x=0;
  vector<pair<int,int>> v(n);
  vector<int> a(n,0);
  forn(i,n){
    char aux; cin>>aux;
    if(aux=='C'){v[i].first=4;}
    else if(aux=='R'){v[i].first=3;}
    else if(aux=='E'){v[i].first=2;}
    else if(aux=='W'){v[i].first=1;}
    else{v[i].first=0;}
    cin>>v[i].second;
  }
  forn(i,n){
    if(v[i].first == 4){a[i]=4*n+v[i].second;}
    else{
      a[i]=val[v[i].first]*n+v[i].second;
    }
  }
  int ans=n-lis(a,x);
  //for(auto u:val){cout<<u<<" ";} cout<<endl;
  while (next_permutation(all(val))) {
    //for(auto u:val){cout<<u<<" ";} cout<<endl;
    forn(i,n){
      if(v[i].first == 4){a[i]=4*n+v[i].second;}
      else{
	a[i]=val[v[i].first]*n+v[i].second;
      }
    }
    ans=min(ans,n-lis(a,x));
  }
  cout<<ans<<"\n";
  return 0;
}
