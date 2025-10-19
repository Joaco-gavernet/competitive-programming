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
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl 
#define RAYA cerr << "=======================" << endl 
#define ff first
#define ss second

struct tup {
  ll lef = 0, rig = 0, any = 0;
};

int main() {
  FIN;

  int n; cin >> n; 
  map<string, tup> cont;
  forn(i,n) {
    string name, typ; 
    ll x; 
    cin >> name >> typ >> x;
    if (typ == "left") cont[name].lef = x;
    if (typ == "right") cont[name].rig = x;
    if (typ == "any") cont[name].any = x;
  }

  bool possible = false; 
  ll worst = 0; 
  for (auto [k, tup]: cont) {
    worst += max(tup.lef, tup.rig); 
    if (tup.lef == 0 and tup.rig == 0) worst += (tup.any != 0); 
    int sum = tup.lef + tup.rig + tup.any; 
    bool dist = false; 
    if (tup.lef > 0 and tup.rig > 0) dist = true;
    if (tup.lef > 0 and tup.any > 0) dist = true;
    if (tup.rig > 0 and tup.any > 0) dist = true;
    if (tup.any > 1) dist = true;
    if (sum >= 2 and dist) possible = true;
  }

  if (possible) cout << worst +1 << endl;
  else cout << "impossible" << endl; 

  return 0; 
}