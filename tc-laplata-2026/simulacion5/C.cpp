#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i = a, jet = b; i < jet; i++)
#define SZ(x) int((x).size())
#define ALL(x) x.begin(), x.end()
#define mset(a,v) memset((a), (v), sizeof(a))
#define NCG ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vv;


int main() {
    NCG;
    ll n; cin>>n; 
    ll a[n]; fore(i,0,n)cin>>a[i];
    fore(i,0,n){
        while(a[i]%3==0) a[i]/=3;
        while(a[i]%2==0)a[i]/=2;
    }
    bool bad=0;
    fore(i,1,n) if(a[i]!=a[i-1]) bad=1;
    cout<<(!bad?"Yes\n":"No\n");
    return 0;
}