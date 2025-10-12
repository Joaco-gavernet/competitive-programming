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

  string a,b,c; cin >> a >> b >> c;
  reverse(all(a));
  reverse(all(b));
  reverse(all(c));

  string ans = ""; 
  while (SZ(a) or SZ(b) or SZ(c)) {
    if (SZ(a) and SZ(b) and a.back() == b.back()) ans += a.back(), a.pop_back(), b.pop_back();
    else if (SZ(a) and SZ(c) and a.back() == c.back()) ans += a.back(), a.pop_back(), c.pop_back(); 
    else if (SZ(b) and SZ(c) and b.back() == c.back()) ans += b.back(), b.pop_back(), c.pop_back(); 
  }
  cout << ans << '\n'; 

  return 0; 
}