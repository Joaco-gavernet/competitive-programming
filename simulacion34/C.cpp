#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(int i = (ll)a; i <(ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define DBG(x) cerr << #x << " = " << x << endl
#define DBGV(v,n) forn(i,n) cerr << v[i] << ' '
#define RAYA cerr << "================================\n"


int ops; 
bool left(int j, int x) {
  //~ DBG("left"); 
  string ans; 
  while (j < x) {
    cout << j << ' ' << x << endl; 
    cin >> ans; j++; ops--; 
    if (ans == "WIN") return true;
  }
  return false; 
}

bool right(int j, int x) {
  //~ DBG("right"); 
  string ans; 
  while (j < x) {
    cout << j << ' ' << x << endl; 
    cin >> ans; x--; ops--; 
    if (ans == "WIN") return true;
  }
  return false; 
}

bool check(int n, int k) {
  //~ DBG("check"); 
  //~ DBG(k); 
  int i = 1; 
  string ans = "STAYED"; 
  while (i +1 < k and ans == "STAYED") {
    cout << i << ' ' << i +1 << endl; 
    ops--;  
    cin >> ans; 
    if (ans == "WIN") return true; 
    if (ans == "STAYED") i += 2;  
  }
  if (ans != "STAYED") {
    if (left(1,i)) return true; 
    if (right(i+1,n)) return true; 
    cout << i << ' ' << i +1 << endl; 
    cin >> ans; ops--;  
    if (ans == "WIN") return true;
    return false; 
  }

  i = 2; 
  //~ DBG("check2"); 
  ans = "STAYED"; 
  while (i +1 < k and ans == "STAYED") {
    cout << i << ' ' << i +1 << endl; 
    ops--;  
    cin >> ans; 
    if (ans == "WIN") return true;
    if (ans == "STAYED") i += 2;  
  }
  if (ans != "STAYED") {
    if (left(1,i)) return true; 
    if (right(i+1,n)) return true; 
    cout << i << ' ' << i +1 << endl; 
    cin >> ans; ops--;
    if (ans == "WIN") return true;  
    return false; 
  }
  if (right(k-1,n)) return true;  
  return false; 
}

int main() {
  FIN;
  
  string ans; 
  int n; cin >> n; 
  ops = 2*n; 
  forr(k,1,n) { // k es el primer numero que no conozco
  reset: forr(j,k+1,n+1) {
      cout << k << ' ' << j << endl;
      cin >> ans; 
      if (ans == "WIN") return 0; 
      ops--; 
      if (ops == 0) {
        ops = 2*n; 
        if (j == n) {
	  if (check(n,k+1)) return 0;  
	}
        else {
          if (check(n,k)) return 0; 
          goto reset; 
        }
	//~ DBG(ops); 
      }
    }
  }


  return 0; 
}
