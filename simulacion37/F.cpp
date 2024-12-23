#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define pb push_back
#define esta(x,v) (v).find(x) != (v).end()
#define all(v) (v).begin(),(v).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "================================\n"
#define DBGV(v,n) forn(i,n) cerr << v[i] << ' '
#define fs first
#define ss second

vi caps; 

struct DSU {
  vi link, sz, maxid, chap, cap; 
  DSU(int tam) {
    link.resize(tam +5), sz.resize(tam +5), maxid.resize(tam +5), chap.resize(tam +5), cap.resize(tam +5);
    forn(i,tam +5) link[i] = i, sz[i] = 1, maxid[i]=i, chap[i]=0, cap[i]=caps[i]; 
  }
  ll find(ll x) {
    return link[x] = (link[x] == x ? x : find(link[x])); 
  }
  
  void join(ll a, ll b) {
    a = find(a), b = find(b); 
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a,b); 
    sz[a] += sz[b]; 
    link[b] = a;
    maxid[a]=max(maxid[a],maxid[b]);
    //~ maxid[b]=maxid[a];
    chap[a]+=chap[b];
    cap[a]+=cap[b];
  }
}; 

int main() {
  FIN;
  
  int n, q; cin >> n >> q; 
  caps.resize(n+5);
  forn(i,n) cin >> caps[i];
  forr(i,n,+5) caps[i]=1e9+7;
  
  vi f(n);
  ll pos=n-1;
  f[pos]=1e9+7;
  pos--;
  while(pos>=0){
    ll next=pos+1;
    while(next<1e9+7 and caps[next]<caps[pos]) next=f[next];
    f[pos]=next;
    pos--;
  }
  
  //~ for(auto u:f) DBG(u);
  
  DSU d(n);
  
  forn(i,q) {
    char c; cin>>c;
    if(c=='+'){
      int l,x; cin>>l>>x;
      l--;
      ll aux=d.find(l);
      d.chap[aux]+=x;
      while(d.chap[aux]>=d.cap[aux] and f[d.maxid[aux]]<1e9+7){
	//~ cout << aux << " H " << f[d.maxid[aux]] << endl;
	 d.join(aux,d.find(f[d.maxid[aux]]));
	 aux=d.find(aux);
      }
    }else{
      int l; cin>>l;
      l--;
      ll aux=d.find(l);
      if(d.maxid[aux]!=l) cout<<caps[l]<<"\n";
      else cout<<min(caps[l]-(d.cap[aux]-d.chap[aux]),caps[l])<<"\n";
    }
  }
  
  return 0;
}



