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
#define RAYA cerr << "=======================\n"

struct torre{
    int p, t, id;
    bool operator < (torre a) const{return p<a.p;}
};

int main() {
    FIN;
    int n[2];
    forn(i,2) cin >> n[i];
    map<int,vector<torre>> x, y;
    vi a[2];
    forn(i,2) a[i].resize(n[i]);
    forn(t,2) forn(i,n[t]){
        int a, b; cin >> a >> b;
        x[a].pb({b,t,i}); y[b].pb({a,t,i});
    }
    for(auto [_,v] : x){
        sort(all(v));
        forn(i,SZ(v)-1) if(v[i].t!=v[i+1].t){
            a[v[i].t][v[i].id]=1;
            a[v[i+1].t][v[i+1].id]=1;
        }
    }
    for(auto [_,v] : y){
        sort(all(v));
        forn(i,SZ(v)-1) if(v[i].t!=v[i+1].t){
            a[v[i].t][v[i].id]=1;
            a[v[i+1].t][v[i+1].id]=1;
        }
    }
    forn(t,2){
        forn(i,n[t]) cout << a[t][i];
        cout << "\n";
    }
    return 0; 
}