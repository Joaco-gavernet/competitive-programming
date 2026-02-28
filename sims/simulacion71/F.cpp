#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define NaN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define pb push_back
#define all(v) begin(v),end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "============================\n"

void solve(){
  int n, m; cin >> m >> n;
  vector <vi> v(m);
  vi p(m), l(n,-1);
  forn(i,m){
    cin >> p[i] ;
    forn(_,p[i]){
      int x; cin >> x;
      x--;
      l[x]=i;
      v[i].pb(x);
    }
  }
  int a=0;
  vi last(n,-1);
  forn(i,p[0]) last[v[0][i]]=0;
  forr(i,1,m){
    bool anda=true;
    forn(j,p[i]){
      if(last[v[i][j]]==i-1 and l[v[i][j]]==i) anda=false;
      last[v[i][j]]=i;
    }
    if(anda){a=i; break;}
  }
  if(a==0) {cout << "No\n"; return;}
  cout << "Yes\n";
  forn(i,a-1) cout << i+1 << " ";
  cout << a+1 << " " << a;
  if(a!=m-1) cout << " ";
  forr(i,a+1,m){
    cout << i+1;
    if(i<m-1) cout << " ";
  }
  cout << "\n";
}

int main() {
  NaN;
  int t; cin >> t;
  while(t--) solve();
  return 0;
}