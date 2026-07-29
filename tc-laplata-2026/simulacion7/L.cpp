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
    int n; cin >> n;
    vi p(n), b(n), a, id(n,-1);
    vector <set<ll>> v(n);
    forn(i,n){
        cin >> p[i] >> b[i]; p[i]--;
        v[p[i]].insert(i);
    }
    int cont=0;
    for(int i=n-1; i>=0; i--) if(id[p[i]]==-1){
        id[p[i]]=cont; cont++;
        a.pb(p[i]);
    }
    int q; cin >> q;
    set <ll> s;
    forn(i,cont) s.insert(i);
    while(q--){
        int k; cin >> k;
        vi g(k);
        forn(i,k){
            cin >> g[i]; g[i]--;
            s.erase(id[g[i]]);
        }
        if(s.lower_bound(0)==s.end()) cout << "0 0\n";
        else{
            int f=*s.lower_bound(0);
            cout << a[f]+1 << " ";
            if(s.lower_bound(f+1)==s.end()) cout << b[*v[a[f]].begin()] << "\n";
            else cout << b[*v[a[f]].lower_bound(*v[a[*s.lower_bound(f+1)]].rbegin())] << "\n";
        }
        forn(i,k) s.insert(id[g[i]]);
    }
    return 0;
}