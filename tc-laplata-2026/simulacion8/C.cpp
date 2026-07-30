#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
using vi = vector<ll>;
using vb = vector<bool>;
using ii = pair<ll,ll>;
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


vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    forr(i,1,n) {
        int j = pi[i - 1];
        while (j > 0 and s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    } 
    return pi;
}

int main() {
    FIN;
    vector<string> s(3);
    cin>>s[0]>>s[1]>>s[2];
    ll tot=SZ(s[0])+SZ(s[1])+SZ(s[2]);
    if(SZ(s[1])>SZ(s[2])) swap(s[2],s[1]);
    if(SZ(s[0])>SZ(s[1])) swap(s[0],s[1]);
    if(SZ(s[1])>SZ(s[2])) swap(s[2],s[1]);

    bool zinone=false;
    string zo=s[0]+'$'+s[1];
    vector<int> pfzo=prefix_function(zo);
    ll base=2*SZ(s[0])+1;
    while(base<SZ(zo)){
        if(pfzo[base]==SZ(s[0])){
            zinone=true;
            break;
        }
        base++;
    }

    bool ointwo=false;
    string ot=s[1]+'$'+s[2];
    vector<int> pfot=prefix_function(ot);
    base=2*SZ(s[1])+1;
    while(base<SZ(ot)){
        if(pfot[base]==SZ(s[1])){
            ointwo=true;
            break;
        }
        base++;
    }

    bool zintwo=false;
    string zt=s[0]+'$'+s[2];
    vector<int> pfzt=prefix_function(zt);
    base=2*SZ(s[0])+1;
    while(base<SZ(zt)){
        if(pfzt[base]==SZ(s[0])){
            zintwo=true;
            break;
        }
        base++;
    }

    //todo incluido en mas grande
    if(zinone and ointwo and zintwo){
        cout<<SZ(s[2])<<"\n";
        return 0;
    }

    ll ans=tot;

    //me olvido de la primera
    if(zinone or zintwo){
        string p1=s[2]+'$'+s[1];
        vector<int> pf1=prefix_function(p1);
        ll a1=pf1[SZ(pf1)-1];
        string p2=s[1]+'$'+s[2];
        vector<int> pf2=prefix_function(p2);
        ll a2=pf2[SZ(pf2)-1];
        ans=min(tot-SZ(s[0])-a2,tot-SZ(s[0])-a1);
        cout<<ans<<"\n";
        return 0;
    }

    //me olvido de la del medio
    if(ointwo){
        string p1=s[2]+'$'+s[0];
        vector<int> pf1=prefix_function(p1);
        ll a1=pf1[SZ(pf1)-1];
        string p2=s[0]+'$'+s[2];
        vector<int> pf2=prefix_function(p2);
        ll a2=pf2[SZ(pf2)-1];
        ans=min(tot-SZ(s[1])-a2,tot-SZ(s[1])-a1);
        cout<<ans<<"\n";
        return 0;
    }

    // ll ans=tot;
    forn(i,6){
        string p1=s[1]+'$'+s[0];
        vector<int> pf1=prefix_function(p1);
        ll a1=pf1[SZ(pf1)-1];
        string p2=s[2]+'$'+s[1];
        vector<int> pf2=prefix_function(p2);
        ll a2=pf2[SZ(pf2)-1];
        ans=min(ans,tot-a1-a2);
        //If b included in a
        next_permutation(all(s));
    }
    cout<<ans<<"\n";

    return 0;
}