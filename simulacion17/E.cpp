#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i< (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) (v).begin(),(v).end()
#define fs first
#define ss second
#define DBG(c) cerr << #c << " = " << c << endl
#define RAYA cerr << "===================\n"

const int MAXN = -1;
const int INF = -1;
const int MOD = -1;


int main() {
  FIN;
  
  string s; cin >> s;
  int i = 0, a = 0, b = 0;
  while (i < SZ(s) and s[i] != '/') a *= 10, a += int(s[i++] -'0');
  i++;
  while (i < SZ(s)) b *= 10, b += int(s[i++] -'0');
  
  if (a < b-1) {
    cout << "impossible\n";
    return 0;
  }
  
  int k = 1;
  while (2*a +b > k*b*b) k++;
  a *= k;
  b *= k;
  
  
  
  vi padre(b+1);
  forn(j,b+1) padre[j]=j-1;
  ll cont=b*(b-1)/2-a;
  for(int j=b;j>2;j--){
    padre[j]=max(1LL,j-1-cont);
    cont-=j-1-padre[j];
  }
  cout << b << " " << b-1 << "\n";
  forr(j,2,b+1){
    cout << j << " " << padre[j] << "\n";
  }
  
  return 0;
}





