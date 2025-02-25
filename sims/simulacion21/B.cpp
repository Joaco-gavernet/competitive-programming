#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << " ======================= \n"

const int MAXN = -1;
const int MOD = -1;
const int INF = -1;


int main() {
  FIN;
  int n; cin>>n;
  vector<int> s(n),e(n);
  forn(i,n){cin>>s[i]>>e[i];}
  int l=-1,r=n,med;
  med=(l+r)/2;
  while(r>l+1){
    int m=0,pl,pr;
    forn(i,n-med){
      pl=max(s[i],s[i+med]); 
      pr=min(e[i],e[i+med]);
      m=max(m,pr-pl);
    }
    //cout<<med<<" "<<m<<endl;
    if(m>=med){l=med;}else{r=med;}
    med=(l+r)/2;
  }
  cout<<r<<"\n";
  return 0;
}
