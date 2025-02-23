#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 
typedef pair<ll,ll> ii; 
#define forr(i,a,b) for (int i = a; i < b; i++)  
#define forn(i,n) forr(i,0,n) 
#define all(v) (v).begin(), (v).end() 
#define pb push_back 
#define SZ(x) int((x).size()) 
#define DBG(x) cerr << #x << " = " << x << endl 
#define RAYA cerr << "=================================\n" 
#define DBGV(v) cerr << #v << " = "; forn(_,SZ(v)) cerr << v[_].first << ' ' << v[_].second << '\n'

struct tup {
  int d, s, id; 
  bool operator < (tup b) {
    if (d *b.s == b.d *s) return id < b.id;
    else return d *b.s < b.d *s;
  }
}; 

int main() {
  int t; cin >> t; 
  while (t--) {
    int n; cin >> n; 
    vector<tup> v(n); 
    forn(i,n) cin >> v[i].d >> v[i].s, v[i].id = i+1; 
    sort(all(v));
    forn(i,n) cout << v[i].id << ' '; 
    cout << '\n';
  } 

  return 0; 
} 
