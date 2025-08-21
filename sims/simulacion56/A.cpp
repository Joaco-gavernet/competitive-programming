#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vi; 
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v), end(v)
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=================================\n"



int main() {
  FIN;
  cout<<fixed<<setprecision(7);
  ll t,p; cin>>t>>p;
  long double v;
  long double ans=0;
  if(p>=20){
    v=(ld)(100-p)/t;
    ans+=(p-20)/v;
    ans+=40/v;
  }
  else{
    v=(ld)(80+2*(20-p))/t;
    ans+=p/((ld)v/2);
  }
  cout<<ans<<"\n";
  return 0; 
}
