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

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vv;

ll trad ( ll x ) {

    if ( x >= 0 ) return 0; 

    x *= -1; 
    if ( x % 100 == 0 ) { return x / 100; }
    else { return ( x / 100 ) + 1; }

}

int main() {
    
    ll n, m; cin >> n >> m; 
    vector<ll> c ( n );
    vector<ll> w ( n ); 

    fore ( i, 0, n ) { cin >> c[ i ]; }
    fore ( i, 0, n ) { cin >> w[ i ]; }

    vector<ll> e ( n ); 
    fore ( i, 0, n ) { e[ i ] = c [ i ] % 100; }

    vector<ll> cant ( n );
    ll sp = m; fore ( i, 0, n ) { sp -= e[ i ]; cant[ i ] = trad ( sp ); }   

    // for ( ll c : cant ) { cout << c << " "; } cout << endl; 

    vector<ll> v ( n ); 
    fore ( i, 0, n ) { v[ i ] = w[ i ] * ( 100 - e[ i ] ); }

    ll valor = 0; vector<ll> asignados ( n, false ); 
    set< pair<ll, ll> > set_v; 
    ll cant_act = 0; 

    fore ( i, 0, n ) {

        if ( c[ i ] % 100 == 0 ) { continue; }

        set_v.insert ( { v[ i ], i } ); 

        if ( cant[ i ] != cant_act ) {

            cant_act = cant[ i ];

            pair<ll, ll> p = *set_v.begin(); 
            valor += p.first; 
            asignados [ p.second ] = true; 

            set_v.erase ( p ); 
        }

    }

    // fore ( i, 0, n ) { cout << asignados [ i ] << " "; } cout << "\n"; 

    cout << valor << "\n"; 
    fore ( i, 0, n ) {

        if ( asignados[ i ] ) { cout << ( (c[ i ] / 100) + 1 ) << " " << 0 << "\n"; }
        else { cout << ( c[ i ] / 100 ) << " " <<  e[ i ] << "\n";  }

    }
 
}