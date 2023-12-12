/*   AUTHOR: Estufa en Piloto   */
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "===============================" << endl
#else
#define DBG(x)
#define RAYA
#endif

typedef long long ll;
typedef vector<ll> vi; typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define SZ(x) int((x).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())
const int INF = 1<<30; // const ll INF = (1LL<<60);
const int MOD = 1e9+7;  // const int MOD = 998244353;
const int MAXN  = 2e5+5;

#define par(s) (s.size()%2==0)

int main(){
  FIN;
  
  string s; cin  >> s;
  int n = SZ(s);

  int chars[26] = {0};
  for (char i : s) chars[int(i)-'A']++; // build histogram
  
  int z = -1;
  int i = 0;
  while (i < 26) {
    if (par(s) and chars[i]%2 != 0) break;
    else if (!par(s) and chars[i]%2 != 0) {
      if (z != -1) break;
      else z = i;
    }
    i++;
  }
  if (par(s)) { // si s es par, se asigna z a un index valido de chars
    forn(j,26) {
      if (chars[j] > 0) {
	z = int(j);
	break;
      }
    }
  }
  
  if (i < 26) cout << "NO SOLUTION\n";
  else {
    string res(n,'*');
    int a = n/2 - chars[z]/2;
    int b = n/2 + n%2 + chars[z]/2;
    forr(j,a,b) res[j] = char(z+'A');
    chars[z] = 0;
    
    // se agregan simetricamente las letras
    int j = 0, k = 0;
    while (j < a) {
      if (chars[k] > 0) {
	res[j] = char(k+'A');
	res[n-j-1] = char(k+'A');
	chars[k]-=2;
	j++;
      } else k++;
    }

    cout << res << '\n';
  }
  
  return 0;
}







