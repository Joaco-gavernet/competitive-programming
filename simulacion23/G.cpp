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
#define DBGV(v,z) forn(i,z) cerr << v[i] << ' '; cerr << endl
#define RAYA cerr << "==============================\n"

const int MAXN = -1;
const int INF = -1;
const int MOD = -1;

int main() {
  FIN; 
  
  string n,m; cin >> n >> m; 
  
  map<string,int> mp;
  ll tot = 0, pasos = 1;
  mp[n]++; 
  if (n == m) {
    cout << "1\n"; 
    return 0; 
  }
  while (tot < 100) {
    vi cont(26, 0); 
    for (char c: n) cont[c-'0']++; 
    //~ DBGV(cont, SZ(cont)); 
    
    string aux; 
    forn(i,26) {
      if (cont[i] > 0) {
	aux += to_string(cont[i]) + char(i +'0');
      }
    }
    //~ DBG(aux); 
    if (mp[aux] == 0) tot++;
    else {
      cout << "Does not appear\n";
      return 0;
    }
    mp[aux]++; 
    
    pasos++;
    n = aux;
    if (m == aux) {
      cout << pasos << '\n';
      return 0; 
    }
    //~ RAYA; 
  }
  
  cout << "I'm bored\n"; 
  return 0;
  
}
