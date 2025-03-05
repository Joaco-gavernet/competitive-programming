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

typedef long double tipo;

struct punto {
	tipo x, y;
	punto const operator -(const punto &p) const { return {x -p.x, y -p.y}; }
	punto const operator +(const punto &p) const { return {x +p.x, y +p.y}; }
	tipo mod() { return sqrtl(x*x + y*y); }
	tipo mod2() { return x*x + y*y; }
};

punto operator*(tipo k, const punto &p) { return {k*p.x, k*p.y}; }
punto operator*(const punto &p, tipo k) { return {k*p.x, k*p.y}; }

int main() {
	FIN;
	cout << fixed << setprecision(10);
	vector <punto> p(2);
	forn(i,2) cin >> p[i].x >> p[i].y;
	punto c; tipo r;
	forn(i,2) cin >> c.x >> c.y >> r;
	tipo ans=0;
	vector <vector <punto>> q(2,vector<punto>(2));
	forn(i,2){
		p[i]=p[i]-c;
		// DBG(r*r/p[i].mod());
		punto a=p[i]*(r*r/p[i].mod2());
		// DBG(a.x); DBG(a.y); DBG(r); DBG(p[i].x); DBG(p[i].y);
		tipo h=sqrtl(r*r-a.mod2()), t=sqrtl(h*h+(p[i].mod()-a.mod())*(p[i].mod()-a.mod()));
		// DBG(h); DBG(t);
		ans+=t;
		swap(p[i].x,p[i].y); p[i].x=-p[i].x;
		forn(j,2){
			q[i][j]=a+p[i]*(-1+2*j)*(h/p[i].mod());
		}
	}
	// DBG(ans);
	tipo best=1e9;
	forn(i,2) forn(j,2){
		punto aux=q[0][i]-q[1][j];
		best=min(best,aux.mod());
	}
	// DBG(best);

	tipo s=best/2/r;
	// DBG(s);

	ans+=2*r*asinl(s);
	cout << ans << "\n";
	return 0;
} 

