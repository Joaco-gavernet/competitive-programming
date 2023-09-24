#include <bits/stdc++.h>
using namespace std;

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,n) for (int i = (a); i < n; i++)
#define forn(i,n) forr(i,0,n)

int main() {
  FIN;
  
  int t; cin >> t;
  int a,b,c;
  
  forn(_,t) {
    cin >> a >> b >> c;
    cout << ceil(float(abs((a-b)))/(2*c)) << "\n";
  }
  
  return 0;
}
