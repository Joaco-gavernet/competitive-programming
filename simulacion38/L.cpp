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

const ll MOD=998244353;
//00 01 10 11
//000 001 010 011 100 101 110 111
//0000 0001 0010 0011 0100 0101 0110 0111 1000 1001 1010 1011 1100 1101 1110 1111

vi cal(ll mask, vector<vb> &sigue, int k){
  vi tot(101);
  int t=1<<(k+1);
  vector<vi> dp(101,vi(t));
  forn(i,t) if(((mask&(1<<i))!=0)) {tot[k+1]++; dp[k+1][i]=1;}
  forr(i,k+2,101){
    forn(j,t) if(((mask&(1<<j))!=0)){
      forn(q,t) if(sigue[q][j]) dp[i][j]=(dp[i][j]+dp[i-1][q])%MOD;
      tot[i]=(tot[i]+dp[i][j])%MOD;
    }
  }
  return tot;
}

int main() {
  FIN; 
  int n, m, k;
  cin >> n >> m >> k;
  if(n<m) swap(n,m);
  if(n==k){cout <<"1\n"; return 0;}
  string obj; cin >> obj;
  int t=1<<(k+1), c=1<<t;
  vb incluye(t);
  vector <string> v; v.pb("0"); v.pb("1");
  //~ RAYA;
  forn(i,k){
    int aux=SZ(v);
    forn(j,aux){
      //~ cout << j << endl;
      //~ cout << t << endl;
      //~ DBG(SZ(v));
      v.pb("1"+v[j]);
      v[j]="0"+v[j];
    }
  }
  forn(i,t){
    if(v[i].substr(0,k)==obj) incluye[i]=true;
    if(v[i].substr(1,k)==obj) incluye[i]=true;
  }
  //~ forn(i,t) if(incluye[i]) cout << i << endl;
  //~ RAYA;
  vector <vb> sigue(t, vb(t,true));
  forn(i,t) forn(j,t) forn(p,k) if(v[i][1+p]!=v[j][p]) sigue[i][j]=false;
  vector <vi> dp(c);
  forn(mask,c){
    dp[mask]=cal(mask,sigue,k);
  }
  //~ RAYA;
  //~ forn(mask,c){
    //~ forn(i,t) if((mask&(1<<i))!=0) cout << v[i] << " ";
    //~ cout << endl;
    //~ DBGV(dp[mask],4);
    //~ cout << endl;
  //~ }
  //~ RAYA;
  ll ans=0;
  vector <vi> newdp=dp;
  forn(mask,c){
    int borrar=0;
    forn(i,t) if((mask&(1<<i))!=0 and !incluye[i]) borrar+=1<<i;
    newdp[mask][n]=(newdp[mask][n]-dp[borrar][n]+MOD)%MOD;
    if(n!=m) newdp[mask][m]=(newdp[mask][m]-dp[borrar][m]+MOD)%MOD;
  }
  if(m==k){cout << newdp[c-1][n] << "\n"; return 0;}
  //~ forn(mask,c){
    //~ forn(i,t) if((mask&(1<<i))!=0) cout << v[i] << " ";
    //~ cout << endl;
    //~ DBGV(newdp[mask],4);
    //~ cout << endl;
  //~ }
  //~ RAYA;
  vector <vi> newnewdp=newdp;
  forn(mask,c){
    vector <int> unos;
    forn(i,t) if((mask&(1<<i))!=0) unos.pb(i);
    int u=SZ(unos);
    forn(i,(1<<u)-1){
      int nmask=mask;
      forn(j,u) if((i&(1<<j))==0) nmask-=1<<unos[j];
      newnewdp[mask][n]=(newnewdp[mask][n]-newnewdp[nmask][n]+MOD)%MOD;
    }
  }
  
  //~ forn(mask,c){
    //~ forn(i,t) if((mask&(1<<i))!=0) cout << v[i] << " ";
    //~ cout << endl;
    //~ DBGV(newdp[mask],4);
    //~ cout << endl;
  //~ }
  //~ RAYA;
  forn(mask, c){
    ans=(ans+newnewdp[mask][n]*newdp[c-1-mask][m])%MOD;
  }
  cout << ans << "\n";
  return 0; 
}


