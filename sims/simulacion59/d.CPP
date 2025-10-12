#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii;
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
  string s; cin>>s;
  ll n=SZ(s);
  vi histo(26);
  forn(i,n) histo[s[i]-'a']++;
  ll cont=0;
  forn(i,26) if(histo[i]%2) cont++;
  if(cont>1) cout<<"no\n";
  else cout<<"yes\n";

  return 0; 
}