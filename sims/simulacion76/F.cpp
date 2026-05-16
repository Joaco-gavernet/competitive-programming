#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cout << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"


vi d1;
void manacher(vi &s) {
  ll l = 0, r = -1, n = SZ(s); 
  d1.resize(n); 
  forn(i,n) {
    ll k = (i > r ? 1 : min(d1[l+r-i], r-i));
    while (i + k < n and i - k >= 0 and s[i+k] == s[i-k]) k++; 
    d1[i] = k--; 
    if (i + k > r) l = i - k, r = i + k;
  }
}

int main() {
  FIN;
  int n; cin >> n;
  vi v(n), l(n);
  forn(i,n) {
    cin >> v[i];
    if(i>0 and v[i-1]<v[i]) l[i]=l[i-1]+1;
  }
  manacher(v);
  ll ans=0;
  forn(i,n){
    ans=max(ans,min(2*l[i]+1,2*d1[i]-1));
  }
  if(ans>=3) cout << ans << "\n";
  else cout << "-1\n";
  return 0; 
}