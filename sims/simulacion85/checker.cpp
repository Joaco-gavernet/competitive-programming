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

bool valid(vector<string>& mat) {
    const int n = SZ(mat);
    const int m = SZ(mat[0]); 
    forn(i,n-1) {
        forn(j,m-1) {
            if (mat[i][j] == mat[i+1][j+1] and mat[i+1][j] == mat[i][j+1] and mat[i][j] != mat[i+1][j]) return false; 
        }
    }
    return true; 
}

void check(int id) {
    string s; cin >> s;
    vector<string> mat; 
    bool state = (s == "YES"); 
    while (cin >> s) mat.pb(s); 
    if (state) {
        if (valid(mat) == false) {
            DBG(id); 
            assert(false); 
        }
    } 
}

int main() {
    FIN;
    int t; cin >> t;
    forn(i,t) check(i); 
    return 0; 
}