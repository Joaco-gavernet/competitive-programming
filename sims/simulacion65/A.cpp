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
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << '\n'
#define RAYA cerr << "==============================\n"

void solve() {
  int n; cin >> n; 
  vi d(n); forn(i,n) cin >> d[i];
  ll s=0, S=0;
  ll x=1000000;
  forn(i,n){
    if(d[i]==0){
      s+=0; S+=x*5-1;
    }
    else{
      s+=x*(10*d[i]-5);
      S+=x*(10*d[i]+5)-1;
    }
  }
  if(S<x*1000 or x*1000<s) {cout << "No\n"; return;}
  cout << "Yes\n";
  forn(i,n){
    ll a, b;
    if(d[i]==0){
      a=0;
      b=x*5-1;
    }
    else{
      a=x*(10*d[i]-5);
      b=x*(10*d[i]+5)-1;
    }
    cout << a+min(b-a,x*1000-s) << " ";
    s+=min(b-a,x*1000-s);
  }
  cout << "\n";
}

int main() {
  FIN;
  int t; cin >> t;
  while (t--) solve();
  return 0;
}