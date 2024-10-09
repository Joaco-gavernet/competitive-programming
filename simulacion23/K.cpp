#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==============================\n"


const int MAXN = 1e5+5;
const int INF = -1;
const int MOD = -1;

int main() {
  FIN; 

  string first, second; 
  getline(cin, first); 
  getline(cin, second); 

  // limpio los espacios en las strings
  string nfirst, nsecond; 
  for (char c : first) {
    if (c == ' ') continue; 
    nfirst += c; 
  }
  for (char c : second) {
    if (c == ' ') continue; 
    nsecond += c; 
  }

  vi fparent(MAXN), sparent(MAXN); 
  int parent = -1; 
  string aux; 
  for (char c: nfirst) {
    if (c != '(' and c != ')') {
      aux += c; 
    } else if (c == '(') {
      if (SZ(aux)) fparent[stoi(aux)] = parent; 
      if (SZ(aux)) parent = stoi(aux); 
      aux = ""; 
    } else {
      if (SZ(aux)) fparent[stoi(aux)] = parent; 
      else parent = fparent[parent]; 
      aux = ""; 
    }
  }
  parent = -1; 
  aux = ""; 
  for (char c: nsecond) {
    if (c != '(' and c != ')') {
      aux += c; 
    } else if (c == '(') {
      if (SZ(aux)) sparent[stoi(aux)] = parent; 
      if (SZ(aux)) parent = stoi(aux); 
      aux = ""; 
    } else {
      if (SZ(aux)) sparent[stoi(aux)] = parent; 
      else parent = sparent[parent]; 
      aux = ""; 
    }
  }
  forn(i,MAXN) {
    if (fparent[i] != sparent[i]) {
      cout << "No\n"; 
      return 0;
    }
  }
  cout << "Yes\n"; 
  
  return 0;
}
