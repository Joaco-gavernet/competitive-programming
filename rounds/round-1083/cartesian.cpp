#include <bits/stdc++.h>
using namespace std;

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
#define NaN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define ff first
#define ss second
#define SZ(x) int((x).size())
#define RAYA cerr << "===============================" << endl


struct CartesianTree {
  int root = -1;               // index of root in [0..n-1]
  vector<int> parent, left, right; // -1 means null
};

// Builds a MAX Cartesian tree:
// - Order of complexity: O(n)
// - Heap by value: a[parent] >= a[child]
// - Inorder traversal equals original array order
// Tie-break for equal values: earlier element stays "above" later ones (stable),
// because we pop only while a[st.back()] < a[i] (strict).
CartesianTree build(const vector<int>& a) {
  const int n = (int)a.size();
  CartesianTree t;
  t.parent.assign(n, -1);
  t.left.assign(n, -1);
  t.right.assign(n, -1);
  if (n == 0) return t;

  vector<int> st;
  st.reserve(n);

  for (int i = 0; i < n; ++i) {
    int last = -1;

    // Pop all strictly smaller values: they become part of i's left subtree.
    while (!st.empty() && a[st.back()] < a[i]) {
      last = st.back();
      st.pop_back();
    }

    // If stack not empty, its top is the first >= a[i] to the left => parent of i.
    if (!st.empty()) {
      t.parent[i] = st.back();
      t.right[st.back()] = i;
    }

    // The last popped node becomes the left child of i.
    if (last != -1) {
      t.parent[last] = i;
      t.left[i] = last;
    }

    st.push_back(i);
  }

  // Root is the only node with no parent.
  for (int i = 0; i < n; ++i) {
    if (t.parent[i] == -1) {
      t.root = i;
      break;
    }
  }
  return t;
}


void solve() {
}

int main(){
  NaN;
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
