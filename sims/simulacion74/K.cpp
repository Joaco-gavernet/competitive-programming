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


int main() {
  FIN;

  int n; cin >> n; 
  vi w(n); forn(i,n) cin >> w[i]; 
  
  reverse(all(w));
  while (SZ(w) and w.back() == 0) w.pop_back(); 

  ll tot = 1, x = 0; 
  while (SZ(w)) {
    if (w.back() > x) tot += w.back() - x + 1;
    x = w.back();
    w.pop_back();
  }
  cout << tot << '\n'; 

  return 0; 
} 
