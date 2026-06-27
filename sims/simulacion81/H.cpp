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

void solve(){
    int n; cin >> n;
    int a=0, b=n+1;
    while(b!=a+1){
        int med=(a+b)/2;
        cout << "type " << med << endl;
        string s; cin >> s;
        if(s[0]=='l') b=med;
        else a=med;
    }
    if(b==1){
        cout << "multi 1" << endl;
        int k; cin >> k;
        cout << "answer " << k << endl;
    }
    else if(a==n){
        cout << "multi " << n-1 << endl;
        int k; cin >> k;
        cout << "answer " << n-k << endl;
    }
    else{
        cout << "multi " << a << endl;
        int k1; cin >> k1;
        cout << "multi " << a+1 << endl;
        int k2; cin >> k2;
        cout << "multi " << a-1 << endl;
        int k3; cin >> k3;
        forn(i,101) forn(j,101) if(i*j==k1 and (i+1)*j==k2 and i*(j+1)==k3){cout << "answer " << a-i+j << endl; return;}
    }
}

int main() {
    FIN;
    int t; cin >> t;
    while(t--) solve();
    return 0; 
}