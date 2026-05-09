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

vi trans(int n){
  vi v;
  forn(_,9){v.pb(n%3); n/=3;}
  return v;
}

vector<vi> d={{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
vb visto(1e5,false);
vi ansx(1e5), anso(1e5);
void dfs(int n){
  visto[n]=true;
  vi v=trans(n);
  int x=0, o=0;
  forn(i,9) {
    if(v[i]==1) x++;
    if(v[i]==2) o++;
  }
  forn(r,8) if(v[d[r][0]]!=0 and v[d[r][0]]==v[d[r][1]] and v[d[r][0]]==v[d[r][2]]){
    if(x!=o) ansx[n]=1;
    else anso[n]=1;
    return;
  }
  forn(i,9) if(v[i]==0){
    if(x==o) v[i]=1;
    else v[i]=2;
    ll aux=0;
    for(int j=8; j>=0; j--){aux*=3; aux+=v[j];}
    if(!visto[aux]) dfs(aux);
    ansx[n]+=ansx[aux];
    anso[n]+=anso[aux];
    v[i]=0;
  }
}

void solve(){
  string s; cin >> s;
  int n=0, X=0, O=0;
  forn(i,9){
    n*=3;
    if(s[i]=='X') {n+=1; X++;}
    if(s[i]=='O') {n+=2; O++;}
  }
  if(!visto[n]) {cout << "-1 -1\n"; return;}
  cout << ansx[n] << " " << anso[n] << "\n";
}

int main() {
  FIN;
  int t; cin >> t;
  dfs(0);
  while(t--) solve();
  return 0;
}