#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vi; 
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v), end(v)
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=================================\n"



int main() {
  FIN;
  int n; cin >> n;
  vector <ld> a(n);
  ld r=0;
  forn(i,n){
    int k; cin >> k;
    a[i]=k;
  }
  cin >> r;
  r/=n;
  vector <ld> ans(n,r);
  forn(i,n-1){
    ans[i]=r;
    if(a[i]/2<r){
        r+=(r-a[i]/2)/(n-i-1);
        ans[i]=a[i]/2;
    }
  }
  ans[n-1]=r;
  for(int i=n-1; i>0; i--) if(ans[i-1]+ans[i]>a[i]){
    ld b=ans[i-1]+ans[i];
    ans[i-1]=a[i-1]/2+(b-a[i])/2;
    ans[i-1]=a[i]/2+(b-a[i-1])/2;
  }
  cout << setprecision(10) << fixed;
  forn(i,n) cout << ans[i] << "\n";
  return 0; 
}
