#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << '\n'
#define RAYA cerr << "===========================\n"

int main() {
  FIN;
  string s; string c; cin >> s >> c;
  int n=SZ(s);
  ld lc=log10(c[0]-'0')+SZ(c)-1, la=log10(s[0]-'0');
  ld best=1e6;
  int ans=-1;
  forn(i,n-1){
    ld lb=log10(s[i+1]-'0')+n-1-i-1;
    if(fabs(lc+lb-la-i)<best){
      ans=i;
      best=fabs(lc+lb-la-i);
    }
  }
  forn(i,ans+1) cout << s[i];
  cout << " ";
  forr(i,ans+1,n) cout << s[i];
  cout << "\n";
  return 0;
}