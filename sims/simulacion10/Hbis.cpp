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

vector <int> query(string &pal) {
  cout << "? " << pal << endl;
  int n; cin >> n;
  vector <int> ans(n);
  forn(i,n) cin >> ans[i], ans[i]--;
  return ans;

}

int main(){  
  //~ FIN;

  vector <string> s = {"","abcdeprtu","afghipstv","bfjklprw","cgjmnqsx","dhkmoqry","eilnoqstz"};
  vector <int> sumas = {0,1,10,100,1000,10000,100000};
  map<int,char> m;
  char let='a';
  forr(i,1,6){
    forr(j,i+1,7){
      m[sumas[i]+sumas[j]]= char(let);
      let++;
    }
  }

  m[111]='p';
  m[111000]='q';
  m[10101]='r';
  m[101010]='s';
  m[100011]='t';
  m[sumas[1]]='u';
  m[sumas[2]]='v';
  m[sumas[3]]='w';
  m[sumas[4]]='x';
  m[sumas[5]]='y';
  m[sumas[6]]='z';

  vector<int> palabra(10005,0);

  int maxi = 0;

  forr(i,1,7){
    vector <int> ans = query(s[i]); 
    if(SZ(ans) == 0) continue;
    maxi = max(maxi,*max_element(all(ans)));
    for(int u : ans) {
      palabra[u] += sumas[i];
    }
  }
  string ans;
  forn(i,maxi+1) {
    ans += m[palabra[i]];
  }
  cout << "! " << ans << endl;
  string rta; cin >> rta;

  return 0;

}
