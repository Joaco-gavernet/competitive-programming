#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++) 
#define forn(i,n) forr(i,0,n) 
#define pb push_back
#define esta(x,v) ((v).find(x) != (v).end()) 
#define SZ(x) int((x).size())
#define all(v) (v).begin(),(v).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define DBGV(v,n) forn(i,n) cerr << v[i] << ' '
#define RAYA cerr << "=================================\n"


const int MAXN = 1e5+5; 
const ll MOD = 998'244'353; 

vi dp(MAXN);

ll algo(int pos, vi &t) {
  int n = SZ(t) -2; 
  ll ans = 0; 
  while (n >= 0) {
    if (pos == t[n]) n--; 
    else if (pos + t[n] == 4) {
      (ans += 4*dp[n] +2) %= MOD; 
      n--;
    } else {
      (ans += 2*dp[n] +1) %= MOD; 
      pos = 4 - pos; 
      n--; 
    }
  }
  
  return ans; 
}

void solve() {
  int n; cin >> n; 
  vi prev(n); forn(i,n) cin >> prev[i]; 
  vi post(n); forn(i,n) cin >> post[i]; 
  
  // descartamos los discos grandes bien ubicados 
  for (int i = n-1; i >= 0; i--) {
    if (prev[i] == post[i]) {
      prev.pop_back(); 
      post.pop_back(); 
    } else break; 
  }
  n = SZ(prev); 
  if (n == 0) {
    cout << 0 << '\n';
    //~ RAYA; 
    return; 
  }
  
  //~ DBGV(prev,n); 
  //~ cout << endl; 
  //~ DBGV(post,n); 
  //~ cout << endl; 
  
  ll ans = 1; 
  int pos; 
  if (prev[n-1] + post[n-1] == 4) {
    (ans += 2*dp[n-1] + 1) %= MOD; 
    pos = 4 -prev[n-1]; 
  } else {
    if (prev[n-1] == 2) pos = 4 -post[n-1]; 
    else pos = 4 - prev[n-1]; 
  }
  ans += algo(pos, prev); 
  
  if (prev[n-1] + post[n-1] == 4) {
    (ans += algo(4-pos, post)) %= MOD; 
  } else {
    (ans += algo(pos, post)) %= MOD; 
  }
  
  cout << ans << '\n'; 
}

int main() {
  FIN;   
  forr(i,1,MAXN) dp[i] = (3*dp[i-1] +1) %MOD;  
  int t; cin >> t;
  forn(_,t) solve(); 
  return 0; 
}


