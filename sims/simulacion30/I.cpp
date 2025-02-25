#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi;
typedef pair<ll,ll> ii; 
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define all(c) (c).begin(),(c).end()
#define esta(v,x) (v).find(x) != (v).end()
#define pb push_back
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=================================\n"


int main() {
  FIN; 
  int n;
  cin >> n;
  vi x(n), y(n), h(n);
  forn(i,n) cin >> x[i] >> y[i] >> h[i];
  ll l=1, r=2*1e8+5;
  forn(i,n) l=max(l,h[i])-1;
  ll ansx, ansy;
  while(r-l>1){
    int med=(r+l)/2;
    vi xa(n), xb(n), ya(n), yb(n);
    forn(i,n){
      xa[i]=x[i]-med+h[i];
      xb[i]=x[i]+med-h[i];
      ya[i]=y[i]-med+h[i];
      yb[i]=y[i]+med-h[i];
    }
    ll minx=xa[0], maxx=xb[0], miny=ya[0], maxy=yb[0];
    forn(i,n){
      minx=max(minx,xa[i]);
      maxx=min(maxx,xb[i]);
      miny=max(miny,ya[i]);
      maxy=min(maxy,yb[i]);
    }
    if(minx>maxx or miny>maxy) l=med;
    else {r=med; ansx=minx; ansy=miny;}
  }
  cout << ansx << " " << ansy << " " << r << "\n";

  return 0; 
}

