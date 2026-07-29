#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
 #include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
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


typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

using i128 = __int128_t; 
string to_string(i128 num) {
    string str;
    bool neg=false; if(num<0){
        neg=true;
        num*=-1;
    }
    do {
        int digit = num % 10; 
        str = to_string(digit) + str;
        num = (num - digit) / 10;
    } while (num != 0); 
    if(neg) str='-'+str;
    return str;
}

i128 solve(vi &v){
    indexed_set s1, s2;
    i128 ans=0;
    ll n=SZ(v);
    forn(i,n) {
        s1.insert({v[i],i}); s2.insert({-v[i],i});
        ll u=ll(s1.order_of_key(*s1.lower_bound({v[i]-1,-1})));
        ll w=ll(s2.order_of_key(*s2.lower_bound({-v[i]-1,-1})));
        i128 aux=v[i]*(u+w);
        ans+=aux;
    }
    return ans;
}

int main() {
    FIN;
    ll n; cin >> n;
    vi v(n);
    forn(i,n) cin >> v[i];
    i128 ans=solve(v);
    reverse(all(v));
    ans-=solve(v);
    cout << to_string(ans) << "\n";
    return 0;
}