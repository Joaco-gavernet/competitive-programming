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

  int X, Y, N, D; cin >> X >> Y >> N >> D; 
  forn(i,N) {
    int xs, xe; cin >> xs >> xe; 
    int ys, ye; cin >> ys >> ye; 
  }

  // preprocess for each coord (x, y) the biggest ornament possible to place starting there
  // TO-DO: fix how to choose when several possible areas for a starting coord???

  forn(i,D) {
    int Xi, Yi; cin >> Xi >> Yi; 
  }

  return 0; 
}