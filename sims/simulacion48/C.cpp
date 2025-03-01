#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb;
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define esta(x,c) c.find(x)!=c.end()
#define pb push_back
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=============================\n"
#define DBGV(v,n) cerr << #v << " = "; forn(_,n) cerr << v[_] << ' '; cerr << endl

vector<int> z_function(string s){
	int n = (int) s.size();
	vector<int> z(n);
	for(int i=1,l=0,r=0; i<n;++i){
		if(i<=r){
			z[i]=min(r-i+1,z[i-l]);
		}
		while(i+z[i]<n && s[z[i]] == s[i+z[i]]) z[i]++;
		if(i+z[i]-1>r){
			l=i; r=i+z[i]-1;
		}
	}
	return z;
}

bool is_variable(string &s){
	if(SZ(s)==1 and ((s[0]>='a' and s[0]<='z')or(s[0]>='A' and s[0]<='Z'))) return true;
	else return false;
}


int main() {
	FIN; 
	ll n; cin>>n;
	vector<string> v(n);
	ll totlen=0;
	forn(i,n){cin>>v[i]; totlen+=SZ(v[i])+1;}
	string total,totalz;
	vb variable(totlen);
	set<int> valid;
	forn(i,n){
		variable[SZ(total)]=is_variable(v[i]);
		// if(SZ(v[i])==1 and ((v[i][0]>='a' and v[i][0]<='z')or(v[i][0]>='A' and v[i][0]<='Z'))) variable[SZ(total)]=true;
		valid.insert(SZ(total));
		if(!is_variable(v[i])) totalz+=v[i];
		else totalz+='$';
		total+=v[i];
		total+=' ';
		totalz+=' ';
	}
	// DBG(total);
	vector<vi> matriz(totlen,vi(totlen));
	forn(i,totlen){
		ll hash=0,p=89,mod=998244353,cont=1,curp=1;
		map<char,ll> mapa;
		forr(j,i,totlen){
			ll xi=0;
			if(variable[j]){
				if(esta(total[j],mapa)){
					xi=mapa[total[j]];
				}else{
					xi=cont;
					mapa[total[j]]=cont;
					cont++;
				}
			}
			hash+=(xi*curp);
			hash%=mod;
			curp*=p;
			curp%=mod;
			matriz[i][j]=hash;
		}
	}
	ll q; cin>>q;
	// RAYA;
	while(q--){
		ll k; cin>>k;
		vector<string> caso(k);
		string totcaso,totcasoz;
		ll totlencaso=0;
		forn(i,k){
			cin>>caso[i];
			totlencaso+=SZ(caso[i])+1;
		}
		vb varcaso(totlencaso);
		forn(i,k){
			varcaso[SZ(totcasoz)]=is_variable(caso[i]);
			if(!is_variable(caso[i])) totcasoz+=caso[i];
			else totcasoz+='$';
			totcaso+=caso[i];
			totcasoz+=' ';
			totcaso+=' ';
		}
		string nueva=totcasoz+'#'+totalz;
		vector<int> zf=z_function(nueva);
		// DBG(nueva);
		// DBGV(zf,SZ(zf));
		ll hash=0,p=89,curp=1,mod=998244353,cont=1;
		map<char,ll> mapa;
		forn(i,totlencaso){
			ll xi=0;
			if(varcaso[i]){
				if(esta(totcaso[i],mapa)){
					xi=mapa[totcaso[i]];
				}else{
					xi=cont; mapa[totcaso[i]]=cont++;
				}
			}
			hash+=(xi*curp);
			hash%=mod;
			curp*=p;
			curp%=mod;
		}
		// DBG(totcasoz);
		// DBG(SZ(totcasoz));
		bool ans=false;
		forn(i,SZ(zf)){
			if(zf[i]==SZ(totcasoz)){
				// forn(j,totlen) cerr<<matriz[i-zf[i]-1][j]<<" ";
				// cerr<<endl;
				ll hash2=matriz[i-zf[i]-1][(i-zf[i]-1)+zf[i]-1];
				// DBG(hash); DBG(hash2);
				if(hash==hash2) ans=true;
				// cout<<total.substr(i-zf[i]-1)<<endl;
			}
		}
		if(ans) cout<<"yes\n";
		else cout<<"no\n";
		// DBG(hash); DBG(total);
		// DBG(totcaso);
	}
	return 0; 
} 
