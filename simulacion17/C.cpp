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

const int MAXN = -1;
const int INF = -1;
const int MOD = -1;


int solve(ll s) {
  FIN;

  ll l=0,r=s+1;
  while(r-l>1){
    ll med=(r+l)/2;
    ll cont=0;
    for(int i=1;i*i<med;i++){
      ll x = sqrt(med-i*i) +2;
      while (x * x > med-i*i) x--;
      cont += x;
    }
    if(4*cont<=s) l=med;
    else r=med;
  }
  cout << fixed << setprecision(10);
  cout << sqrtl(r) << "\n";
  
  return 0;
}

int main(){
  ll s;
  cin >> s;
  solve(s);
  return 0;
}
