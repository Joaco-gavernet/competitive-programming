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
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define SZ(x) (x).size()
#define DBG(x) cerr << #x << " = " << endl
#define RAYA cerr << "========================\n"

struct RandomAll {
    mt19937 rng;
    RandomAll(int seed) {rng.seed(seed);}
    int nextInt(int l, int r) {
        uniform_int_distribution<int> dist(l, r);
        return dist(rng);
    }
    vector<int> permutation(int n) {
        vector<int> perm(n);
        iota(all(perm), 1);
        shuffle(all(perm), rng);
        return perm;
    }
    vector<int> randomVector(int n, int l, int r) {
        vector<int> vec(n);
        for (int i = 0; i < n; i++) vec[i] = nextInt(l, r);
        return vec;
    }
};

int main(int argc, char** argv) {
    int seed = argc > 1 ? atoi(argv[1]) : chrono::steady_clock::now().time_since_epoch().count();
    RandomAll rand(seed);
    int n = rand.nextInt(1, 10);
    cout << n << "\n";
    vb usedx(101), usedy(101); 
    forn(i,n) {
        int x1 = rand.nextInt(0, 100);
        int x2 = rand.nextInt(0, 100);
        while (usedx[x1]) x1 = rand.nextInt(0, 100);
        while (usedx[x2]) x2 = rand.nextInt(0, 100);
        if (x1 > x2) swap(x1, x2); 
        
        int y1 = rand.nextInt(0, 100);
        int y2 = rand.nextInt(0, 100);
        while (usedx[y1]) y1 = rand.nextInt(0, 100);
        while (usedx[y2]) y2 = rand.nextInt(0, 100);
        if (y1 > y2) swap(y1, y2); 

        cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
    }

    return 0;
}