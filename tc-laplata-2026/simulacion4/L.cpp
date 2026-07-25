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
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "================================\n"



int main() {
    FIN;

    int n; cin >> n;
    int act = 0, best = 0;
    vi h(1e6+5);
    forn(i,n) {
        char op; cin >> op;
        int id; cin >> id; 
        if (op == '-') {
            if (h[id] == 0) best++;
            else h[id]--, act--;
        } else {
            act++;
            h[id]++;
        }
        best = max(best, act);
    }
    cout << best << '\n'; 

    return 0;
}