#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"


typedef long double tipo;
double EPS = (double)(1e-3);
struct punto {
    tipo x, y; 
    punto const operator -(const punto& p) const { return {x - p.x, y - p.y}; }
    punto const operator +(const punto& p) const { return {x + p.x, y + p.y}; }
    tipo operator * (const punto& p) const { return x*p.x + y*p.y; }
    tipo operator ^ (const punto& p) const { return x*p.y - y*p.x; }
    bool operator == (const punto& p) const {
        return (abs(x - p.x) < EPS and abs(y - p.y) < EPS);
    }
    bool operator < (punto p) const { return x != p.x ? x < p.x : y < p.y; }
    tipo arg() { return atan2(y, x); }
    tipo mod() { return sqrtl(x*x + y*y); }
    tipo mod2() { return x*x + y*y; }
};
punto operator * (tipo k, const punto& p) { return {k * p.x, k * p.y}; }

struct recta {
    punto v, p;
    recta(punto p1, punto p2) {
        v = (p2 - p1); p = p1; 
    }
    recta() {}
};

tipo dist_point_line(punto& p, recta& r) {
    punto p1 = r.p, p2 = r.p + r.v; 
    return fabs((p1 - p) ^ (p2 - p)) / r.v.mod();
}

bool solve(int ids) {
    int n; cin >> n;
    if (n == 0) return false; 

    vector<punto> p(n); 
    forn(i,n) {
        int x, y; cin >> x >> y;
        p[i] = {x, y}; 
    }
    tipo ans=10000;
    forn(i,n) forn(j,n) if(i!=j){
        recta r(p[i],p[j]);
        tipo u=0, d=0;
        forn(k,n){
            if(((p[k]-p[i])^(p[j]-p[i]))>EPS) u+=max(u,dist_point_line(p[k],r));
            if(((p[k]-p[i])^(p[j]-p[i]))<-EPS) d=max(d,dist_point_line(p[k],r));
        }
        ans=min(ans,u+d);
    }
    cout << "Case " << ids << ": " << setprecision(2) << fixed << ans << "\n"; 
    return true; 
}

int main() {
    FIN;
    bool ans = true; 
    int i = 1; 
    while (ans) ans = solve(i++);
    return 0;
}