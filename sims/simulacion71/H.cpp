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

int cont=0, n;

vector <vi> v(2000,vi(2000));

void f24(int x, int y){
  cont++;
  v[x][y]=cont; v[x][y+1]=cont; v[x][y+2]=cont+1; v[x][y+3]=cont+1;
  v[x+1][y]=cont; v[x+1][y+1]=cont+1; v[x+1][y+2]=cont; v[x+1][y+3]=cont+1;
  cont++;
}

void f42(int x, int y){
  cont++;
  v[x][y]=cont; v[x][y+1]=cont;
  v[x+1][y]=cont; v[x+1][y+1]=cont+1;
  v[x+2][y]=cont+1; v[x+2][y+1]=cont;
  v[x+3][y]=cont+1; v[x+3][y+1]=cont+1;
  cont++;
}

void out(){
  cout << cont << "\n";
  forn(i,n){
    forn(j,n){
      cout << v[i][j];
      if(j<n-1) cout << " ";
    }
    cout << "\n";
  }
}

void s0(){
  for(int i=0; i<n; i+=2) for(int j=0; j<n; j+=4) f24(i,j);
  out();
}

void s2(){
  forn(i,2) forn(j,2) v[i][j]=0;
  for(int j=2; j<n; j+=4) f24(0,j);
  for(int i=2; i<n; i+=4) f42(i,0);
  for(int i=2; i<n; i+=2) for(int j=2; j<n; j+=4) f24(i,j);
  out();
}

int main() {
  NaN;
  int t; cin >> t;
  while(t--){
    cont=0;
    cin >> n;
    if(n%4==0) s0();
    //if(n%4==1) s1();
    if(n%4==2) s2();
    //if(n%4==3) s3();
  }
  return 0;
}