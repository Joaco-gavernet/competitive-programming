#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(c) (c).begin(),(c).end()

const int INF = -1;

typedef long long tipo;

struct punto {
  tipo x,y; 
  tipo operator ^ (const punto &p) const {
    return x*p.y - y*p.x; 
  }
};

tipo area(vector<punto> &v) {
  tipo ans = 0; int n = v.size();
  forn(i,n) ans += v[i] ^ v[(i+1) %n];
  return abs(ans);
}

int main() {
  FIN;
  
  int n; cin >> n;
  tipo tot = 0.0;
  
  forn(_,n) {
    int p; cin >> p;
    vector<punto> poli(p);
    forn(i,p) cin >> poli[i].x >> poli[i].y;
    
    tot += area(poli);
  }
  cout << tot/2 << endl;
  
  return 0;
}





