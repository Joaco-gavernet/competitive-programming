#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i< (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())

const int MAXN = -1;
const int INF = -1;
const int MOD = -1;

int main() {
  FIN;
  
  int c, d; cin >> c >> d;
  vi am, bm; 
  
  forn(i, d-c+1) {
    string s; cin >> s;
    
    if (s == "FizzBuzz") am.pb(c +i), bm.pb(c +i);
    else if (s == "Fizz") am.pb(c +i);
    else if (s == "Buzz") bm.pb(c +i);
  }
  
  ll a, b;
  if (SZ(am) == 1) a = am[0];
  else if (SZ(am) > 1) a = am[1] -am[0];
  else a = d+1;
  
  if (SZ(bm) == 1) b = bm[0];
  else if (SZ(bm) > 1) b = bm[1] -bm[0];
  else b = d+2;
  
  cout << a << " " << b << endl;
  
  return 0;
}
