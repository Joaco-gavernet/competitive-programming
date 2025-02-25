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

typedef vector<vector<double>> Matrix;

Matrix ones(int n){
  Matrix r(n,vector<double>(n));
  forn(i,n) r[i][i]=1;
  return r;
} 
Matrix operator*(Matrix &a, Matrix &b){
  int n=a.size(), m=b[0].size(), z=a[0].size();
  Matrix r(n,vector<double>(m));
  forn(i,n) forn(j,m) forn(k,z){
    r[i][j]+=a[i][k]*b[k][j];
  }
  return r;
}

Matrix be(Matrix b, ll e){
  Matrix r=ones(b.size());
  while(e){if(e&1LL)r=r*b;b=b*b;e/=2;}
  return r;
}

int main(){  
  FIN;
  ll e;
  cin >> e;
  e--;
  Matrix a(2,vector<double>(2)),b(2,vector<double>(2)),c(2,vector<double>(2));
  a[0][0]=100;
  b[0][1]=100;
  c[0][0]=0.5; c[1][0]=0.5; c[0][1]=1;
  c=be(c,e);
  a=a*c;
  b=b*c;
  //cout << a[0][0] << " " << a[1][0] << endl << a[0][1] << " " << a[1][1];
  //cout << endl;
  //cout << b[0][0] << " " << b[1][0] << endl << b[0][1] << " " << b[1][1];
  //cout << endl;
  cout << fixed << setprecision(10) << b[0][1] << " " << a[0][1] << "\n";
  return 0;
}
