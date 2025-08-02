#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"
#define DBGV(v,n) cerr << #v << " = "; forn(_,n) cerr << v[_] << ' '

int n, m;
vector <string> f;
bool compare(vector <string> &v){
  bool listo=true;
  forn(i,n) forn(j,m) if(v[i][j]!=f[i][j]) listo=false;
  if(listo) cout << "yes\n";
  return listo;
}

void mover(vector <string> &v, int t){
  int k=t%2;
  if(t<2){
    forn(i,n){
      int cont=0;
      forn(j,m) if(v[i][(m-1)*k+(1-2*k)*j]!='.'){
        char c=v[i][(m-1)*k+(1-2*k)*j];
        v[i][(m-1)*k+(1-2*k)*j]='.';
        v[i][(m-1)*k+(1-2*k)*cont]=c;
        cont++;
      }
    }
  }
  else{
    forn(j,m){
      int cont=0;
      forn(i,n) if(v[(n-1)*k+(1-2*k)*i][j]!='.'){
        char c=v[(n-1)*k+(1-2*k)*i][j];
        v[(n-1)*k+(1-2*k)*i][j]='.';
        v[(n-1)*k+(1-2*k)*cont][j]=c;
        cont++;
      }
    }
  }
}

bool check(vector <string> v, vector <int> p){
  forn(i,80){
    int t=i%4;
    mover(v,p[t]);
    // forn(i,n){
    //   cout << v[i] << "\n";
    // }
    // RAYA;
    if(compare(v)) return true;
  }
  return false;
}


int main() {
  FIN;
  cin >> n >> m;
  vector <string> v(n); f.resize(n);
  forn(i,n) cin >> v[i];
  forn(i,n) cin >> f[i];
  if(compare(v)) return 0;
  if(check(v,{0,2,1,3}) or check(v,{0,3,1,2}) or check(v,{1,2,0,3}) or check(v,{1,3,0,2}) or check(v,{2,0,3,1}) or check(v,{2,1,3,0}) or check(v,{3,0,2,1}) or check(v,{3,1,2,0})) return 0;
  cout << "no\n";
  return 0;
}