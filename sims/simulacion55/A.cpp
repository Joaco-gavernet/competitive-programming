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
#define ff first
#define ss second 




int main() {
  FIN;

  int dx, dy, k; cin >> dx >> dy >> k; 
  vector<vector<vi>> tab(k,vector<vi>(dx,vi(dy,0)));
  vi wx(k), wy(k); 
  vector<vi> on(dx,vi(dy,0));
  queue<ii> next;
  forn(i,k) {
    // DBG(i);
    cin >> wx[i] >> wy[i]; 
    int b; cin >> b;
    ll a,d;
    forn(j,b){
      // DBG(j);
      cin >> a >> d;
      a--; d--;
      // DBG(a); DBG(d);
      if(on[a][d]==0){
        on[a][d]=1;
        next.push({a,d});
      }
      tab[i][a][d]=1;
    }
  }
  // RAYA;
  while(SZ(next)){
    ii ca=next.front(); next.pop();
    forn(i,k) if(!tab[i][ca.first][ca.second]){
      ll u=ca.ff-wx[i];
      ll v=ca.ss-wy[i];
      if(!on[u][v]){
        on[u][v]=1;
        next.push({u,v});
      }
    }
  }
  forn(i,dy){
    forn(j,dx){
      if(on[j][i]) cout<<"#"; 
      else cout<<".";
    }
    cout<<"\n";
  }
  cout<<"\n";
  // RAYA;
  queue<ii> next2;
  vector<vi> on2(dx,vi(dy,1));
  forn(i,k){
    forn(x,dx) forn(y,dy){
      // DBG(x); DBG(y);
      if((x<wx[i] or y<wy[i] or x-wx[i]>=dx or y-wy[i]>=dy)and(!tab[i][x][y])){
        on2[x][y]=0;
        next2.push({x,y});
      }
      // RAYA;
      if(!(x<wx[i] or y<wy[i] or x-wx[i]>=dx or y-wy[i]>=dy) and tab[i][x][y]){
        ll x2=x; ll y2=y;
        x2-=wx[i]; y2-=wy[i];
        if(on2[x2][y2]==1){
          on2[x2][y2]=0;
          next2.push({x2,y2});
        }
      }
    }
  }
  // RAYA;
  while(SZ(next2)){
    ii el=next2.front(); next2.pop();
    // DBG(el.ff); DBG(el.ss);
    forn(i,k){
      // DBG(i);
      // DBG(el.ff+wx[i]); DBG(el.ss+wy[i]);
      if(el.ff+wx[i]<dx and el.ss+wy[i]<dy and el.ff+wx[i]>=0 and el.ss+wy[i]>=0 and 
  !tab[i][el.ff+wx[i]][el.ss+wy[i]] and on2[el.ff+wx[i]][el.ss+wy[i]]==1){
        // DBG(el.ff+wx[i]); DBG(el.ss+wy[i]);
        // RAYA;
        on2[el.ff+wx[i]][el.ss+wy[i]]=0;
        next2.push({el.ff+wx[i],el.ss+wy[i]});
      }
    }
  }
  // RAYA;
  forn(i,dy){
    forn(j,dx){
      if(on2[j][i]) cout<<"#"; 
      else cout<<".";
    }
    cout<<"\n";
  }

  return 0;
}
