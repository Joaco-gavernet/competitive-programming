#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
using vi = vector<ll>;
using vb = vector<bool>;
using ii = pair<ll,ll>;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second 
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=============================\n"

int main() {
    FIN;
    int n, m;
    cin >> n;
    vi a(n);
    forn(i,n) cin >> a[i];
    cin >> m;
    vi b(m);
    forn(i,m) cin >> b[i];
    sort(all(a)); sort(all(b));
    int i=0, j=0, ans=0;
    while(i<n and j<m){
        if(abs(a[i]-b[j])<=1) {i++; j++; ans++;}
        else if(a[i]<b[j]) i++;
        else j++;
    }
    cout << ans << "\n";
    return 0;
}