#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;
using vb = vector<bool>;
using ii = pair<ll,ll>;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "============================\n"
typedef long double ld;
typedef long double tipo;
tipo EPS = (tipo)1e-8;
struct punto {
    tipo x, y; 
    punto const operator - (const punto& p) const { return {x - p.x, y - p.y}; }
    punto const operator + (const punto& p) const { return {x + p.x, y + p.y}; }
    tipo operator * (const punto& p) const { return x * p.x + y * p.y; }
    tipo operator ^ (const punto& p) const { return x * p.y - y * p.x; }
    bool operator == (const punto& p) const {
        return (abs(x - p.x) < EPS and abs(y - p.y) < EPS); 
    }
    bool operator < (const punto p) const { return x != p.x ? x < p.x : y < p.y; }
    tipo arg() { return atan2(y, x); }
    tipo mod() { return sqrtl(x * x + y * y); }
    tipo mod2() { return x * x + y * y; }
};

punto operator * (tipo k, const punto& p) {
    return {k * p.x, k * p.y}; 
}

void convex_hull(vector<punto>& a) {
    if (SZ(a) == 1) return;
    sort(all(a));
    punto p1 = a[0];
    vector<punto> up, down; 
    up.pb(p1), down.pb(p1);
    forr(i,1,SZ(a)) {
        int n = SZ(up), m = SZ(down); 
        while (n > 1 and ((up[n - 1] - up[n - 2]) ^ (a[i] - up[n - 1])) >= -EPS) {
            up.pop_back(); n--;
        }
        up.pb(a[i]); 
        while (m > 1 and ((down[m - 1] - down[m - 2]) ^ (a[i] - down[m - 1])) <= EPS) {
            down.pop_back(); m--;
        }
        down.pb(a[i]); 
    }
    a.clear();
    for (punto u : up) a.pb(u);
    for (int i = SZ(down) - 2; i > 0; i--) a.pb(down[i]); 
}

struct recta {
    punto v, p;
    recta(punto p1, punto p2) { v = (p2 - p1); p = p1; }
    recta() {}
    recta(tipo A, tipo B, tipo C) {
        v = {-B, A};
        A != 0 ? p = {-C / A, 0} : p = {0, - C / B}; 
    }
    bool is_in(punto q) { return fabs((q.x - p.x) * v.y - (q.y - p.y) * v.x) < EPS; }
    punto eval(double x) { return x * v + p; }
};

bool inter_seg(recta& r1, recta& r2, punto& ans) {
    if (r1.p == r2.p or r1.p == r2.p + r2.v) {
        ans = r1.p; return true; 
    }
    if (r1.p + r1.v == r2.p or r1.p + r1.v == r2.p + r2.v) {
        ans = r1.p + r1.v; return true; 
    }
    if (abs(r1.v ^ r2.v) < EPS) return false; 
    tipo alpha = tipo((r2.p - r1.p) ^ r2.v) / tipo(r1.v ^ r2.v); 
    tipo beta = tipo((r1.p - r2.p) ^ r1.v) / tipo(r2.v ^ r1.v); 
    if (alpha < -EPS or beta < -EPS) return false; 
    if (alpha > 1.0 + EPS or beta > 1.0+EPS) return false;
    ans = r1.p + alpha * r1.v; 
    return true; 
}

tipo area(vector <punto> &v){
    tipo ans=0.0; int n=SZ(v);
    forn(i,n) ans+=v[i]^v[(i+1)%n];
    return fabs(ans/2.0);
}

int main() {
    FIN;
    ld ans=125.0/31;
    cout << setprecision(10) << fixed;
    vector <punto> d={{0.5,0.5},{0.5,-0.5},{-0.5,-0.5},{-0.5,0.5}}, p(4);
    forn(i,4) cin >> p[i].x >> p[i].y;
    vi s={3,1,4,6};
    forn(i,4){
        recta r(d[i],d[(i+1)%4]);
        r.v=100*r.v; r.p=r.p-r.v; r.v=2*r.v;
        vector <punto> q;
        forn(j,4){
            recta l(p[j],p[(j+1)%4]);
            punto aux;
            if(inter_seg(r,l,aux)) q.pb(aux);
            if(d[i].x==d[(i+1)%4].x and d[i].x*p[j].x>EPS and fabs(p[j].x)>fabs(d[i].x)) q.pb(p[j]);
            if(d[i].y==d[(i+1)%4].y and d[i].y*p[j].y>EPS and fabs(p[j].y)>fabs(d[i].y)) q.pb(p[j]);
        }
        convex_hull(q);
        ans+=area(q)*s[i]*5/124;
    }
    cout << ans << "\n";
    return 0; 
}