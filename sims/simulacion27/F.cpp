#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = a; i < b; i++) 
#define DBG(x) cerr << #x << " = " << x << endl
#define esta(x,v) (v).find(x) != (v).end()
#define SZ(x) int((x).size())
#define pb push_back

bool possible(string &a, string &b, int c) {
  forr(i,0,c) 
    if (a[i] != b[i] and a[i] != '*' and b[i] != '*') 
      return false; 
  return true; 
}

const int MAXN = 10;

int main() {
  FIN; 

  int n, c; cin >> n >> c; 
  vector<string> v(n); forr(i,0,n) cin >> v[i]; 
  vector<bitset<MAXN>> reach(n); 
  vector<vi> g(n); 

  forr(i,0,n) {
    reach[i][i] = 1; 
    forr(j,i+1,n) {
      if (possible(v[i], v[j], c)) {
        cerr << i << ' ' << j << endl; 
        reach[i][j] = reach[j][i] = 1;
        g[i].pb(j); 
        g[j].pb(i); 
      }
    }
  }

  forr(i,0,n) {
    forr(j,0,MAXN) cerr << reach[i][j]; 
    cerr << endl; 
  }

  forr(i,0,n) {
    reach[i][i] = 1; 
    forr(j,i+1,n) {
      if (possible(v[i], v[j], c)) {
        cerr << i << ' ' << j << endl; 
        reach[i][j] = reach[j][i] = 1;
      }
    }
  }

  forr(i,0,n) {
    bitset<MAXN> best = reach[i];  
    forr(j,i+1,n) {
      cerr << i << ' ' << j << endl; 
    }
  }


  return 0; 
}
