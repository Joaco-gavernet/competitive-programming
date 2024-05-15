#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;

#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n);
#define SZ(x) int((x).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()

const ll INF = (1LL<<60);

// Criba lineal, obtiene los primos menores al parametro
vi min_prime; // min_prime[i] contiene el menor primo que divide a i, util para factorizar en log(i)

vi criba(ll n) {
	vb prime(n+1,true);
	min_prime.resize(n+1,INF);
	vi primos;
	for(ll p=2; p*p<=n; p++){
		if(!prime[p]) continue;
		for(ll i=p*p; i<=n; i += p) {
			prime[i] = false;
			min_prime[i] = min(min_prime[i],p);
		}
	}
	forr(i, 2, n+1){
		if(prime[i]) primos.pb(i), min_prime[i] = i;
	}
	return primos; // lista de primos hasta n
}

vi find_divisors(ll n, vi &primos) {
	vector <pair<ll,ll>> factor; 
	for(ll prime : primos) {
		int cont = 0;
		while(n % prime == 0) {
			cont++;
			n /= prime;
		}
		if(cont > 0) factor.pb({prime,cont});
	}

	if(n > 1) factor.pb({n,1});

	vi divisores = {1};
	for(auto [p,exp] : factor) {
		int tam = SZ(divisores);
		forn(i,exp) {
			forn(j,tam) {
				int pos = SZ(divisores)-tam;
				divisores.pb(divisores[pos] * p);
			}
		}
	}

	sort(all(divisores));
	return divisores;
}
vi prims = criba(2e4);

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vi divs = find_divisors(n,prims);

		if (divs[1] != n) cout << n -divs[1] << endl;
		else cout << n -1 << endl;
	}

	return 0;
}
