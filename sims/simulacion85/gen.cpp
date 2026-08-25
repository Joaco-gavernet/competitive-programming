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

struct RandomAll {
    mt19937 rng;
    RandomAll(int seed) { rng.seed(seed); }
    int nextInt(int l, int r) {
        uniform_int_distribution<int> dist(l, r); 
        return dist(rng); 
    }
};

int main(int argc, char** argv) {
    FIN;
    int seed = argc > 1 ? atoi(argv[1]) : chrono::steady_clock::now().time_since_epoch().count(); 
    RandomAll rand(seed); 

    int t = 1000000000; 
    cout << t << '\n';
    while (t--) {
        int n = rand.nextInt(1, 10); 
        int m = rand.nextInt(1, 10); 
        vector<char> ops = {'B', 'W', '?'}; 
        cout << n << ' ' << m << '\n'; 
        forn(i,n) {
            forn(j,m) cout << ops[rand.nextInt(0, 2)];
            cout << '\n';
        }
    }

    return 0; 
}