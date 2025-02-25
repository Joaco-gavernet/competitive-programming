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
#define DBGV(v,n) forn(i,n) cerr << v[i] << ' '
#define RAYA cerr << "=================================\n"

ll lis(vector<long double> &a, int strict = 0){
  vector<long double> temp; temp.pb(a[0]);
  forr(i,1,SZ(a)){
    long double x= a[i];
    if(x >= temp.back()+strict) temp.pb(x);
    else{
      auto it=upper_bound(all(temp),x-strict);
      *it = x;
    }
    //~ DBG(i);
    //~ cout<<i<<"\n";
  }
  return SZ(temp);
}

int main() {
  FIN; 

  int n; cin >> n; 

  // solucion 1
  // forn(i,n) cout << 2*355*(i -25000) << '\n'; 

  // solucion 2
  /*
  vector<long double> senos(1e7,0);
  forn(i,1e7) senos[i]=sinl(i);
  forn(i,15) cout<<senos[i]<<"\n";
  cout<<lis(senos)<<"\n";
  */

  // solucion 3
  const long double pi = acos(-1); 
  DBG(pi); 
  for (int i = 0; i < 2*n; i += 2) cout << int(226 *pi * (i -25000)) << '\n'; 


  return 0; 
}

/*
-78539.8
-78533.5
-78527.2
-78521
*/
