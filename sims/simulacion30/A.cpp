#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi;
typedef pair<ll,ll> ii; 
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define all(c) (c).begin(),(c).end()
#define esta(v,x) (v).find(x) != (v).end()
#define pb push_back
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=================================\n"


int main() {
  FIN; 
  ll a,b,n; cin>>a>>b>>n;
  ll dif=b-a;
  ll ans=1;
  //~ if((n-a)%dif) ans++;
  ans=ans+2*((n-b)/dif);
  if((n-b)%dif) ans+=2;
  cout<<ans<<"\n";
  return 0; 
}

