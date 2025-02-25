#include <bits/stdc++.h>
using namespace std; 


typedef long long ll; 
typedef vector<ll> vi;
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define esta(v,x) (v).find(x) != (v).end()
#define pb push_back
#define SZ(x) int((x).size)
#define all(v) (v).begin(), (v).end() 
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=============================\n"
#define DBGV(v,n) forn(_,n) cerr << v[_] << ' '


int main() {
  FIN;
  ll n, k; cin >> n >> k;
  vector <long double> p(n);
  forn(i,n) {cin >> p[i]; p[i]/=100;}
  cout << setprecision(10) << fixed;
  if(n==1) {cout << "100\n"; return 0;}
  long double _n=n, _k=k;
  if(k==1) {
    long double ans=1/_n; ans*=100;
    cout << ans << "\n"; return 0;
  }
  vector <long double> c(n-k+1);
  c[0]=_k*(_k-1)/_n/(_n-1);
  forn(j,n-k) {c[j+1]=c[j]*(n-j-k); c[j+1]/=n-j-2;}
  forn(i,n-k+1){
    assert(0 <= c[i]);
    assert(c[i] <= 1);
  }
  //cout << endl;
  forn(i,n){
    long double acum=p[i], ans=0;
    forn(j,n-k+1){
      int r=(n+i-j-1)%n;
      ans+=acum*c[j];
      acum+=p[r];
    }
    assert(0 <= ans);
    assert(ans <= 1); 
    cout << ans*100 << " ";
  }
  cout << "\n";
  return 0;
} 
