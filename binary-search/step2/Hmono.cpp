#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define forr(i,a,b) for(int i=(int)a; i<(int)b; i++)
#define forn(i,n) forr(i,0,n)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "============================" << endl
 
int main() {
  
  string pal; cin >> pal;
  ll b, s, c; cin >> b >> s >> c;
  ll pb, ps, pc; cin >> pb >> ps >> pc;
  ll money; cin >> money;

  vector <ll> cont(3,0);
  for(char u : pal) {
    if(u == 'B') cont[0]++;
    if(u == 'S') cont[1]++;
    if(u == 'C') cont[2]++;
  }
  
  ll x = 0, y = (ll)(1e13);
  while(y-x > 1) {
    ll med = (x+y)/2;
    ll cost = 0;
    cost += max(0LL,cont[0]*med - b) * pb;
    cost += max(0LL,cont[1]*med - s) * ps;
    cost += max(0LL,cont[2]*med - c) * pc;
    if(cost <= money) x = med;
    else y = med;
  }
  cout << x << "\n";
  return 0;
}
