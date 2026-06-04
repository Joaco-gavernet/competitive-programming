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
#define RAYA cerr << "================================\n"
#define ff first
#define ss second 

const long double EPS = 1e-9; 

void solve() {
  ll r, w, h; cin >> r >> w >> h; 

  auto f = [&](ll c) -> ll {
    ll p = (4 * r * r - c * c * w * w) / (h * h); 
    ll aa = 0, bb = 1e9+5; 
    while (aa + 1 < bb) {
      ll mi = (aa + bb) / 2;
      if (mi * mi <= p) aa = mi;
      else bb = mi; 
    }
    return aa * c; 
  }; 

  if (2 * r <= w or 2 * r <= h) {
    cout << "0\n";
    return; 
  }

  ll a = 0, b = 2 * r / w; 
  while (a + 1 < b) {
    ll mid = (a + b) / 2;
    if (f(mid) < f(mid + 1)) a = mid;
    else b = mid; 
  }

  cout << max(f(a), f(b)) << '\n'; 
}

int main() {
  FIN;
  int t; cin >> t;
  while (t--) solve(); 
  return 0; 
} 
