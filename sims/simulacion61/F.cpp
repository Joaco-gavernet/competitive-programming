#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==============================" << endl
#define ff first
#define ss second

const ll INF = 1LL<<60; 

int main() {
  FIN;
  
  int n; cin >> n;
  vi a(n); forn(i,n) cin >> a[i]; 

  vi pref(n+1); 
  forn(i,n) pref[i+1]=(pref[i]+a[i])%10;
  vi last(10,-1);
  ll pos=n-1;
  vi ans(n);
  forn(i,n){
    last[pref[pos+1]]=pos;
    ll rest=pref[pos];
    if(last[rest]==-1) ans[pos]=-1;
    else ans[pos]=(last[rest]-pos)+1;
    pos--;
  }

  for (auto x: ans) cout << x << " "; 
  cout << endl; 

  return 0;
}