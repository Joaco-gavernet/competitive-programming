#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vi; 
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"
#define DBGV(v,n) cerr << #v << " = "; forn(_,n) cerr << v[_] << ' '

const ld EPS = 1e-14;
const long double INF = 1e7;
const ll IT = 1000;

int main() {
  FIN;
  cout<<fixed<<setprecision(15);
  ll n; ld t; 
  cin >> n >> t;
  vector<ld> d(n), s(n);
  ld mins=-1001;
  forn(i,n){
    int a, b; cin >> a >> b;
    d[i] = a, s[i] = b;
    mins=max(mins,(d[i] /t) -s[i]);
  }
  ld l = mins, r = INF;
  forn(x,IT) {
    ld c=l/2+r/2;
    ld anst=0;
    forn(i,n) anst += d[i]/(c + s[i]);
    if(anst <= t) r=c;
    else l=c;
  }
  cout<<r<<"\n";

  return 0;
}