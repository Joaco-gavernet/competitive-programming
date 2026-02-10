#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 
typedef pair<ll,ll> ii; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define ff first
#define ss second
#define SZ(x) int((x).size()) 
#define all(v) begin(v),end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define DBGV(v) forn(_,SZ(v)) cerr<<v[_]<<" "
#define RAYA cerr << "========================\n" 

const ll BITMAX=21;
const ll MAXN=1<<BITMAX;

ll indice[6][6]={
	{1,2,3,4,5,6},
	{0,7,8,9,10,11},
	{0,0,12,13,14,15},
	{0,0,0,16,17,18},
	{0,0,0,0,19,20},
	{0,0,0,0,0,21},
};

ii fichas[21]={
	{1,1},{1,2},{1,3},{1,4},{1,5},{1,6},
	{2,2},{2,3},{2,4},{2,5},{2,6},
	{3,3},{3,4},{3,5},{3,6},
	{4,4},{4,5},{4,6},
	{5,5},{5,6},
	{6,6}
};

ll dfs(vector<vi> &g,ll nod, vb &visto){
	visto[nod]=true;
	ll ans=1;
	for(auto u:g[nod]){
		// DBG(u);
		if(!visto[u]) ans+=dfs(g,u,visto);
	}
	return ans;
}

bool solve(ll i){
	vector<vi> g(6);
	// DBG(i);
	forn(bit,BITMAX) if((1<<bit) &i){
		// DBG(bit);
		ii f=fichas[bit];
		ll a=f.ff; ll b=f.ss; a--; b--;
		g[a].pb(b); g[b].pb(a);
	}
	ll contimp=0;
	ll contnocero=0;
	forn(j,6){
		if(SZ(g[j])) contnocero++;
		if(SZ(g[j])%2) contimp++;
	}
	// if(i==130){DBG(contimp); DBG(contnocero);}
	if(contimp!=0 and contimp!=2) return false;
	vb visto(6,false);
	ll in=0; while(SZ(g[in])==0) in++;
	ll comp=dfs(g,in,visto); 
	// if(i==130) DBG(comp);
	if(comp<contnocero) return false;
	else{
		return true;
	}
}

int main() {
	FIN;
	vi soluciones;
	ll cont=0;
	vi posible(MAXN,-1);
	// forr(i,130,131) if(solve(i)) dp[i]++;
	forr(i,1,MAXN){
		// 1 7 12 16 19 21
		// DBG(i);
		ll nro=i;
		ll dupl=0;
		vb presentes(6,false);
		if(i & 1<<0){nro-=(1<<0); dupl++;}
		if(i & 1<<6){nro-=(1<<6); dupl++;}
		if(i & 1<<11){nro-=(1<<11); dupl++;}
		if(i & 1<<15){nro-=(1<<15); dupl++;}
		if(i & 1<<18){nro-=(1<<18); dupl++;}
		if(i & 1<<20){nro-=(1<<20); dupl++;}
		// DBG(nro);
		if(nro==0){
			if(dupl==1){
				posible[i]=1;
				soluciones.pb(i);
			}
			else posible[i]=0;
			continue;
		}
		if(posible[nro]==-1){
			if(solve(nro)){
				posible[nro]=1;
				soluciones.pb(nro);
			}
		}else if(posible[nro]==1){
			posible[i]=1;
			soluciones.pb(i);
		}else posible[i]=0;
	}
	ll t; cin>>t;
	while(t--){
		ll x; cin>>x;
		ll nro=0;
		forn(i,x){
			ll a,b; cin>>a>>b; a--; b--;
			ll pos=indice[a][b]-1;
			nro+=(1<<pos);
		}
		ll ans=0;
		for(auto u:soluciones) if((u & nro) == u){DBG(u); ans++;}
		cout<<ans<<"\n";
	}

	return 0; 
} 
