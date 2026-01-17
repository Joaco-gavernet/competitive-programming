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
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << '\n'
#define RAYA cerr << "===========================\n"

typedef long long tipo; 

struct CD {
  double r, i;
  CD(double r = 0, double i = 0): r(r), i(i) {}
  double real() const { return r; }
  void operator /= (const tipo c) { r /= c; i /= c; }
};

CD operator * (const CD &a, const CD &b) { return CD(a.r*b.r-a.i*b.i, a.r*b.i+a.i*b.r); }
CD operator + (const CD &a, const CD &b) { return CD(a.r+b.r, a.i+b.i); }
CD operator - (const CD &a, const CD &b) { return CD(a.r-b.r, a.i-b.i); }

const double pi = acos(-1);
const tipo MAXN = 1<<21; 
CD cp1[MAXN+9], cp2[MAXN+9];
tipo R[MAXN+9]; 

void dft(CD * a, tipo n, bool inv) {
  forn(i,n) if (R[i] < i) swap(a[R[i]], a[i]);
  for (int m = 2; m <= n; m *= 2) {
    double z = 2*pi/m*(inv?-1:1);
    CD wi = CD(cos(z), sin(z)); 
    for (int j = 0; j < n; j+= m) {
      CD w(1);
      for (int k = j, k2 = j+m/2; k2<j+m; k++, k2++) {
        CD u = a[k]; CD v = a[k2]*w; a[k] = u + v; a[k2] = u - v; w = w * wi; 
      }
    }
  }
  if (inv) forn(i,n) a[i] /= n; 
}

vector<tipo> multiply(vector<tipo> &p1, vector<tipo> &p2) {
  tipo n = SZ(p1) + SZ(p2) + 1;
  tipo m = 1, cnt = 0;
  while (m <= n) m += m, cnt++;
  forn(i,m) { R[i] = 0; forr(j,0,cnt) R[i] = (R[i]<<1) | ((i>>j)&1); }
  forn(i,m) cp1[i] = cp2[i] = 0;
  forn(i, SZ(p1)) cp1[i] = p1[i];
  forn(i, SZ(p2)) cp2[i] = p2[i];
  dft(cp1, m, 0); dft(cp2, m, 0);
  forn(i,m) cp1[i] = cp1[i]*cp2[i];
  dft(cp1, m, 1);
  vector<tipo> res;
  n -= 2; 
  forn(i,n) res.pb((ll)floor(cp1[i].real()+.5)); 
  return res; 
}

int main() {
  FIN;
  int n; cin >> n;
  vb t(n+1,false), s(n+1,false);
  vi v(n+1);
  int last=0;
  forr(i,1,n+1){
    string a, b;
    cin >> a >> v[i] >> b;
    if(a=="+") s[i]=true;
    else last=i;
    if(b[0]=='a') t[i]=true;
  }
  vi p(1,1);
  ll sum=0;
  for(int i=last; i>=0; i--) if(s[i] and t[i]){
    vi aux(v[i]+1);
    aux[0]=1; aux[v[i]]=1;
    p=multiply(p,aux);
    forn(j,SZ(p)) if(p[j]>0) p[j]=1;
  }
  vb ans(1000001,false);
  if(!t[last]){
    ll lastsum=0;
    forr(i,last,n+1) if(s[i]) lastsum+=v[i];
    //DBG(lastsum);
    //forn(i,SZ(p)) if(p[i]>0) DBG(i);
    forn(i,SZ(p)) if(p[i]>0) ans[i+lastsum]=true;
  }
  vi ini;
  forn(i,n+1) if(!s[i] and t[i]){
    if(SZ(ini)<v[i]+1) ini.resize(v[i]+1);
    ini[v[i]]=1;
  }
  //forn(i,SZ(ini)) if(ini[i]>0) DBG(i);
  vi q(1,1);
  for(int i=n; i>last; i--) if(s[i]){
    sum+=v[i];
    if(!t[i] and i>last){
      if(SZ(q)<sum+1) q.resize(sum+1);
      q[sum]=1;
    }
    else{
      vi aux(v[i]+1);
      aux[0]=1; aux[v[i]]=1;
      q=multiply(q,aux);
    }
    RAYA;
    forn(i,SZ(q)) if(q[i]>0) DBG(i);
    forn(i,SZ(q)) if(q[i]>0) q[i]=1;
  }
  RAYA;
  forn(i,SZ(q)) if(q[i]>0) DBG(i);
  p=multiply(p,q);
  ini=multiply(ini,p);
  forn(i,SZ(ini)) if(ini[i]>0) ans[i]=true;
  ll cont=0;
  forn(i,SZ(ans)) if(ans[i]) cont++;
  cout << cont << "\n";
  return 0;
}