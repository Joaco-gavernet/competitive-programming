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
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);


struct Hash {
  const ll P=1777771;
  const ll MOD[2] = {999727999, 1070777777};
  const ll PI[2] = {325255434, 10018302};

  vector<ll> h[2],pi[2];
  Hash(string& s){
    forn(k,2)h[k].resize(s.size()+1),pi[k].resize(s.size()+1);
    forn(k,2){
      h[k][0]=0;pi[k][0]=1;
      ll p=1;
      forr(i,1,s.size()+1){
        h[k][i]=(h[k][i-1]+p*s[i-1])%MOD[k];
        pi[k][i]=(1LL*pi[k][i-1]*PI[k])%MOD[k];
        p=(p*P)%MOD[k];
      }
    }
  }
  ll get(ll s, ll e){ // [s, e] (s y e van de 0 a n-1)
    e++;
    ll h0=(h[0][e]-h[0][s]+MOD[0]);
    h0=(1LL*h0*pi[0][s])%MOD[0];
    ll h1=(h[1][e]-h[1][s]+MOD[1]);
    h1=(1LL*h1*pi[1][s])%MOD[1];
    return (h0<<32)|h1;
  }
};

int main(){
  FIN;

  string s,z; cin >> s >> z;
  Hash a(s);
  Hash b(z);

  int n = s.size();
  int m = z.size();

  ll obj = b.get(0,m-1);
  int tot = 0;

  dbg(obj);
  forn(i,n-m+1) {
    dbg(a.get(i,i+m-1));
    if (a.get(i,i+m-1) == obj) tot++;
  }
  cout << tot << endl;



  return 0;
}
