#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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
#define RAYA cerr << "========================\n"


typedef ll tipo;
struct punto {
    tipo x, y; 
    punto const operator - (const punto& p) const { return {x - p.x, y - p.y}; }
    punto const operator + (const punto& p) const { return {x + p.x, y + p.y}; }
    tipo operator * (const punto& p) const { return x * p.x + y * p.y; }
    tipo operator ^ (const punto& p) const { return x * p.y - y * p.x; }
    bool operator == (const punto& p) const { return x == p.x and y == p.y; }
    bool operator < (const punto& p) const { return x != p.x ? x < p.x : y < p.y; }
    tipo arg() { return atan2(y, x); }
    tipo mod() { return sqrtl(x * x + y * y); }
    tipo mod2() { return x * x + y * y; }
};

punto operator * (tipo k, const punto& p) { return {k * p.x, k * p.y}; }

typedef long double stipo;
const stipo EPS = 1e-10; 
struct recta {
    punto v, p; 
    recta(punto p1, punto p2) { v = (p2 - p1); p = p1; }
    recta() {}
    recta(tipo A, tipo B, tipo C) {
        v = {-B, A}; A != 0 ? p = {-C / A, 0} : p = {0, -C / B}; 
    }
    bool is_in(punto q) { return fabs((q.x - p.x) * v.y - (q.y - p.y) * v.x) == 0; }
    punto eval(double x) { return x * v + p; }
};

bool inter_seg(recta& r1, recta& r2) {
    if (r1.p == r2.p or r1.p == r2.p + r2.v) return true; 
    if (r1.p + r1.v == r2.p or r1.p + r1.v == r2.p + r2.v) return true; 
    if (abs(r1.v ^ r2.v) < EPS) return false;
    stipo alpha = stipo((r2.p - r1.p) ^ r2.v) / stipo(r1.v ^ r2.v); 
    stipo beta = stipo((r1.p - r2.p) ^ r1.v) / stipo(r2.v ^ r1.v); 
    if (alpha < -EPS or beta < -EPS) return false; 
    if (alpha > 1.0 + EPS or beta > 1.0 + EPS) return false;
    return true; 
}

bool inter_seg2(recta& r1, recta& r2) {
    if (r1.p == r2.p or r1.p == r2.p + r2.v) return false; 
    if (r1.p + r1.v == r2.p or r1.p + r1.v == r2.p + r2.v) return false; 
    if (abs(r1.v ^ r2.v) < EPS) return false;
    stipo alpha = stipo((r2.p - r1.p) ^ r2.v) / stipo(r1.v ^ r2.v); 
    stipo beta = stipo((r1.p - r2.p) ^ r1.v) / stipo(r2.v ^ r1.v); 
    if (alpha < -EPS or beta < -EPS) return false; 
    if (alpha > 1.0 + EPS or beta > 1.0 + EPS) return true;
    return true; 
}

void solve() {
    vector <punto> p(6);
    vector <recta> r(3);
    forn(i,6) cin >> p[i].x >> p[i].y;
    for(int i=0; i<5; i+=2) r[i/2]=recta(p[i],p[i+1]);
    if(p[0]==p[1]){cout << "0\n"; return;}
    forr(i,2,6) if(r[0].is_in(p[i]) and ((p[0]<p[i] and p[i]<p[1]) or (p[1]<p[i] and p[i]<p[0]))){cout << "1\n"; return;}
    vb c(2,false);
    bool uno=false;
    for(int i=2; i<5; i+=2){
        if(!(p[i]==p[i+1])) c[i/2-1]=inter_seg(r[0],r[1]);
        else uno=true;
    }
    if(!c[0] and !c[1]) {cout << "0\n"; return;}
    if(!c[0] or !c[1]) {cout << "1\n"; return;}
    if(uno and (c[0] or c[1])) {cout << "1\n"; return;}
    if(!inter_seg(r[1],r[2])){cout << "1\n"; return;}
    forr(i,2,6){
        recta s=recta(p[0],p[i]);
        bool anda=true;
        forr(j,1,3) if(inter_seg2(s,r[j])) anda=false;
        s.p=p[1];
        forr(j,1,3) if(inter_seg2(s,r[j])) anda=false;
        if(anda) {cout << "1\n"; return;}
    }
    cout << "2\n";
}

int main() {
    FIN;
    int t; cin >> t;
    while (t--) solve(); 
    return 0; 
}