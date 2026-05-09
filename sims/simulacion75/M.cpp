#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "===========================\n"



int main() {
  FIN;

  int n; cin >> n; 

  vector<string> v, u, trans; 
  forn(i,25) {
    char x = 'a' + i; 
    char y = 'a' + i + 1; 
    string s = "";
    s += x; s += x; 
    if (SZ(v) < 25) v.pb(s);
    u.pb(s);
    s.pop_back();
    s += y; 
    if (SZ(v) < 25) v.pb(s);
    trans.pb(s); 
    // cout << u[i] << ' ' << trans[i] << '\n'; 
  }
  sort(all(v)); 

  vector<vector<string>> base(5); 
  vector<vector<string>> xbase(5); 
  base[0] = v, xbase[0] = v;
  forr(i,1,5) base[i] = u; 
  forr(i,1,5) xbase[i] = trans; 

  // DBG(SZ(v)); 
  // for (auto x: u) cout << x << '\n'; 
  // RAYA; 


  vi act(5); 
  forn(k,n) {
    forn(i,5) cout << base[i][act[i]]; 
    cout << '\n'; 
    
    int i = 0;
    while (act[i] == 24) {
      reverse(all(base[i])), reverse(all(xbase[i])), act[i] = 0;
      
      if (i > 0) {
        forn(j,5) {
          if (j == i) cout << xbase[j][act[j]]; 
          else cout << base[j][act[j]]; 
        }
        cout << '\n'; 
        k++; 
        if (k == n) return 0;
      }
      i++;
      
    }
    act[i]++; 
  }

  return 0;
}