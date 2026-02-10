#include <bits/stdc++.h> 
using namespace std;

typedef long long ll; 
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==================================\n"


int main() {
  FIN;
  ll n,a,b; cin>>n>>a>>b;
  if((a+b > n+1) or (a+b==2)){cout<<"no\n"; return 0;}
  bool inv=false;
  if(a>b){swap(a,b); inv=true;}
  vi ans(n);
  ll pans=0;
  forn(i,a-1){
    ans[pans++]=i+1;
  }
  ans[pans++]=n;
  ll rem=b-1;
  forn(x,n-a-rem) ans[pans++]=a+x;
  forn(x,rem) ans[pans++]=n-1-x;
  cout<<"yes\n";
  if(inv) reverse(all(ans));
  forn(i,n) cout<<ans[i]<<" ";
  cout<<"\n";
  return 0; 
}
