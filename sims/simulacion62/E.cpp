#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n) 
#define SZ(x) int((x).size()) 
#define all(v) begin(v),end(v)
#define pb push_back
#define ff first
#define ss second 
#define DBG(x) cerr << #x << " = " << x << endl 
#define RAYA cerr << "========================\n" 

vector <int> ans;

void solve(int l, int r, int s, int o){
  if(r<l) return;
  s++;
  int med=(r+l)/2;
  if(s==o) ans.pb(med);
  solve(l,med-1,s,o); solve(med+1,r,s,o);
}

int main() {
  FIN; 
  int t;cin >> t;
  while(t--){
    int n, s; cin >> n >> s;
    solve(0,n-1,0,s);
    sort(all(ans));
    forn(i,SZ(ans)) cout << ans[i] << " ";
    cout << "\n";
    ans.clear();
  }
  return 0; 
} 
