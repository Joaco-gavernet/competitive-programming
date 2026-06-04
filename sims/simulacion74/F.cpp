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
#define RAYA cerr << "================================\n"
#define ff first
#define ss second 

void solve(){
  ll n,m,u,r,d,l;
  cin >> n >> m >> u >> r >> d >> l;\
  if(r<m-1 or u<n-1){cout << "impossible\n"; return;}
  vector <vector<char>> v(n,vector <char>(m,'a'));
  v[0][m-1]='*';
  r-=m-1; u-=n-1;
  int x=0, y=0;
  while(d>0){
    v[x][y]='D';
    y++;
    if(y==m-1){x++; y=0;}
    d--;
  }
  while(r>0){
    v[x][y]='R';
    y++;
    if(y==m-1){x++; y=0;}
    r--;
  }
  ll xx=n-1, yy=0;
  while(xx>x+1){
    v[xx][yy]='U';
    xx--;
  }
  while(yy<y){
    v[xx][yy]='R';
    yy++;
  }
  if(xx>x){
    v[xx][yy]='U';
    xx--;
  }
  while(yy<m-1){
    v[xx][yy]='R';
    yy++;
  }
  while(xx>0){
    v[xx][yy]='U';
    xx--;
  }
  forn(i,n) forn(j,m) if(v[i][j]=='a'){
    if(u>0){
      v[i][j]='U';
      u--;
    }
    else{
      v[i][j]='L';
      l--;
    }
  }
  forn(i,n){
    forn(j,m) cout << v[i][j];
    cout << "\n";
  }
}

int main() {
  FIN;
  ll t; cin >> t;
  while(t--){
    solve();
    cout << "\n";
  }
  return 0; 
} 
