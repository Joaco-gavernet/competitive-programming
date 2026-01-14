#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb; 
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=========================\n"
#define all(v) begin(v),end(v)
const ll INF=1e9, MAXN=3e5+5, LOG=32; //CAMBIAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAR
ll n, e, ans=0, p=0, a=0, b=0, d=0;
//ll jmp[MAXN][LOG], dst[MAXN][LOG];
vi k(MAXN,INF), nex(MAXN), last(MAXN,-1);
void step(){
  ans+=e;
  p=(p+e)%n;
  if(p==0) e++;
  else e--;
}

void jump(){
  ans+=e*k[e%n]-k[e%n]*(k[e%n]-1)/2;
  e=e-k[e%n]+2;
}

int main() {
  FIN;
  cin >> n >> e;
  if(e%n==0 or (2*e-1)%n==0 or (e%n==1 and e>1)) {cout << "infinity\n"; return 0;}
  
  ll s=0;
  forn(i,2*n){
    s=(s+i)%n;
    if(last[s]!=-1) k[i%n]=min(k[i%n],i-last[s]);
    last[s]=i;
  }
  forn(i,n) nex[i]=(i+n-k[i]+2)%n;
  /*forn(i,n) cout << nex[i] << " ";
  cout << endl;
  forn(i,n) cout << 2-k[i] << " ";
  cout << endl;*/
  /*forn(i,n){
    jmp[i][0]=nex[i];
    dst[i][0]=2-k[i];
  }
  forr(j,1,LOG) forn(i,n){
    jmp[i][j]=jmp[jmp[i][j-1]][j-1];
    dst[i][j]=dst[i][j-1]+dst[jmp[i][j-1]][j-1];
  }*/
 ll ce=e%n;
 a+=k[ce];
 b-=k[ce]*(k[ce]-1)/2;
 d=k[ce]-2;
 ce=nex[ce];
 while(ce!=e%n){
  a+=k[ce];
  b-=(d+k[ce])*(d+k[ce]-1)/2-d*(d-1)/2;
  d+=k[ce]-2;
  ce=nex[ce];
 }
 //cout << a << " " << b << endl;
 //cout << d << endl;
 ll t=(e-1)/d;
 ans+=b*t+a*e*t-a*d*t*(t-1)/2;
 e=e-(e-1)/d*d;
 while(e>k[e%n]-1) jump();
 while(e>0) step();
 cout << ans << "\n";
  return 0;
}