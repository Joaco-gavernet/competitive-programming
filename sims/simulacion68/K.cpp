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
  vi v(n);
  forn(i,n) {
    string s; cin >> s;
    if (SZ(s) == 1) v[i] = -1;
    else v[i] = stoi(s);
  }

  vi ans(n);
  ll mx = 0; 
  forn(i,n) {
    if (v[i] > -1) mx = max(mx, ((v[i] + 10) / 10) * 10); 
    if (v[i] == -1) ans[i] = mx; 
    else ans[i] = v[i];
  }
  for (auto x: ans) cout << x << '\n';

  return 0;
}