#include <bits/stdc++.h> 
using namespace std;

typedef long long ll; 
typedef vector<ll> vi; 
typedef pair<ll,ll> ii; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) (v).begin(), (v).end()
#define esta(v,x) (v).find(x) != (v).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "======================================\n"
#define DBGV(v,n) forn(i,n) cerr << v[i] << ' '



int main() {
  FIN; 
  int n, k;
  cin >> n >> k;
  vector <double> v(n);
  forn(i,n) cin >> v[i];
  sort(all(v)); reverse(all(v));
  vector <long double> dp(10002);
  forn(i,5001) dp[i]=1;
  long double ans=0;
  forn(i,n){
    vector <long double> aux(10002);
    aux[0]=1;
    forr(j,1,10001) aux[j]=dp[j+1]*(1-v[i])+dp[j-1]*v[i];
    ans=max(ans,aux[k+5000]);
    dp=aux;
  }
  cout << fixed << setprecision(10);
  cout << ans << "\n";
  return 0;
}
