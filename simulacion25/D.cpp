#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=============================\n" 


const int MAXN = 1e5+5;

ii dfs(const int w) {
  int m, n; cin >> m >> n; 
  ll ans = 0;
  multiset<ll> st; 
  ll restos = 0; 

  forn(_,n) {
    auto [_ans, _n] = dfs(w);
    ans += _ans; 
    st.insert(_n); 
    restos += _n; 
  }

  while (restos > w) {
    auto mx = *st.rbegin(); 
    st.erase(st.find(mx)); 
    ans++;
    restos -= mx;
  }
  m += restos; 

  if (m > w) { 
    ans += m/w; 
    m %= w; 
  }
  return {ans, m};
}

int main() {
  FIN; 

  ll w; cin >> w; 
  auto [ans, n] = dfs(w); 
  cout << ans + (n+w-1)/w << endl; 


  return 0;
}
