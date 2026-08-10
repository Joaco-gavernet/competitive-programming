#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
typedef pair<ll,char> piramide;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"

const ll INF = 1e9+7;

vector<pair<ii,piramide>> dp(1e6+5,{(ii){INF,-1},(piramide){-1,'$'}});
vector<pair<ll,piramide>> pirhigh={{5,{2,'H'}}};
// vector<piramide> sumpirhigh={5};
vector<pair<ll,piramide>> pirlow={{10,{3,'L'}},{20,{4,'L'}}};
vector<pair<ll,piramide>> pirs;
// vector<piramide> sumpirlow={10,20};

bool solve(int ids) {
    ll n; cin>>n;
    if(n==0) return false;
    cout << "Case " << ids << ": "; 
    if(dp[n].ff.ff==INF) cout<<"impossible";
    else while(n>0){
        // DBG(dp[n].ff.ff);
        cout<<dp[n].ss.ff<<dp[n].ss.ss<<" ";
        n-=dp[n].ff.ss;
    }
    
    cout<<"\n";
    return true; 
}

int main() {
    FIN;
    //Calculate dp
    ll totpirs=3;
    ll nextbase=3;
    ll proxsum=nextbase*nextbase+(pirhigh.back().ff);
    while(proxsum<=1e6){
        pirhigh.pb({proxsum,{nextbase,'H'}});
        nextbase++;
        totpirs++;
        proxsum=nextbase*nextbase+(pirhigh.back().ff);
    }
    nextbase=5;
    proxsum=nextbase*nextbase+pirlow[SZ(pirlow)-2].ff;
    while(proxsum<=1e6){
        pirlow.pb({proxsum,{nextbase,'L'}});
        nextbase++;
        totpirs++;
        proxsum=nextbase*nextbase+pirlow[SZ(pirlow)-2].ff;
    }
    //merge pyramids
    ll ph=0; ll pl=0;
    forn(i,totpirs){
        if(ph<SZ(pirhigh) and pl<SZ(pirlow)){
            if(pirhigh[ph].ff<pirlow[pl].ff){
                pirs.pb(pirhigh[ph]);
                ph++;
            }else{
                pirs.pb(pirlow[pl]);
                pl++;
            }
        }else if(ph<SZ(pirhigh)){
            pirs.pb(pirhigh[ph]);
            ph++;
        }else{
            pirs.pb(pirlow[pl]);
            pl++;
        }
    }
    // reverse(all(pirs));
    dp[0]={{0,-1},{-1,-1}};
    for(auto u:pirs){
        piramide p=u.ss;
        ll sum=u.ff;    
        for(ll i=1e6;i>=1;i--){
            if(sum>i) continue;
            if(dp[i-sum].ff.ff==INF) continue;
            else if(dp[i-sum].ff.ff+1<=dp[i].ff.ff){
                dp[i].ff.ff=dp[i-sum].ff.ff+1;
                dp[i].ff.ss=sum;
                dp[i].ss=p;
            }
        }
        // DBG(sum);
        // DBG(dp[19].ff.ss);
    }
    // forr(i,1,50){
    //     DBG(dp[i].ff.ss);
    // }

    //Answer queries
    bool ans = true; 
    int i = 1; 
    while (ans) ans = solve(i++);
    return 0;
}
