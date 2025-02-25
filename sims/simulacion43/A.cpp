#include <bits/stdc++.h>
using namespace std; 


typedef long long ll; 
typedef vector<ll> vi;
typedef vector<bool> vb; 
typedef pair<ll,ll> ii;
typedef vector<ii> vii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define esta(v,x) (v).find(x) != (v).end()
#define pb push_back
#define SZ(x) int((x).size)
#define all(v) (v).begin(), (v).end() 
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=============================\n"
#define DBGV(v,n) forn(_,n) cerr << v[_] << ' '

struct suma{
  ll tot=0, t=0, c=0;
};

int main() {
  FIN;
  cout<<fixed<<setprecision(7);
  ll n,w; cin>>n>>w;
  vii pos(n,{1,0});
  vi tot(w+1), ans(n), puntos(n);
  vector <suma> pen(w+1), igno(n);
  tot[0]=n;
  RAYA;
  forn(i,w){
    int k; cin >> k;
    vii q(k);
    forn(j,k) {
      cin >> q[j].second;
      q[j].second--;
      q[j].first=puntos[q[j].second];
    }
    sort(all(q)); reverse(all(q));
    for(auto [_,id] : q){
      ans[id]+=pen[puntos[id]].tot-igno[id].tot;
      ans[id]+=pos[id].first*(i-pos[id].second);
      pos[id].first=pos[id].first+pen[puntos[id]].c-igno[id].c;
    }
    int cont=0;
    forn(j,k){
      int id=q[j].second;
      if(j>0 and q[j].first==q[j-1].first) cont++;
      cout << "AASA " << pos[id].first << " " << pos[id].second << " " << id << endl;
      // Aca sumar penalidad
      pen[puntos[id]]={pen[puntos[id]].tot+pen[puntos[id]].c*(i-pen[puntos[id]].t),i,pen[puntos[id]].c};
      igno[id]={igno[id].tot+igno[id].c*(i-igno[id].t),i,igno[id].c};
      cout << id << " " << ans[id] << endl;
      pen[puntos[id]]={pen[puntos[id]].tot+1,i,pen[puntos[id]].c+1};
      tot[puntos[id]]--;
      puntos[id]++;
      tot[puntos[id]]++;
      igno[id]=pen[puntos[id]];
      pos[id]={pos[id].first-tot[puntos[id]]+1+cont,i};
      cout << "AASA " << pos[id].first << " " << pos[id].second << " " << id << endl;
      RAYA;
    }
  }
  forn(i,n){
    ans[i]+=pos[i].first*(w-pos[i].second);
    pen[puntos[i]]={pen[puntos[i]].tot+pen[puntos[i]].c*(w-1-pen[puntos[i]].t),w-1,pen[puntos[i]].c};
    igno[i]={igno[i].tot+igno[i].c*(w-1-igno[i].t),w-1,igno[i].c};
    ans[i]+=pen[puntos[i]].tot-igno[i].tot;
    //cout << ans[i] << " ";
    cout << (long double)ans[i]/(long double)w<<" ";
  }
  cout<<"\n";
  cout << pen[1].tot << " " << pen[1].t << " " << pen[1].c << endl;
  cout << igno[0].tot << " " << igno[0].t << " " << igno[0].c << endl;
  return 0;
} 
