#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << '\n'
#define RAYA cerr << "==============================\n"

bool can(int a, int b, int ka, int kb, int p, int mask, int c){
  if(c==6 and ((mask&(1<<5))==0) and p==0) return false;
  if(c==6 and ((mask&(1<<5))!=0) and p==1) return false;
  vi fa, fb;
  forn(i,c){
    if((mask&(1<<i))!=0){
      a-=i+2;
      fa.pb(i+2);
    }
    else{
      b-=i+2;
      fb.pb(i+2);
    }
  }
  a-=ka;
  b-=kb;
  if(a<0 or b<0 or a==1 or b==1) return false;
  if(a>ka*7 or b>kb*7) return false;
  vi ja, jb;
  forn(i,ka)if(a>=2){
    ja.pb(2);
    a-=2;
  }
  int aux=0;
  while(a>0){
    ja[aux]++;
    a--;
    aux=(aux+1)%SZ(ja);
  }
  forn(i,kb)if(b>=2){
    jb.pb(2);
    b-=2;
  }
  aux=0;
  while(b>0){
    jb[aux]++;
    b--;
    aux=(aux+1)%SZ(jb);
  }
  bool tur=true;
  int ia=0, ib=0;
  while(ia<ka){
    ia++;
    cout << 1;
    if(SZ(ja)){
      cout << ja.back();
      ja.pop_back();
    }
    else break;
  }
  cout << "/";
  tur=!tur;
  while(ib<kb){
    ib++;
    cout << 1;
    if(SZ(jb)){
      cout << jb.back();
      jb.pop_back();
    }
    else{
      cout << "/";
      tur=!tur;
      break;
    }
  }
  while(ia+ib<ka+kb){
    if(tur){
      if(ia<ka){
        cout << "1/";
        ia++;
      }
      else cout << "/";
      tur=!tur;
    }
    else{
      if(ib<kb){
        cout << "1/";
        ib++;
      }
      else cout << "/";
      tur=!tur;
    }
  }
  ia=0; ib=0;
  while(ia<SZ(fa) or ib<SZ(fb)){
    if(tur){
      if(ia==SZ(fa) or fa[ia]!=ia+ib+2){
        cout << "/";
        tur=!tur;
      }
      else {cout << fa[ia]; ia++;}
    }
    else{
      if(ib==SZ(fb) or fb[ib]!=ia+ib+2){
        cout << "/";
        tur=!tur;
      }
      else {cout << fb[ib]; ib++;}
    }
  }
  if(tur and p==1) cout << "/";
  if(!tur and p==0) cout << "/";
  cout << "\n";
  return true;
}

void solve() {
  int a, b, n, p; cin >> a >> b >> n >> p;
  int m=max(0,6-n);
  forn(i,1<<m) forn(k,min(15,21-n)+1){
    if(can(a,b,k,min(15,21-n)-k,p,i,m)) return;
  }
  cout << "NA\n";
}

int main() {
  FIN;
  int t; cin >> t;
  while (t--) solve();
  return 0;
}