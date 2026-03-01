#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define NaN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "/////////////////////////////\n"


int main() {
  NaN;
  ll m, n, p; cin >> m >> n >> p;
  if(p<n or p==m) {cout << "0/1\n"; return 0;}
  if(n==0){
    if(p==0) {cout << "1/1\n"; return 0;}
    else {cout << "0/1\n"; return 0;}
  }
  vector <vi> c(m+1,vi(m+1,1));
  forr(x,2,m+1) forr(y,1,x) c[x][y]=c[x-1][y]+c[x-1][y-1];
  ll den=p*c[m][p], num=2*n;
  ll k=0;
  forn(i,n){
    if(m-2*(i+1)<p-1) break;
    k+=(1-2*(i%2))*c[m-2*(i+1)][p-1]*c[n-1][i];
  }
  num*=k;
  cout << num/__gcd(num,den) << "/" << den/__gcd(num,den) << "\n";
  return 0; 
}