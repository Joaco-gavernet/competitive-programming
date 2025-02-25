#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(int i = (ll)a; i <(ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define pb push_back


const int MAXN = 1000;

int main() {
  FIN;

  int s; cin >> s; 
  forr(i,0,MAXN) {
    forr(j,0,MAXN) {
      if (i*i + j*j == s) {
        cout << "0 0\n"; 
        cout << i << ' ' << j << '\n'; 
        cout << i -j << ' ' << i +j << '\n'; 
        cout << -j << ' ' << i << '\n'; 
        return 0; 
      }
    }
  }
  cout << "Impossible\n"; 


  return 0; 
}
