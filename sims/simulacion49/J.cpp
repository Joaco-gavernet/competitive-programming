#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "================================\n" 

bool is_corner(vi p){
	if(p[0]==0 and p[1]==0) return true;
	if(p[1]==0 and p[2]==0) return true;
	if(p[2]==0 and p[3]==0) return true;
	if(p[3]==0 and p[0]==0) return true;
	return false;
}

void rotate(vi &v){
	vi v2=v;
	forn(i,4) v2[(i-1+4)%4]=v[i];
	v=v2;
	return;
}


int main() {
	FIN;
	ll n; cin>>n;
	vector<vi> v(n,vi(4));
	vector<vi> mp(2*n+1);
	vb visto(2*n+1,false);
	forn(i,n){
		cin>>v[i][0]>>v[i][1]>>v[i][2]>>v[i][3];
		if(v[i][0]>0) mp[v[i][0]].pb(i);
	}
	vector<vi> ans;
	vi inicial(4);
	ll inin=-1;
	forn(i,n) if(is_corner(v[i])){
		inicial=v[i];
		inin=i;
		break;
	}
	if(inin==-1){
		cout<<"SIN ESQUINA\n";
		return 0;
	}
	DBG(inin);
	while(inicial[0]!=0 or inicial[1]!=0) rotate(inicial);
	ll h=1,w=1;
	ans.pb(vi());
	ans[0].pb(inin);
	while(inicial[3]!=0){
		ll id=inicial[3];
		DBG(id);
		if(SZ(mp[id])!=2){cout<<"NO HAY PAR FILA\n";return 0;}
		if(visto[mp[id][0]]){
			inicial=v[mp[id][1]];
			inin=mp[id][1];
		}else{
			inicial=v[mp[id][0]];
			inin=mp[id][0];
		}
		while(inicial[1]!=id) rotate(inicial);
		ans.pb(vi());
		h++;
		ans[h-1].pb(inin);
	}
	if(n%h!=0){cout<<"NO HAY RECTANGULO\n";return 0;}
	w=n/h;
	ll cont=h;
	//fila a fila
	forn(i,h){
		forn(j,w){
			inin=ans[j][0];
			inicial=v[inin];
			ll id=inicial[2];
			if(SZ(mp[id])!=2){cout<<"NO HAY PAR\n";return 0;}
			if(visto[mp[id][0]]){
				inicial=v[mp[id][1]];
				inin=mp[id][1];
			}else{
				inicial=v[mp[id][0]];
				inin=mp[id][0];
			}
			while(inicial[0]!=id) rotate(inicial);
			if(i>0 and inicial[1]!=v[ans[i-1][j]][3]){cout<<"INCONGRUENCIA\n";return 0;}
			ans[i].pb(inin);
		}
	}
	if(cont<n){cout<<"impossible\n";return 0;}
	forn(i,h) if(v[ans[h][w-1]][2]!=0){cout<<"impossible\n";return 0;}
	forn(i,w) if(v[ans[h-1][w]][3]!=0){cout<<"impossible\n";return 0;}
	cout<<h<<" "<<w<<"\n";
	forn(i,h){forn(j,w) cout<<ans[i][j]+1<<" "; cout<<"\n";}
	return 0;
} 

