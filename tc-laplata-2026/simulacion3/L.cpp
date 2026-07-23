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
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "===============================\n"

typedef long double tipo;
tipo EPS = (tipo)(1e-6);
struct punto {
    tipo x, y; int t=1, id=-1;
    punto const operator - (const punto &p) const { return {x - p.x, y - p.y}; }
    punto const operator + (const punto &p) const { return {x + p.x, y + p.y}; }
    tipo operator * (const punto &p) const { return x * p.x + y * p.y; }
    tipo operator ^ (const punto &p) const { return x * p.y - y * p.x; }
    bool operator == (const punto &p) const { return (abs(x - p.x) < EPS and abs(y-p.y) < EPS); }
    bool operator < (punto p) const { return x != p.x ? x < p.x : y < p.y; }
    tipo arg() { return atan2(y, x); }
    tipo mod() { return sqrtl(x*x + y*y); }
    tipo mod2() { return x * x + y * y; }
};

punto operator * (tipo k, const punto &p) { 
    return {k * p.x, k * p.y}; 
}

punto origin = {0LL, 0LL};
bool AngularSort(const punto &A, const punto &B) {
    bool aorig = (A < origin);
    bool borig = (B < origin); 
    if (aorig != borig) { return aorig > borig; }
    if((A ^ B)<EPS and (A ^ B)>-EPS) {return A.t>B.t;}
    return (A ^ B) > 0;
}



int main() {
    FIN;
    ll n;tipo r; cin >> n >> r;
    vector <punto> p(n);
    forn(i,n){
        ll x, y; cin >> x >> y;
        p[i]={tipo(x),tipo(y)};
    }
    vector <punto> h={{1,0},{0,1},{-1,0},{0,-1}};
    sort(all(h),AngularSort);
    //DBG(h[0].x); DBG(h[0].y); DBG(h[1].x); DBG(h[1].y);
    ll ans=1;
    forn(s,n){
        vector <punto> q;
        ll cont=1;
        forn(i,n) if(i!=s){
            punto aux=p[i]-p[s];
            tipo d=aux.mod();
            if(d>2*r+EPS) continue;
            aux=1.0/d*aux;
            swap(aux.x,aux.y); aux.x=-aux.x;
            aux=sqrtl(r*r-d*d/4)*aux;
            punto z=0.5*(p[i]-p[s])+aux;
            z.t=-1; z.id=i;
            q.pb(z);
            punto z2=0.5*(p[i]-p[s])-aux;
            z2.t=1; z2.id=i;
            q.pb(z2);
        }
        //if(s==0) cout << s << " " << SZ(q) << endl;
        sort(all(q),AngularSort);
        vb visto(n,false);
        int m=SZ(q);
        forn(i,3*m) {
            //if(s==0) cout << q[i%m].x << " " << q[i%m].y << " " << q[i%m].t << endl;
            if(q[i%m].t==-1 and visto[q[i%m].id]) {cont+=q[i%m].t; visto[q[i%m].id]=false;}
            if(q[i%m].t==1 and !visto[q[i%m].id]) {cont+=q[i%m].t; visto[q[i%m].id]=true;}
            ans=max(ans,cont);
        }
    }
    cout << ans << "\n";
    return 0; 
}