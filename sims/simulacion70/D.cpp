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
#define RAYA cerr << "======================\n"

int main() {
  FIN;
  ll n; cin>>n;
  queue<ii> cand;
  cand.push({(n+1)/2,0});
  while(SZ(cand)){
    ii el=cand.front(); cand.pop();
    ll x=el.ff; ll sent=el.ss;
    if(__gcd(x,n)==1){
      cout<<x<<"\n";
      return 0;
    }
    if(sent==0){
      cand.push({x-1,-1});
      cand.push({x+1,1});
    }else{
      cand.push({x+sent,sent});
    }
  }
  return 0; 
}