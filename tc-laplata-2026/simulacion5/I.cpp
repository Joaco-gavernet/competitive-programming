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
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"

using pii = pair< int, int >; 

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vv;


void cas( ) { 

    int cantR = 0; int cantCh = 0; 

    int r, c; cin >> r >> c >> cantCh; 
    vector< vector< int > > M ( r, vector< int >  ( c, 0 )  ); 

    fore ( i, 0, r ) 
    {
        string s; cin >> s; 
        fore ( j, 0, c ) {
            if ( s[ j ] == 'R' ) { M[ i ][ j ] = 1; cantR++; }
        }
    }

    vector< pii > ordenadas; 

    for ( int i = 0; i < r; i += 1 ) {
        if ( i % 2 == 0 ) {
            for ( int j = 0; j < c; j++ ) ordenadas.push_back ( { i, j } ); 
        } else {
            for ( int j = c - 1; j >= 0; j-- ) ordenadas.push_back ( { i , j } );
        }
    }

    vector< vector< int > > rta ( r, vector< int >  ( c, 0 )  ); 
    int cantCada = cantR / cantCh; 
    int rem = cantR - ( cantCh * cantCada ); 
    // DBG(cantCada);
    // DBG(rem);
    // for (auto [x, y]: ordenadas) cerr << x << ' ' << y << '\n';
    // RAYA;

    int actCh = 0; int actR = 0; int add = 0; 
    for ( int pC = 0; pC < r * c; pC ++ ) {
        add = actCh < rem;
        auto [y, x] = ordenadas[pC]; 
        rta[y][x] = actCh; 
        actR += M[y][x];
        if (actR == (cantCada + add) and actCh < cantCh - 1) actCh++, actR = 0; 
    }

    vector<char> v; 
    fore ( i, 'a', 'z' + 1 ) v.push_back( char(i) );
    fore ( i, 'A', 'Z' + 1 ) v.push_back( char(i) ); 
    fore ( i, '0', '9' + 1 ) v.push_back ( char(i) ); 
    // DBG(SZ(v));
    // for (auto c : v) cerr << c << ' ';
    // cout << '\n';

    fore ( i, 0, r ) {
        fore ( j, 0, c ) cout << v[ rta[ i ][ j ] ]; 
        cout << "\n"; 
    }
    // RAYA; 
}

int main() {
    NCG;
    int t; cin >> t; fore ( i, 0, t ) { cas(); }
}

/*

% ./I < i1  
cantCada = 0
rem = 1
0 0
0 1
0 2
0 3
0 4
1 4
1 3
1 2
1 1
1 0
2 0
2 1
2 2
2 3
2 4
==========================
aaabc
hgfed
ijklm

*/