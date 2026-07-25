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
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "================================\n"



int main() {
    FIN;
    int n; cin >> n;
    if(n<=3) {cout << "NO\n"; return 0;}
    cout << "YES\n";
    if(n%2==0){
        cout << "1 * 2 = 2\n";
        cout << "3 * 2 = 6\n";
        cout << "6 * 4 = 24\n";
        for(int k=6; k<=n; k+=2){
            cout << k << " - " << k-1 << " = 1\n";
            cout << "24 * 1 = 24\n";
        } 
    }
    else{
        cout << "3 + 2 = 5\n";
        cout << "5 - 1 = 4\n";
        cout << "4 * 5 = 20\n";
        cout << "4 + 20 = 24\n";
        for(int k=7; k<=n; k+=2){
            cout << k << " - " << k-1 << " = 1\n";
            cout << "24 * 1 = 24\n";
        } 
    }
    return 0;
}