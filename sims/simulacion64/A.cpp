#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i <(ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << '\n'
#define RAYA cerr << "============================\n"
#define ff first
#define ss second


int main() {
  FIN;
  ll n,m; cin>>n>>m;
  vi in(n),out(m);
  forn(i,n) cin>>in[i]; 
  forn(i,m) cin>>out[i];
  map<ll,ll> match;
  forn(i,n) forn(j,m) if(in[i]<=out[j]) match[out[j]-in[i]]++;
  ll maxi=0,nmax=0;
  for(auto u:match){
    if(u.ss > maxi){
      maxi=u.ss;
      nmax=u.ff;
    }
  }
  cout<<nmax<<"\n";

  return 0; 
}