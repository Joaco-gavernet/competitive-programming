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
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "========================\n"

void solve(){
    ll k; string s; cin>>k>>s;
    ll n=SZ(s);
    vector<queue<ll>> histo(26);
    forn(i,n) histo[s[i]-'a'].push(i);
    ll contcortes=0;
    ll proxpos=0;
    string ans;
    while(contcortes<k and proxpos<n){
        ll phisto=25;
        while(SZ(histo[phisto])==0 and phisto>=0) phisto--;
        ll car=(histo[phisto]).front(); histo[phisto].pop();
        char c=phisto+'a';
        // DBG(car);
        // DBG(proxpos);
        ans+=c;
        if(car != proxpos){
            contcortes++;
            while(++proxpos<car){
                histo[s[proxpos]-'a'].pop();
            }
        }
        proxpos++;
        
    }
    while(proxpos<n) ans+=s[proxpos++];
    cout<<ans<<"\n";
}

int main() {
    FIN;
    ll t; cin>>t;
    while(t--) solve();
    return 0; 
}
