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

bool sepuede_automaton ( string &s, string &t ) {

    int ss = (int)s.size(); 
    int st = (int)t.size(); 

    int p1 = 0; int p2 = 0; 

    if ( ss < st ) { return false; }

    while ( p1 < ss and p2 < st ) {
        
        while ( p1 < ss and s[p1]  != t[ p2] ) { p1++; }

        if ( p1 == ss ) { return false; }

        p1++; p2++; 
    }

    if ( p2 == st ) { return true; } else {
        return false; 
    }

    assert ( 0 ); 
    return true; 

}

bool sepuede_array ( string &s , string &t ) {

    vector<int> cants ( 27, 0 ); 
    vector<int> cantt ( 27, 0 ); 

    for ( char c : s ) { cants [ int ( c ) - int ( 'a') ]++; }
    for ( char c : t ) { cantt [ int ( c ) - int ( 'a') ]++; }

    fore ( i, 0, 27 ) if ( cantt[ i ] != cants [ i ] ) { return false; }
    return true;
}

bool sepuede_both ( string &s , string &t ) {

    vector<int> cants ( 27, 0 ); 
    vector<int> cantt ( 27, 0 ); 

    for ( char c : s ) { cants [ int ( c ) - int ( 'a') ]++; }
    for ( char c : t ) { cantt [ int ( c ) - int ( 'a') ]++; }

    fore ( i, 0, 27 ) if ( cantt[ i ] > cants [ i ] ) { return false; }
    return true;
}

int main() {
    NCG;

    string s, t; cin >> s >> t; 

    if ( sepuede_automaton ( s, t ) ) {
        cout << "automaton" << "\n"; 
        return 0; 
    }

    if ( sepuede_array ( s, t ) ) {
        cout << "array" << "\n"; 
        return 0; 
    }

    if ( sepuede_both ( s, t ) ) {
        cout << "both" << "\n";
        return 0;
    }

    cout << "need tree" << "\n"; 

    return 0;
}