#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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


int main() {
  FIN;
  int m, n; cin >> m >> n;
  vector <vb> g(26, vb(26,false));
  forn(i,m){
    char a, b;
    cin >> a >> b;
    g[a-'a'][b-'a']=true;
  }
  forn(i,26) g[i][i]=true;
  forn(k,26) forn(i,26) forn(j,26) if(g[i][j]) forn(q,26) if(g[j][q]) g[i][q]=true;
  forn(i,n){
    string a, b;
    cin >> a >> b;
    if(SZ(a)!=SZ(b)) {cout << "no\n"; continue;}
    bool anda=true;
    forn(j,SZ(a)) anda&=g[a[j]-'a'][b[j]-'a'];
    if(anda) cout << "yes\n";
    else cout << "no\n";
  } 
  return 0;
}