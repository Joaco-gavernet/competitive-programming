#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi; 
typedef pair<ll,ll> ii; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define all(v) (v).begin(),(v).end()
#define esta(x,v) (v).find(x) != (v).end() 
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==================================\n"
const int MAXN=1e5+5;
vi dp(MAXN,1);
vb visto(MAXN);
vector <vi> g(MAXN);
void dfs(int v){
  visto[v]=true;
  for(auto u : g[v]){
    if(!visto[u]) dfs(u);
    dp[v]=max(dp[v],dp[u]+1);
  }
}
int main() {
  FIN; 
  int n; cin >> n;
  forn(i,n){
    int k; cin >> k;
    forn(j,k){
      int a; cin >> a;
      a--;
      g[i].push_back(a);
    }
  }
  forn(i,n){
    if(!visto[i]) dfs(i);
    if(dp[i]==n){cout <<"1\n"; return 0;}
  }
  cout << "0\n";
  
  return 0; 
} 
