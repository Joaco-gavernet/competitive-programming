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
#define all(v) begin(v),end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "========================\n" 


const int MAXN = (1<<20);
ll c1[MAXN+9], c2[MAXN+9]; 

void fht(ll *p, int n, bool inv) {
  for (int l = 1; 2*l <= n; l *= 2) for (int i = 0; i < n; i += 2*l) forn(j,l) {
    ll u = p[i+j], v = p[i+l+j]; 
    if (!inv) p[i+j] = u+v, p[i+l+j] = u; 
    else p[i+j] = v, p[i+l+j] = u-v; 
  } 
} 

vi multiply(vi &p1, vi &p2) {
  int n = 1<<(32-__builtin_clz(max(SZ(p1), SZ(p2)) -1)); 
  forn(i,n) c1[i] = 0, c2[i] = 0; 
  forn(i,SZ(p1)) c1[i] = p1[i]; 
  forn(i,SZ(p2)) c2[i] = p2[i]; 
  fht(c1, n, false); fht(c2, n, false); 
  forn(i,n) c1[i] *= c2[i]; 
  fht(c1, n, true); 
  return vi(c1, c1+n); 
} 

int leer(){
	string s; cin >> s;
	int ans=0;
	forn(i,SZ(s)) if(s[i]=='1') ans+=1<<i;
	return ans;
}

int main() {
  FIN;
 int n, k; cin >> n >> k;
 vi p(1<<k);
 forn(i,n) p[leer()]++;
 vi p2=multiply(p,p), p3=multiply(p2,p);
 int q; cin >> q;
 while(q--){
	int a=leer();
	cout << (p3[a]-3*p2[a]+2*p[a])/6 << "\n";
 }
  return 0; 
} 
