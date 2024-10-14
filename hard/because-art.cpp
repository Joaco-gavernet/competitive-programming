#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define SZ(x) int((x).size())
#define fs first
#define ss second
#define RAYA cerr << "===============================" << endl

const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1LL<<60); // (1LL<<60)

typedef long long tipo;
typedef long double ld; 

struct CD{
  ld r,i;
  CD(ld r=0, ld i=0):r(r),i(i){}
  ld real()const{return r;}
  void operator /=(const tipo c){r/=c; i/=c;}
};
CD operator*(const CD& a, const CD& b){return CD(a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r);}
CD operator+(const CD& a, const CD& b){return CD(a.r+b.r,a.i+b.i);}
CD operator-(const CD& a, const CD& b){return CD(a.r-b.r,a.i-b.i);}
const ld pi=acos(-1);
const tipo MAXN=1<<21;
CD cp1[MAXN+9],cp2[MAXN+9];
tipo R[MAXN+9];

void dft(CD* a, tipo n, bool inv){
  forn(i, n) if(R[i]<i) swap(a[R[i]],a[i]);
  for(int m=2;m<=n;m*=2){
    ld z=2*pi/m*(inv?-1:1);
    CD wi=CD(cos(z),sin(z));
    for(int j=0;j<n;j+=m){
      CD w(1);
      for(int k=j,k2=j+m/2;k2<j+m;k++,k2++){
        CD u=a[k]; CD v=a[k2]*w;a[k]=u+v;a[k2]=u-v;w=w*wi;
      }
    }
  }
  if(inv) forn(i,n) a[i]/=n;
}

vector<tipo> multiply(vector<tipo> &p1, vector<tipo> &p2, bool deb = false){
  tipo n=SZ(p1)+SZ(p2)+1;
  tipo m=1,cnt=0;
  while(m<=n) m+=m,cnt++;
  forn(i, m){R[i]=0;forr(j,0,cnt)R[i]=(R[i]<<1)|((i>>j)&1);}
  forn(i, m) cp1[i]=cp2[i]=0;
  forn(i, SZ(p1)) cp1[i]=p1[i];
  forn(i, SZ(p2)) cp2[i]=p2[i];
  dft(cp1,m,0); dft(cp2,m,0);
  forn(i, m) cp1[i]=cp1[i]*cp2[i];
  dft(cp1,m,1);
  vector<tipo> res;
  n -= 2;
  forn(i,n) res.pb((ll)floor(cp1[i].real()+.5));
  return res;
}

void fmaxis(int n, vi &F, vi &C, vi &pairs, bool deb) {
  int l = 0, r = n-1;
  while (l <= r and F[l]*C[l] > 0) pairs.pb(F[l]*C[l]), l++;
  while (l <= r and F[r]*C[r] > 0) pairs.pb(F[r]*C[r]), r--; 
  sort(all(pairs), greater<ll>()); 
  forr(i,1,SZ(pairs)) pairs[i] += pairs[i-1];
  if (l <= r) {
    vi Ci(C.begin() +l, C.begin() +r +1);
    vi Fi(F.begin() +l, F.begin() +r +1);
    reverse(all(Ci));
    vi prod = multiply(Ci, Fi, deb);
    ll aux = 0;
    if (SZ(pairs)) aux = *(--pairs.end()); 
    for (int i = 0, j = SZ(prod) -1; i <= j; i++, j--) 
      pairs.pb(aux +max(prod[i], prod[j]));
  }
}

void fminis(int n, vi &F, vi &C, vi &pairs) {
  int l = 0, r = n-1;
  reverse(all(C)); 
  while (l <= r and F[l]*C[l] < 0) pairs.pb(F[l]*C[l]), l++;
  while (l <= r and F[r]*C[r] < 0) pairs.pb(F[r]*C[r]), r--; 
  sort(all(pairs)); 
  forr(i,1,SZ(pairs)) pairs[i] += pairs[i-1];
  if (l <= r) {
    vi Ci(C.begin() +l, C.begin() +r +1);
    vi Fi(F.begin() +l, F.begin() +r +1);
    reverse(all(Ci));
    vi prod = multiply(Ci, Fi);
    ll aux = 0;
    if (SZ(pairs)) aux = *(--pairs.end()); 
    for (int i = 0, j = SZ(prod) -1; i <= j; i++, j--) 
      pairs.pb(aux +min(prod[i], prod[j]));
  }
}


int main() {
  FIN; 

  int n; cin >> n;
  vi F(n), C(n);
  bool deb = false;
  forn(i,n) cin >> F[i];
  forn(i,n) cin >> C[i];
  sort(all(F));
  sort(all(C));

  vi maxis, minis;
  fmaxis(n, F, C, maxis, deb);
  fminis(n, F, C, minis);

  forn(i,n) cout << minis[i] << ' ' << maxis[i] << '\n';


  return 0; 
}

