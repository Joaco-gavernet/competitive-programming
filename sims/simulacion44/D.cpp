#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 
#define forr(i,a,b) for (int i = a; i < b; i++)  
#define forn(i,n) forr(i,0,n) 
#define all(v) (v).begin(), (v).end() 


int dx[] = {0, 1, 0, -1}; 
int dy[] = {-1, 0, 1, 0}; 
int ddx[] = {1, 1, -1, -1}; 
int ddy[] = {-1, 1, 1, -1}; 

int main() {
  int t; cin >> t; 
  forn(ti,t) {
    ll n, m, d1, d2; 
    cin >> n >> m >> d1 >> d2; 
    vector<string> g(n); 
    forn(i,n) cin >> g[i]; 

    vector<vi> ans(n, vi(m,0)); 
    forn(y,n) forn(x,m) {
      if (g[y][x] == 'V') {
        ans[y][x] = -1; 
        forn(i,4) {
          int yi = y +dy[i], xi = x +dx[i]; 
          if (yi < 0 or yi >= n or xi < 0 or xi >= m) continue; 
          if (ans[yi][xi] == -1) continue; 
          ans[yi][xi] = max(ans[yi][xi], d1); 
        } 
        forn(i,4) {
          int yi = y +ddy[i], xi = x +ddx[i]; 
          if (yi < 0 or yi >= n or xi < 0 or xi >= m) continue; 
          if (ans[yi][xi] == -1) continue; 
          ans[yi][xi] = max(ans[yi][xi], d2); 
        } 
      }
    } 

    cout << "Airplane #" << ti +1 << ": \n"; 
    forn(y,n) {
      forn(x,m) {
        if (ans[y][x] == -1) cout << 'V';
        else cout << ans[y][x]; 
      }
      cout << '\n'; 
    } 
  } 

  return 0; 
} 
