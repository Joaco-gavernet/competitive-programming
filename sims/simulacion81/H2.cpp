#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "========================\n"

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct MyRandom {
    uniform_int_distribution<int> dist;
    MyRandom(int l, int r) : dist(l, r) {}
    int get() { return dist(rng); }
};
// shuffle(all(v), rng);

int multi(int x, vi &v){
    int l=0, r=0;
    forn(i,SZ(v)){
        if(i<x and v[i]==0) l++;
        if(i>=x and v[i]==1) r++;
    }
    return l*r;
}

bool check(int x, vi &v){
    int l=0, r=0;
    forn(i,SZ(v)){
        if(i<x and v[i]==0) l++;
        if(i>=x and v[i]==1) r++;
    }
    if(l==r) return true;
    else return false;
}

bool solve(){
    int n=10;
    vi v(n);
    MyRandom ran(0,1);
    forn(i,n) v[i]=ran.get();
    int a=0, b=n+1;
    while(b!=a+1){
        int med=(a+b)/2;
        if(v[med-1]==0) b=med;
        else a=med;
    }
    if(b==1){
        int k=multi(1,v);
        if(check(k,v)) return true;
        else{
            forn(i,n) cout << v[i];
            cout << endl;
            return false;
        }
    }
    else if(a==n){
        int k=multi(n,v);
        if(check(n-k,v)) return true;
        else{
            forn(i,n) cout << v[i];
            cout << endl;
            return false;
        }
    }
    else{
        int k1=multi(a,v);
        int k2=multi(a+1,v);
        int k3=multi(a-1,v);
        forn(i,101) forn(j,101) if(i*j==k1 and (i+1)*j==k2 and i*(j+1)==k3){
            if(check(a-i+j,v)) return true;
            else{
                forn(i,n) cout << v[i];
                cout << endl;
                return false;
            }
        }
    }
    return false;
}

int main() {
    FIN;
    while(solve());
    return 0; 
}