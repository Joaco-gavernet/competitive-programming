#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=====================================\n"


int main() {
  FIN;
  int n;  cin >> n;
  vector <pair<ii,int>> pos, neg;
  forn(i,n){
    string s; cin >> s;
    int a=0, b=0;
    forn(j,SZ(s)){
      if(s[j]=='(') b++;
      else if(b>0) b--;
      else a++;
    }
    if(b-a>=0) pos.pb({{a,b},i+1});
    else neg.pb({{-b,a},i+1});
  }
  sort(all(pos)); sort(all(neg));
  vi ans;
  int c=0;
  forn(i,SZ(pos)){
    if(pos[i].first.first>c) {cout << "impossible\n"; return 0;}
    c-=pos[i].first.first;
    c+=pos[i].first.second;
    ans.pb(pos[i].second);
  }
  forn(i,SZ(neg)){
    if(neg[i].first.second>c) {cout << "impossible\n"; return 0;}
    c-=neg[i].first.first;
    c-=neg[i].first.second;
    ans.pb(neg[i].second);
  }
  if(c!=0) {cout << "impossible\n"; return 0;}
  forn(i,n) cout << ans[i] << "\n";
  return 0;
}
