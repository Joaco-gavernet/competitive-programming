#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "===========================\n"



int main() {
  FIN;
  int n;
  cin >> n;
  vector <string> s;
  forn(i,5000){
    string x;
    int k=i;
    forn(_,3) {x+='a'+k%18; k/=18;}
    s.pb(x);
  }
  vector <string> ans;
  ans.pb(s[0]+s[0]+s[0]);
  forn(i,SZ(s)-1){
    string r=s[i]+s[i]+s[i];
    forn(j,9) if(s[i][j%3]!=s[i+1][j%3]) {r[j]=s[i+1][j%3]; ans.pb(r);}
  }
  forn(i,n) cout << ans[i] << "\n";
  return 0;
}