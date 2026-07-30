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


bool letter(char c) {
    return 'a' <= c and c <= 'z'; 
}

void output(ll act, vi& frac) {
    string ans = "";
    
    frac[0] += frac[1] / 10;
    act += frac[0] / 10;
    frac[1] %= 10; 
    frac[0] %= 10;

    while (act > 0) {
        if (SZ(ans)) ans += '.';
        if (act > 0) ans += '0' + (act % 10), act /= 10;
        if (act > 0) ans += '0' + (act % 10), act /= 10;
        if (act > 0) ans += '0' + (act % 10), act /= 10;
    }

    reverse(all(ans)); 
    cout << ans;
    if (SZ(ans) == 0) cout << '0';
    if (frac[0] + frac[1] > 0) cout << '.' << frac[0] << frac[1];
    cout << '\n';
}

int main() {
    FIN;

    string s; cin >> s; 
    
    int i = 0;
    ll tot = 0, act = 0;
    vi frac(2); 
    s += 'a'; 
    const int n = SZ(s); 
    while (i < n) {
        if (i < n and letter(s[i])) i++;
        else {
            while (i < n and !letter(s[i])) {
                if (s[i] == '.') {
                    if (i + 3 < n and letter(s[i + 3])) {
                        frac[0] += s[i + 1] - '0';
                        frac[1] += s[i + 2] - '0'; 
                        i += 2; 
                    } 
                } else act *= 10, act += s[i] - '0'; 
                i++; 
            }
            tot += act;
            act = 0;
        }
    }
    output(tot, frac);

    return 0;
}