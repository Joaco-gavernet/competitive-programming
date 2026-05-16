#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cout << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"

bool check(int x, int y, int n){
  if(x<0 or y<0 or x>=n or y>=n) return false;
  return true;
}

int main() {
  FIN;
  int n; cin >> n;
  n=1<<n;
  vector <vi> v(n,vi(n));
  vi dx={0,1,0,-1}, dy={1,0,-1,0};
  vi c((n*n-1)/3+1);
  forn(i,n) forn(j,n) {cin >> v[i][j]; c[v[i][j]]++;}
  forr(i,1,(n*n-1)/3+1) if(c[i]!=3){cout << "0\n";  return 0;}
  bool found=false;
  vector <vb> visto(n,vb(n,false));
  forn(i,n) forn(j,n){
    if(v[i][j]==0){
      visto[i][j]=true;
      if(!found) found=true;
      else {cout << "0\n";  return 0;}
    }
    else{
      forn(t,4) forn(k,4) if(!visto[i][j] and t%2!=k%2 and check(i+dx[t],j+dy[t],n) and check(i+dx[k],j+dy[k],n) and v[i+dx[t]][j+dy[t]]==v[i][j] and v[i+dx[k]][j+dy[k]]==v[i][j] and !visto[i+dx[t]][j+dy[t]] and !visto[i+dx[k]][j+dy[k]]){
        visto[i][j]=true;
        visto[i+dx[t]][j+dy[t]]=true;
        visto[i+dx[k]][j+dy[k]]=true;
      }
    }
  }
  forn(i,n) forn(j,n) if(!visto[i][j]) {cout << "0\n"; return 0;}
  cout << "1\n";
  return 0; 
}