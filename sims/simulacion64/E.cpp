#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i <(ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << '\n'
#define RAYA cerr << "============================\n"
#define ff first
#define ss second
ll INF=1LL<<60;

int main() {
  FIN;
  ll b, n; cin >> b >> n;
  map <string,int> mapa;
  vector <string> s(n);
  vi c(n), p(n), id(n);
  int cont=0;
  forn(i,n){
    string a, _;
    cin >> a >> s[i] >> _ >> c[i] >> p[i];
    if(mapa[a]==0){
      id[i]=cont;
      cont++;
      mapa[a]=cont;
    }
    else id[i]=mapa[a]-1;
  }
  vi r(cont);
  vector <vi> base(cont);
  vi hechas(cont);
  queue <int> q;
  forn(i,n){
    r[id[i]]++;
    if(mapa[s[i]]==0) q.push(i);
    else base[mapa[s[i]]-1].pb(i);
  }
  vector<ii> t(n,{INF,INF});
  while(SZ(q)>0){
    int i=q.front(); q.pop();
    t[id[i]]=min(t[id[i]],{c[i],-p[i]});
    hechas[id[i]]++;
    if(hechas[id[i]]==r[id[i]]){
      for(auto j : base[id[i]]){
        c[j]+=t[id[i]].ff;
        p[j]-=t[id[i]].ss;
        q.push(j);
      }
    }
  }
  //forn(i,cont) cout << t[i].ff << " " << -t[i].ss << endl;
  vi best(b+1);
  forn(i,cont) forn(j,b+1-t[i].ff) {
    int k=b-t[i].ff-j;
    best[k+t[i].ff]=max(best[k]-t[i].ss,best[k+t[i].ff]);
  }
  ii ans={-INF,-INF};
  forn(i,b+1) ans=max(ans,{best[i],-i});
  //forn(i,b+1) cout << i << " " << best[i] << endl;
  cout << ans.ff << "\n" << -ans.ss << "\n";
  return 0; 
}