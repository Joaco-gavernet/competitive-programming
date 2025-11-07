#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define ff first
#define ss second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl


/* Algoritmo O(n^3) para assignment problem
 * Inspirando el el notebook vasito, quien se inspiro
 * en http://e-maxx.ru/algo/assignment_hungary
 */
typedef ll td; typedef vector<td> vd;
const td INF = 1LL<<60; //for maximum set INF to 0, and negate costs
bool zero(td x){return fabs(x)<1e-9;}//change to x==0, for ints/ll
struct Hungarian{
  int n; vector<vd> cs; vi L, R;
  Hungarian(int N, int M):n(max(N,M)),cs(n,vd(n)),L(n),R(n){
    forn(x,N)forn(y,M)cs[x][y]=INF;
  }
  void set(int x,int y,td c){cs[x][y]=c;}
  td assign() {
    int mat = 0; vd ds(n), u(n), v(n); vi dad(n), sn(n);
    forn(i,n)u[i]=*min_element(all(cs[i]));
    forn(j,n){v[j]=cs[0][j]-u[0];forr(i,1,n)v[j]=min(v[j],cs[i][j]-u[i]);}
    L=R=vi(n, -1);
    forn(i,n)forn(j,n)
    if(R[j]==-1&&zero(cs[i][j]-u[i]-v[j])){L[i]=j;R[j]=i;mat++;break;}
    for(;mat<n;mat++){
      int s=0, j=0, i;
      while(L[s] != -1)s++;
      fill(all(dad),-1);fill(all(sn),0);
      forn(k,n)ds[k]=cs[s][k]-u[s]-v[k];
      for(;;){
        j = -1;
        forn(k,n)if(!sn[k]&&(j==-1||ds[k]<ds[j]))j=k;
        sn[j] = 1; i = R[j];
        if(i == -1) break;
        forn(k,n)if(!sn[k]){
          auto new_ds=ds[j]+cs[i][k]-u[i]-v[k];
          if(ds[k] > new_ds){ds[k]=new_ds;dad[k]=j;}
        }
      }
      forn(k,n)if(k!=j&&sn[k]){auto w=ds[k]-ds[j];v[k]+=w,u[R[k]]-=w;}
      u[s] += ds[j];
      while(dad[j]>=0){int d = dad[j];R[j]=R[d];L[R[j]]=j;j=d;}
      R[j]=s;L[s]=j;
    }
    td value=0;forn(i,n)value+=cs[i][L[i]];
    return value;
  }
};


int main(){
  FIN;

  int n; cin >> n; 
  vector<vi> c(n, vi(n)); 

  Hungarian hun(n, n); 
  forn(y,n) forn(x,n) cin >> c[y][x], hun.set(y, x, c[y][x]); 
  ll best = hun.assign(); 
  cout << best << '\n'; 
  forn(i,n) cout << i +1 << ' ' << hun.L[i] +1 << '\n'; 

  return 0;
}
