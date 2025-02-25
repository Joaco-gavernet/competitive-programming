#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
typedef vector<ii> vii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i<(ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "============================\n"
#define DBGV(v) cerr << #v << " = "; forn(_,SZ(v)) cerr << v[_] << ' '; cerr << '\n'
#define fs first
#define sd second

int main() {
  FIN; 
  int n; cin >> n;
  vb x(2*n+1,false), y(2*n+1,false);
  vii v(n);
  forn(i,n){
    cin >> v[i].fs >> v[i].sd;
    x[v[i].fs]=true; y[v[i].sd]=true;
  }
  if(n==1) {cout << "NO\n"; return 0;}
  cout << "YES\n";
  forn(i,n) if(!x[2*(i+1)]){
    forn(j,n) cout << i+1 << " " << j+1 << "\n";
    return 0;
  }
  forn(i,n) if(!y[2*(i+1)]){
    forn(j,n) cout << j+1 << " " << i+1 << "\n";
    return 0;
  }
  int k;
  forn(i,n) if(v[i].sd==2) k=v[i].fs;
  k=k/2;
  forr(i,2,n+1) cout << k << " " << i << "\n";
  cout << k%2+1 << " " << 1 << "\n";
  return 0; 
}
