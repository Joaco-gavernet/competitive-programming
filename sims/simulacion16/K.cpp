#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long ll;

using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

#ifdef LOCAL
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "===============================" << endl
#else
#define DBG(x)
#define RAYA
#endif

typedef long long ll;
typedef vector<int> vi; typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define SZ(x) int((x).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())
const int INF = 1<<30; // const ll INF = (1LL<<60);
const int MOD = 1e9+7;  // const int MOD = 998244353;
const int MAXN  = 2e5+5;

int main() {
  FIN;
  
  int N; cin >> N; 
  int n = N/2;
  vi ops(N);
  forn(i,n) cin >> ops[2*i];
  forn(i,n) cin >> ops[2*i+1];
  //~ for (int i : ops) DBG(i);
  
  // init indexed_set s
  vi example(N);
  forr(i,1,N+1) example[i-1]=i;
  indexed_set s(all(example));
  
  vi ansa(n), ansb(n);
  forn(i,n) {
    // operacion A
    auto elem = s.find_by_order(ops[2*i]-1);
    cout << *elem << " ";
    s.erase(elem);
    
    // operacion B      
    elem = s.find_by_order(ops[2*i+1]-1);
    ansb[i] = *elem;
    s.erase(elem);
  }
  
  // output
  cout << "\n";
  for (int i : ansb) cout << i << " ";
  cout << "\n";
  
  
  return 0;
}







