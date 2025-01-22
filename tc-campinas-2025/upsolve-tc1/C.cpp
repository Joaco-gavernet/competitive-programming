#include <bits/stdc++.h>
using namespace std; 

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define SZ(x) (__int128)((x).size())
#define esta(x,v) (v).find(x) != (v).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"
#define DBGV(v,n) forn(i,n) cerr << v[i] << ' ' 


__int128 gcd (__int128 a, __int128 b){
	if(b==0){
		return a;
	}else return gcd(b,a%b);
}

string toString(__int128 num) {
	string str; 
	do {
		int digit = num %10; 
		str = to_string(digit) +str; 
		num = (num -digit) /10; 
	} while (num != 0);
	return str; 
}

vector<vector<ll>> g(105);
vector<__int128> llegan(105,0);
vector<__int128> dp(105,0);

void calc(__int128 val,ll n){
	forn(lol,105) llegan[lol]=0;
	ll hijos;
	forr(nod,1,n+1){
		if(nod==1) llegan[nod]+=val;
		hijos=SZ(g[nod]);
		if(hijos>0){
			forn(i,llegan[nod]%hijos) llegan[g[nod][i]]++;
			forn(i,hijos) llegan[g[nod][i]]+=(llegan[nod]/hijos);
		}
	}
	forn(i,SZ(llegan)) cerr << toString(llegan[i]) << ' '; 
	cerr << endl; 
	return;
}

int main() {
	FIN;
	ll n; cin>>n;
	forn(i,n){
		ll x; cin>>x;
		forn(j,x){
			ll aux; cin>>aux;
			g[i+1].pb((__int128)aux);
		}
	}
	dp[0]=1;
	forr(i,1,n+1){
		if(SZ(g[i])==0) {dp[i]=dp[i-1]; continue;}
		calc(dp[i-1],n);
		dp[i]=dp[i-1]*(SZ(g[i])/gcd(SZ(g[i]),llegan[i]));
	}
	cout<< toString(dp[n]) <<"\n";
	return 0;
}
