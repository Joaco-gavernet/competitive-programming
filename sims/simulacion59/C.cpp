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
#define DBG(x) cerr << #x << " = " << x << endl 
#define RAYA cerr << "=============================\n"

ll d[2][8]={{1,1,-1,-1,2,2,-2,-2},{2,-2,2,-2,1,-1,1,-1}};

int main() {
  FIN;
  int n, m; cin >> n >> m;
  vector <vb> anda(n,vb(n,false));
  vb fila(n,false), col(n,false), d1(2*n,false), d2(2*n,false);
  forn(i,m){
    char c; cin >> c;
    int x, y; cin >> x >> y;
    x--; y--;
    anda[x][y]=true; 
    if(c=='R' or c=='Q') fila[x]=true, col[y]=true;
    if(c=='N') forn(j,8) if(d[0][j]+x<n and 0<=d[0][j]+x and 0<=d[1][j]+y and d[1][j]+y<n) anda[x+d[0][j]][y+d[1][j]]=true;
    if(c=='Q') d1[x+y]=true, d2[x-y+n]=true;
  }
  ll ans=0;
  forn(i,n) forn(j,n){
    anda[i][j]=anda[i][j] or fila[i] or col[j] or d1[i+j] or d2[i-j+n];
    if(anda[i][j]) ans++;
  }
  cout << ans << "\n";
  return 0; 
}