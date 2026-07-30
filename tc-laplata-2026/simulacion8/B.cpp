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
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "================================\n"


int main() {
    FIN;
    ll n, s; cin >> n >> s; s--;
    ll sx=0, sy=0;
    ll Sx=0, Sy=0;
    vi x(n), y(n);
    forn(i,n){
        cin >> x[i] >> y[i];
        sx+=x[i]; sy+=y[i];
        if(i==s){sx-=x[s]*2; sy-=y[s]*2;}
        cin >> x[i] >> y[i];
        Sx+=x[i]; Sy+=y[i];
    }
    forn(i,n) if(Sx-2*x[i]==sx and Sy-2*y[i]==sy) cout << i+1 << "\n";
    return 0;
}