#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<bool> vb;

#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()

const int INF = -1;
const int MOD = -1;
const int MAXN = -1;

int main() {
  FIN;
  
  string str; cin >> str;
  ll s; cin >> s;
  ll n = SZ(str);
  
  // caso facil
  bool ult = true;
  for (char c : str) if (c == 'E') ult = false;
  
  if (ult) {
    cout << "0" << endl;
    return 0;
  }
  
  vi preproc; 
  int i = 0, cont = 0;
  while (i < n) {
    while (i < n and str[i] == 'P') cont++, i++;
    if (i == n and str[0] == 'P') preproc[0] += cont;
    else preproc.pb(cont);
    cont = 0;
    i++;
  }
  
  ll ans = n*s;
  
  // hago restas de las p's
  for (ll m : preproc) {
    forr(j,1,min(s,m)+1) {
      ans -= (m-j+1);
    }
  }
  
  cout << ans << endl;
  
  
  return 0;
}
