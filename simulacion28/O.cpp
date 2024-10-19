#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==============================\n"
#define pb push_back
#define SZ(x) int((x).size())
#define all(c) (c).begin(),(c).end()

int main() {
  FIN; 
  int n; cin>>n;
  ll m=1<<30; m--;
  ll sum=0;
  vi lis(n); forn(i,n){cin>>lis[i];}
  forn(i,n-1) sum+=(lis[i]^lis[i+1]);
  ll ans=sum;
  if(n==2) cout<<m<<"\n";
  else{
    vi xo,xoc(n-2,0);
    ll mejor=0;
    xo.pb((m)-(lis[0]^lis[1]));
    forr(i,1,n-1){
      xo.pb(2*(m)-(lis[i-1]^lis[i+1])-(lis[i-1]^lis[i])-(lis[i]^lis[i+1]));
      ans=max(ans,sum+mejor+xo[i]);
      mejor=max(mejor,xo[i-1]);
    }
    xo.pb((m)-(lis[n-1]^lis[n-2]));
    ans=max(ans,sum+mejor+xo[n-1]);
    //ahora caso consecutivo
    ans=max(ans,sum+2*(m)-(lis[1]^lis[2])-(lis[1]^lis[0]));
    ans=max(ans,sum+2*(m)-(lis[n-1]^lis[n-2])-(lis[n-2]^lis[n-3]));
    forr(i,1,n-2){
      ans=max(ans,sum+2*(m)+(lis[i-1]^lis[i+2])-(lis[i]^lis[i+1])-(lis[i]^lis[i-1])-(lis[i+1]^lis[i+2]));
    }
    cout<<ans<<"\n";
  }
  return 0; 
}
