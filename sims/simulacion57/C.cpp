#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define all(v) begin(v), end(v)
#define SZ(x) int((x).size())
#define pb push_back
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "============================\n"



int main() {
  FIN;
  ll c; cin>>c;
  ll sum=0;
  vi cols(c);
  forn(i,c){
    cin>>cols[i];
    sum+=cols[i];
  }
  sum/=3;
  bool ans=true;
  forn(i,c) if(cols[i]>sum) ans=false;
  if(ans) cout<<"YES\n";
  else cout<<"NO\n";

  return 0;
}