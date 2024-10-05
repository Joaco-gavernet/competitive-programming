#include <bits/stdc++.h>
using namespace std;

#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define SZ(x) int((x).size())

//~ const ll MAXN = -1;
//~ const ll MOD = -1;
//~ const ll INF = -1;


int main() {
  FIN;
  int n,k,d,s; cin>>n>>k>>d>>s;
  double ans;
  int sumtot=d*n,sumact=s*k;
  ans=((double)sumtot-sumact)/(n-k);
  cout<<fixed<<setprecision(7);
  if(ans>100 or ans<0) cout<<"impossible\n";
  else cout<<ans<<"\n";
  return 0;
}
