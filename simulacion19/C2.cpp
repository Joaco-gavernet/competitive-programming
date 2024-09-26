#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, L, U;
    cin >> n >> L >> U;
    vi A(n + 1), S(n + 1);
    for (ll i = 1; i <= n; ++i) {
        cin >> A[i];
        S[i] = S[i - 1] + A[i];
    }
    ll Q;
    cin >> Q;
    while (Q--) {
        ll B, E, X;
        cin >> B >> E >> X;
        ll final_wealth = X + S[E] - S[B - 1];
        final_wealth = min(max(final_wealth, L), U);
        cout << final_wealth << '\n';
    }
    return 0;
}
