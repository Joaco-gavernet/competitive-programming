#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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

const ll INF = 1LL<<60; 

vi min_prime;

vi criba(ll n) {
	vb prime(n+1, true);
	min_prime.resize(n+1, INF);
	vi primos;
	for (ll p = 2; p*p <= n; p++) {
		if (!prime[p]) continue;
		for (ll i = p * p; i <= n; i += p) {
			prime[i] = false;
			min_prime[i] = min(min_prime[i], p);
		}
	}
	forr(i, 2, n+1) {
		if (prime[i]) primos.pb(i), min_prime[i] = i; 
	}
	return primos;
}

ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}

vi primo;

void solve(){
	vi num(2), den(2);
	forn(i,2){
		string s; cin >> s;
		int coma=SZ(s)-1;
		forn(j,SZ(s)){
			if(s[j]!='.') num[i]=num[i]*10+s[j]-'0';
			else coma=j;
		}
		den[i]=pow(10,SZ(s)-1-coma);
		// cout << num[i] << " " << den[i] << endl;
	}
	ll m=den[0]*den[1]/gcd(den[0],den[1]);
	forn(i,2) num[i]=num[i]*m/den[i];
	m=gcd(num[0],num[1]);
	forn(i,2) num[i]/=m;
	if(num[1]==1 and num[0]==1) {cout << "2 2\n"; return;}
	if(num[0]==1 or num[1]==1) {cout << "impossible\n"; return;}
	vb p(2,true);
	forn(i,2) for(int j=0; primo[j]*primo[j]<=num[i]; j++) if(num[i]%primo[j]==0){p[i]=false; break;}
	if(p[0] and p[1]) cout << num[0] << " " << num[1] << "\n";
	else cout << "impossible\n";
	// RAYA;
}

int main() {
	FIN;
	int n; cin >> n;
	primo=criba(4000);
	while(n--) solve();
	return 0;
} 

