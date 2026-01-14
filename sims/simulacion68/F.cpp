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
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=========================\n"
#define all(v) begin(v),end(v)


int main() {
  FIN;

  int n; cin >> n;
  vi a(n), b(n); 
  forn(i,n) cin >> a[i];
  forn(i,n) cin >> b[i];

  // checks
  int A = 0, B = 0;

  // greedy for first version of the graph
  int i = 0, j = 0;
  while (i < n and j < n) {

  }


  return 0;
}