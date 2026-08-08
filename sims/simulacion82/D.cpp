#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=======================\n"
const ll MAXN=5005;
vector <vi> g(MAXN);

void bfs(ll s, vi &d){
    d[s]=0;
    queue <ll> q; q.push(s);
    while(SZ(q)>0){
        ll v=q.front(); q.pop();
        for(auto u : g[v]) if(d[u]==-1){
            d[u]=d[v]+1;  q.push(u);
        }
    }
}

ld f(ll a, ll k) {return 1.0/(2+k/a)*(k%a)+1.0/(1+k/a)*(a-k%a);}

ld cal(ll a, ll b, ll k){
  if(a==0 and b==0) return 0;
  if(a==0) return 2*f(b,k);
  if(b==0) return f(a,k);
  ll l=-1, r=k/b+1;
  ld best=a+2*b;
  while(r-l>1){
    ll m1=(r+l*2)/3, m2=(r*2+l)/3;
    ld s1=2.0/(1+m1)*b+f(a,k-b*m1), s2=2.0/(1+m2)*b+f(a,k-b*m2);
    best=min(best,s1); best=min(best,s2);
    if(r-l==2) break;
    if(s1>s2) l=m1;
    else r=m2;
  }
  l=-1; r=k/a+1;
  while(r-l>1){
    ll m1=(r+l*2)/3, m2=(r*2+l)/3;
    ld s1=1.0/(1+m1)*a+2*f(b,k-a*m1), s2=1.0/(1+m2)*a+2*f(b,k-a*m2);
    best=min(best,s1); best=min(best,s2);
    if(r-l==2) break;
    if(s1>s2) l=m1;
    else r=m2;
  }
  return best;
}

int main() {
    FIN;
    ll n, m, k; cin >> n >> m >> k;
    forn(i,m){
        int a, b; cin >> a >> b; a--; b--;
        g[a].pb(b); g[b].pb(a);
    }
    ll s[2], e[2];
    forn(i,2) {cin >> s[i] >> e[i]; s[i]--; e[i]--;}
    vector <vi> vs(2,vi(n,-1)), ve(2,vi(n,-1));
    forn(i,2){bfs(s[i],vs[i]); bfs(e[i], ve[i]);}
    vector <ii> pares={{vs[0][e[0]]+vs[1][e[1]],0}};
    forn(u,n){
        bool anda=true;
        forn(i,2) if(vs[i][u]==-1) anda=false;
        if(!anda) continue;
        vi d(n,-1); bfs(u,d);
        forn(v,n) if(d[v]!=-1){
            anda=true;
            forn(i,2) if(ve[i][v]==-1) anda=false;
            if(!anda) continue;
            ll a=0;
            forn(i,2) a+=vs[i][u]+ve[i][v];
            pares.pb({a,d[v]});
        }
    }
    sort(all(pares));
    ld ans=cal(pares[0].ff,pares[0].ss,k);
    ll mini=pares[0].ss;
    forr(i,1,SZ(pares)) if(pares[i].ff>pares[i-1].ff and pares[i].ss<mini){
        ans=min(ans,cal(pares[i].ff,pares[i].ss,k));
        mini=min(pares[i].ss,mini);
    }
    cout << setprecision(12) << fixed << ans << "\n";
    return 0; 
}