#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii; 

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define esta(x,v) (v).find(x) != (v).end()
#define all(v) (v).begin(),(v).end() 
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"

vector<vector<bool>> visto1;
vector<vector<bool>> visto2;
ll a,b,c,d; 
ll ans;
ll n;
bool evalcasilla(ll x,ll y){
  if(x<n and x>=0 and y<n and y>=0) return true;
  else return false;
}

void proxis(ll posx,ll posy,ll x, ll y, vector<ii> &casillas){
  casillas.pb({posx+x,posy+y});
  casillas.pb({posx+x,posy-y});
  casillas.pb({posx-x,posy+y});
  casillas.pb({posx-x,posy-y});
  casillas.pb({posx+y,posy+x});
  casillas.pb({posx+y,posy-x});
  casillas.pb({posx-y,posy+x});
  casillas.pb({posx-y,posy-x});
}

void dfs(ll posx, ll posy, ii mov){
  if(mov.first==a and mov.second==b){
    //~ RAYA;
    vector<ii> casillas;
    proxis(posx,posy,a,b,casillas);
    for(auto u:casillas){
      if(evalcasilla(u.first,u.second) and !visto1[u.first][u.second]){
	visto1[u.first][u.second]=true;
	//~ DBG(u.first); DBG(u.second); DBG(mov.second);
	dfs(u.first,u.second,{c,d});
      }
    }
  }else{
    //~ DBG(n);
    vector<ii> casillas;
    proxis(posx,posy,c,d,casillas);
    for(auto u:casillas){
      if(evalcasilla(u.first,u.second) and !visto2[u.first][u.second]){
	visto2[u.first][u.second]=true;
	//~ DBG(u.first); DBG(u.second); DBG(mov.first);
	dfs(u.first,u.second,{a,b});
      }
    }
  }
  
  return;
}



int main() {
  FIN;
  ans=0;
  cin>>n;
  cin>>a>>b>>c>>d;
  visto1=vector<vector<bool>>(n,vector<bool>(n,false));
  visto2=vector<vector<bool>>(n,vector<bool>(n,false));
  visto1[0][0]=true;
  dfs(0,0,{a,b});
  dfs(0,0,{c,d});
  forn(i,n) forn(j,n) if(visto1[i][j] or visto2[i][j]) ans++;
  cout<<ans<<"\n";
  return 0;
}
