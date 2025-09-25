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

int main(){  
  FIN;
  int n, d;
  cin >> n >> d;
  int cont=n;
  vb ans(n+1,true);
  vi c(10),v(n+1),mini1(10,n),mini2(10,n),mini3(10,n);
  v[n]=INF;
  forn(i,n){
    cin >> v[i];
    c[v[i]%10]++;
    if(v[i]<v[mini3[v[i]%10]]) mini3[v[i]%10]=i;
    if(v[mini3[v[i]%10]]<v[mini2[v[i]%10]]) swap(mini2[v[i]%10],mini3[v[i]%10]);
    if(v[mini2[v[i]%10]]<v[mini1[v[i]%10]]) swap(mini2[v[i]%10],mini1[v[i]%10]);
  }
  if(d==0){
    cout << cont << "\n";
    forn(i,n) if(ans[i]) cout << v[i] << " ";
    return 0;
  }
  if(d==5){
    forn(i,n){
      bool ok=false;
      if(v[i]%2==0){cont--; ans[i]=false;}
      else if(v[i]%5==0) ok=true;
      if(!ok){ cout << -1 << "\n"; return 0;}
    }
  }
  if(d%2==1 and d!=5){
    forn(i,n) if(v[i]%2==0 or v[i]%5==0) {cont--; ans[i]=false;}
    ll p=1;
    forn(i,c[3]%4) p=(p*3)%10;
    forn(i,c[7]%4) p=(p*7)%10;
    forn(i,c[9]%4) p=(p*9)%10;
    if(d!=p){
      int k=(p*d*d*d)%10;
      if(k==3){
	if(v[mini1[3]]<v[mini1[7]]*v[mini1[9]] and (v[mini1[3]]<v[mini1[7]]*v[mini2[7]]*v[mini3[7]] or v[mini3[7]]==INF)){
	  cont--;
	  ans[mini1[3]]=false;
	}
	else if(v[mini1[7]]*v[mini1[9]]<v[mini1[7]]*v[mini2[7]]*v[mini3[7]] or v[mini3[7]]==INF){
	  cont-=2;
	  ans[mini1[7]]=false; ans[mini1[9]]=false;
	}
	else{
	  cont-=3;
	  ans[mini1[7]]=false; ans[mini2[7]]=false; ans[mini3[7]]=false;
	}
	if(c[3]<1 and (c[7]<1 or c[9]<1) and c[7]<3) {cout << -1 << "\n"; return 0;}
      }
      if(k==7){
	if(v[mini1[7]]<v[mini1[3]]*v[mini1[9]] and (v[mini1[7]]<v[mini1[3]]*v[mini2[3]]*v[mini3[3]] or v[mini3[3]]==INF)){
	  cont--;
	  ans[mini1[7]]=false;
	}
	else if(v[mini1[3]]*v[mini1[9]]<v[mini1[3]]*v[mini2[3]]*v[mini3[3]] or v[mini3[3]]==INF){
	  cont-=2;
	  ans[mini1[3]]=false; ans[mini1[9]]=false;
	}
	else{
	  cont-=3;
	  ans[mini1[3]]=false; ans[mini2[3]]=false; ans[mini3[3]]=false;
	}
	if(c[7]<1 and (c[3]<1 or c[9]<1)) {cout << -1 << "\n"; return 0;}
      }
      if(k==9){
	if(v[mini1[9]]<v[mini1[3]]*v[mini2[3]] and v[mini1[9]]<v[mini1[7]]*v[mini2[7]]){
	  cont--;
	  ans[mini1[9]]=false;
	}
	else if(v[mini1[3]]*v[mini2[3]]<v[mini1[7]]*v[mini2[7]]){
	  cont-=2;
	  ans[mini1[3]]=false; ans[mini2[3]]=false;
	}
	else{
	  cont-=2;
	  ans[mini1[7]]=false; ans[mini2[7]]=false;
	}
	if(c[7]<2 and c[9]<1 and c[3]<2) {cout << -1 << "\n"; return 0;}
      }
    }
  }
  vector <vector<vi>> tabla(10,vector<vi>(10,vi(10)));
  forn(i,10) forn(j,10) forn(k,10) tabla[i][j][k]=(i*j*k)%10;
  if(d%2==0 and d!=0){
    forn(i,n) if(v[i]%5==0) {cont--; ans[i]=false;}
    ll p=1;
    forn(i,c[3]%4) p=(p*3)%10;
    forn(i,c[7]%4) p=(p*7)%10;
    forn(i,c[9]%4) p=(p*9)%10;
    forn(i,c[2]) p=(p*2)%10;
    forn(i,c[4]) p=(p*4)%10;
    forn(i,c[6]) p=(p*6)%10;
    forn(i,c[8]) p=(p*8)%10;
    
  }
  if(cont==0) {cout << -1 << "\n"; return 0;}
  cout << cont << "\n";
  forn(i,n) if(ans[i]) cout << v[i] << " ";
  return 0;
}
