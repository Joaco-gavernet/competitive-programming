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


typedef long double ld;
typedef complex<ld> cd; 
void fft(vector<cd> &a) {
    int n = SZ(a), L = 31 - __builtin_clz(n);
    vi rev(n);
    forn(i,n) rev[i] = (rev[i / 2] + ((i&1)<<L)) / 2;
    forn(i,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
    static vector<cd> root(2, 1); 
    for (static int k = 2; k < n; k *= 2) {
        root.resize(n);
        cd z = polar(1.0, acos(-1)/k);
        forr(i, k, 2*k) root[i] = root[i / 2] * ((i&1) ? z : 1);
    }
    for (int k = 1; k < n; k*= 2) {
        for (int i = 0; i < n; i += 2*k) {
            forn(j,k) {
                cd z = root[j+k] * a[i + j + k];
                a[i + j + k] = a[i + j] - z;
                a[i + j] += z; 
            }
        }
    }
}

vi mul(vi& a, vi& b) {
    int sa = SZ(a), sb = SZ(b);
    if (sa == 0 or sb == 0) return {};
    int n = 1<<(32-__builtin_clz(sa + sb - 2));
    vector<cd> f(n), h(n);
    forn(i,n) f[i] = cd(ld(i < sa? a[i]:0), ld(i<sb?b[i]:0));
    fft(f);
    forn(i,n) {
        ll j = (-i) & (n - 1);
        h[i] = (f[j] * f[j] - conj(f[i] * f[i])) * cd(0, -0.25/n); 
    }
    fft(h);
    vi c(sa+sb-1);
    forn(i, sa+sb-1) c[i] = ll(round(h[i].real()));
    return c;
}

int main() {
    FIN;
    int n; cin >> n;
    vi a(n), b(n), c(2*n);
    forn(i,n) cin >> a[i];
    forn(i,n) cin >> b[n-1-i];
    forn(i,n) if(a[i]==0) c[i]=c[i+n]=1;
    vi p=mul(b,c);
    forn(i,n) {
        if(b[i]==0) b[i]=1;
        else b[i]=0;
        c[i]=c[i+n]=a[i];
    }
    ll ans=0;
    vi q=mul(b,c);
    forr(i,n-1,2*n) ans=max(ans,q[i]+p[i]);
    cout << ans << "\n";
    return 0; 
}