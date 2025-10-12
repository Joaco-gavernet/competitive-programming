#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii;
typedef long double ld;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define DBG(x) cerr << #x << " = " << x << endl 
#define RAYA cerr << "=============================\n"



int main() {
  FIN;
  cout<<fixed<<setprecision(10);
  ll d,a,o,ca,co; cin>>d>>a>>o>>ca>>co;
  ll difa=d*ca;
  ll difo=d*co;
  a=max((ll)0,a-difa);
  o=max((ll)0,o-difo);
  ll denom=a+o;
  ld coc=a;
  coc/=denom;
  coc*=100;
  cout<<coc<<"\n";
  return 0; 
}