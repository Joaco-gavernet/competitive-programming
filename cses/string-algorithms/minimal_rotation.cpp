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

#define RB(x) (x<n?r[x]:0)
void csort(vector<int>& sa, vector<int>& r, int k){
  int n=sa.size();
  vector<int> f(max(255,n),0),t(n);
  forr(i,0,n)f[RB(i+k)]++;
  int sum=0;
  forr(i,0,max(255,n))f[i]=(sum+=f[i])-f[i];
  forr(i,0,n)t[f[RB(sa[i]+k)]++]=sa[i];
  sa=t;
}

vector<int> suffix_array(string& s){ // O(n logn)
  s += '{';
  int n = s.size(), rank;
  dbg(n);
  vector<int> sa(n),r(n),t(n);
  forr(i,0,n) sa[i] = i, r[i] = s[i];
  for(int k=1; k<n; k*=2){
    csort(sa,r,k); csort(sa,r,0);
    t[sa[0]] = rank=0;
    forr(i,1,n){
      if(r[sa[i]] != r[sa[i-1]] || RB(sa[i]+k) != RB(sa[i-1]+k)) rank++;
      t[sa[i]] = rank;
    }
    r = t;
    if (r[sa[n-1]] == n-1) break;
  }
  return sa;
}

int main(){
  FIN;

  string s; cin >> s;
  int n = s.size();
  s += s;
  vector<int> ans = suffix_array(s);
  int i = ans[0];

  dbg(s);
  dbg(ans);
  dbg(i);

  string z;
  while (n > 0) {
    if (s[i] != '{') z += s[i], n--;
    (++i) %= s.size();
  }
  cout << z << '\n';


  return 0;
}
