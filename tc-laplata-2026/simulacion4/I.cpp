#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
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

const ll CBITS=24;

int main() {
    FIN;
    ll n; cin>>n;
    vector<string> words(n);
    forn(i,n) cin>>words[i];
    forn(i,n){
        sort(all(words[i]));
        words[i].erase(unique(all(words[i])),words[i].end());
        // DBG(words[i]);
    }
    vi cwords1(CBITS);
    vector<vi> cwords2(CBITS,vi(CBITS));
    vector<vector<vi>> cwords3(CBITS,vector<vi>(CBITS,vi(CBITS)));
    forn(i,n){
        ll a,b,c;
        a=words[i][0]-'a'; cwords1[a]++;
        // DBG(a);
        if(SZ(words[i])==1) continue;
        b=words[i][1]-'a';
        if(a>b) swap(a,b);
        cwords1[b]++;
        cwords2[a][b]++; cwords2[b][a]++;
        // DBG(b);
        if(SZ(words[i])==2) continue;
        c=words[i][2]-'a';
        cwords1[c]++;
        if(c<a) swap(a,c);
        if(c<b) swap(c,b);
        cwords2[b][c]++; cwords2[c][b]++;
        cwords2[a][c]++; cwords2[c][a]++;
        cwords3[a][b][c]++; cwords3[a][c][b]++;
        cwords3[b][a][c]++; cwords3[b][c][a]++;
        cwords3[c][a][b]++; cwords3[c][b][a]++;
        // DBG(c);
    }
    ll ans=0;
    vi dp(1<<CBITS,0);
    forn(bitmask,1<<CBITS){
        ll i=-1,j=-1;
        for(ll p1=CBITS-1;p1>=0;p1--){
            if(1<<p1 & bitmask){
                i=p1;
                break;
            }
        }
        for(ll p2=i-1;p2>=0;p2--){
            if(1<<p2 & bitmask){
                j=p2;
                break;
            }
        }
        // DBG(i); 
        // DBG(j);
        if(i==-1) continue;
        if(j==-1){
            dp[bitmask]=cwords1[i];
            ll x=dp[bitmask];
            x*=x;
            // DBG(x); DBG(bitmask);
            // RAYA;
            ans^=x;
            continue;
        }
        dp[bitmask]+=dp[bitmask-(1<<i)];
        dp[bitmask]+=dp[bitmask-(1<<j)];
        dp[bitmask]-=dp[bitmask-(1<<j)-(1<<i)];
        dp[bitmask]-=cwords2[j][i];
        forn(bitextra,j){
            if(1<<bitextra & bitmask){
                dp[bitmask]+=cwords3[bitextra][j][i];
            }
        }
        ll x=dp[bitmask];
        x*=x;
        // DBG(x); DBG(bitmask);
        // RAYA;
        ans^=x;
    }
    cout<<ans<<"\n";

    return 0;
}




// vi dp(1<<CBITS,0);
    // dp[1]=cwords1[0];    //Palabras solo con A
    // forr(bit,1,CBITS){
    //     dp[1<<bit]=cwords1[bit];
    //     forn(prev,1<<bit){
    //         ll act=prev+(1<<bit);
    //         dp[act]=dp[prev]+cwords1[bit];
    //         //Restar los duos
    //         forn(bprev,bit) if((1<<bprev)&prev) dp[act]-=cwords2[bprev][bit];
    //         //Sumar los trios
    //         forn(bprev1,bit) if((1<<bprev1)&prev){
    //             forr(bprev2,bprev1+1,bit) if((1<<bprev2)&prev){
    //                 dp[act]+=cwords3[bprev1][bprev2][bit];
    //             }
    //         }
    //         ans=ans^(dp[act]*dp[act]);
    //     }
    // }