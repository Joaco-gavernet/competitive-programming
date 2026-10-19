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

tipo dist_point_line(punto &p, recta &r){
    punto p1=r.p,p2=r.p+r.v;
    return fabs(((p1-p)^(p2-p))/r.v.mod());
    // ((a-p)^(b-p))*((a-p)^(b-p))<c*c*r.v.mod2()
    // a-p=(x1-x,y1-y)
    // b-p=(x2-x,y2-y)
    // (a-p)^(b-p) = (x1-x)*(y2-y)-(y1-y)*(x2-x)
    // aux=(x1-x)*(y2-y)-(y1-y)*(x2-x)
    // r.v.mod2=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)
}

int main() {
    FIN;
    ll n; cin >> n;
    vector <vector<ll>> c(501,vector<ll>(501));
    vector <vb> g(501,vb(501,false));
    forn(i,n){
        ll x, y; cin >> x >> y;
        g[x][y]=true;
        string s;
        cin >> s;
        c[x][y]=(s[2]-'0');
    }
    ll q; cin >> q;
    forn(k,q){
        ll ans=0, x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
        if(x1>x2){swap(x1,x2); swap(y1,y2);}
        punto a={x1,y1}, b={x2,y2};
        recta r(a,b);
        ll rvm=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2); rvm*=100;
        if(x1==x2){
            forr(y,min(y1,y2),max(y1,y2)+1) if(g[x1][y]) ans++;
            cout << ans << "\n"; continue;
        }
        if(y1==y2){
            forr(x,x1,x2+1) if(g[x][y1]) ans++;
            cout << ans << "\n"; continue;
        }
        //RAYA;
        //sumar (x1,y1)
        //cout << x1 << "  " << y1 << endl;
        if(g[x1][y1]) ans++;
        ll y=y1, d=1, s=1, e=0, aux;
        if(y1>y2) {d=-1; s=-1; e=0;}
        forr(x,x1+1,x2+1){
            punto z=r.eval((ld (x-x1))/(x2-x1));
            ll _y=floor(z.y);
            //sumar (x,y) (x,y+1)
            //cout << x << "  " << y << endl;
            if(g[x][y]){
                aux=(x1-x)*(y2-y)-(y1-y)*(x2-x);
                if(aux*aux*10000<c[x][y]*c[x][y]*rvm) ans++;
            }
            //if(d==-1) cout << x << " " << y+1 << endl;
            if(d==-1 and g[x][y+1]){
                aux=(x1-x)*(y2-y-1)-(y1-y-1)*(x2-x);
                if(aux*aux*10000<c[x][y+1]*c[x][y+1]*rvm) ans++;
            }
            for(ll i=y+s; i!=_y+e+d; i+=d){
                //sumar (x-1,i) (x,i)
                //cout << x-1 << "  " << i << endl;
                //cout << x << "  " << i << endl;
                if(g[x][i]){
                    aux=(x1-x)*(y2-i)-(y1-i)*(x2-x);
                    if(aux*aux*10000<c[x][i]*c[x][i]*rvm) ans++;
                }
                if(g[x-1][i]){
                    aux=(x1-x+1)*(y2-i)-(y1-i)*(x2-x+1);
                    if(aux*aux*10000<c[x-1][i]*c[x-1][i]*rvm) ans++;
                }
            }
            //sumar (x-1,_y+1)
            //if(d==1) cout << x-1 << " " << _y+1 << endl;
            if(d==1 and g[x-1][_y+1]){
                aux=(x1-x+1)*(y2-_y-1)-(y1-_y-1)*(x2-x+1);
                if(aux*aux*10000<c[x-1][_y+1]*c[x-1][_y+1]*rvm) ans++;
            }
            y=_y;
        }
        cout << ans << "\n";
    }
    return 0; 
}