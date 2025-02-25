#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds; 
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi; 
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++) 
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define SZ(x) int((x).size())
#define esta(v,x) (v).find(x) != (v).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "================================\n"

typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set; 

int main() {
  FIN; 
  
  int n; cin >> n; 
  indexed_set st; 
  forn(i,n) {
    int act; cin >> act; 
    st.insert({i, act}); 
    st.insert({i+n, act}); 
  }

  int pos = 0; 
  int tot = n; 
  while (tot > 1) {
    auto [id, jmp] = *st.find_by_order(pos); 
    jmp--; 
    jmp %= tot; 
    auto [del, x] = *st.find_by_order(pos +jmp); 
    del %= n; 
    tot--; 

    auto ptr = st.find({del, x}); ptr++;
    pos = distance(st.begin(), ptr); 
    if (pos == tot +1) pos = 0; 
    else pos--; 
    st.erase(--ptr); 
    st.erase({del +n, x}); 
  }
  cout << (*st.begin()).first +1 << endl; 


  return 0; 
}
