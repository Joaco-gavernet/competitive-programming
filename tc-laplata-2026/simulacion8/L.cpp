#include <bits/stdc++.h> 
#include <bit>
using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vb = vector<bool>;
using ii = pair<ll,ll>;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cout << #x << " = " << x << endl
#define RAYA cerr << "================================\n"

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T>
T rnd(T l, T r) { return uniform_int_distribution<T>(l, r)(rng); }

using tipo = long double; 
const int ITER = 1e8; 

int main() {
    FIN;

    int n; cin >> n;
    vi l(5,-1), r(5,-1); forn(i,n) cin >> l[i] >> r[i]; 
    ld ans=0;
    cout << setprecision(12) << fixed;
    ///CABBBCABCBABC
    forr(k,1,1e4+1) forn(mask,1<<5) if(__builtin_popcount(mask)>1){
        //DBG(mask);
        ld p=k;
        //DBG(p);
        forn(i,5){
            //DBG(i);
            //DBG(p);
            if((mask&(1<<i))!=0){
                if(k<l[i] or k>r[i]) p=0;
                else p=p/(r[i]-l[i]+1);
            }
            else{
                //DBG(i); DBG(k); DBG(l[i]); DBG(r[i]);
                if(k<=l[i]) p=0;
                else if(k<=r[i]) p=p*(k-l[i])/(r[i]-l[i]+1);
            }
        }
        //DBG(p);
        ans+=p;
        //RAYA;
    }
    forr(k,1,1e4+1) forn(j,5) forr(mask,1,1<<4){
        ld p=k;
        if(r[j]<=k) p=0;
        else if(l[j]<=k) p=p*(r[j]-k)/(r[j]-l[j]+1);
        forn(i,4){
            int t=(j+i+1)%5;
            if((mask&(1<<i))!=0){
                if(k<l[t] or k>r[t]) p=0;
                else p=p/(r[t]-l[t]+1);
            }
            else{
                if(k<=l[t]) p=0;
                if(k<=r[t]) p=p*(k-l[t])/(r[t]-l[t]+1);
            }
        }
        ans+=p;
    }
    cout << ans << "\n";
    return 0;
}