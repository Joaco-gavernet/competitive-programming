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
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    vi v(n);
    forn(i,n) if(s[n-1-i]=='1'){
        v[n-1-i]=1;
        if(i>0) v[n-1-i]+=v[n-i];
    }
    int j=0;
    forn(i,m){
        if(t[i]=='0'){
            while(j<n and s[j]!='0') j++;
        }
        else{
            int r=i;
            while(r<m and t[r]=='1') r++;
            if(r!=m){
                while(j<n and v[j]<r-i) j++;
            }
            else{
                while(j<n and (v[j]<r-i or j+v[j]!=n)) j++;
            }
            if(i==0 and j!=0) {cout << "no\n"; return;}
            i=r-1;
        }
        if(j==n) {cout << "no\n"; return;}
        j++;
    }
    cout << "yes\n";
}

int main() {
    FIN;
    int t; cin >> t;
    while(t--) solve();
    return 0; 
}