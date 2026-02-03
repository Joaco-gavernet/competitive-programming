#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<int> bit;
    Fenwick(int n = 0) : n(n), bit(n + 1, 0) {}

    void add(int i, int v) {
        for (; i <= n; i += i & -i) bit[i] += v;
    }
    int sumPrefix(int i) const {
        int s = 0;
        for (; i > 0; i -= i & -i) s += bit[i];
        return s;
    }
    // smallest idx such that prefix sum >= k (assumes 1 <= k <= total)
    int kth(int k) const {
        int idx = 0;
        int pw = 1;
        while ((pw << 1) <= n) pw <<= 1;
        for (int step = pw; step > 0; step >>= 1) {
            int ni = idx + step;
            if (ni <= n && bit[ni] < k) {
                idx = ni;
                k -= bit[ni];
            }
        }
        return idx + 1;
    }
};

struct SegTree {
    int n;
    vector<int> minPref, maxSuf;
    vector<int> cntAlive;
    vector<long long> sumPrefAlive, sumSufAlive, sumProdAlive;
    vector<int> lazyPref, lazySuf; // 0 = none (values are always >= 1 in assigns)

    SegTree(const vector<int>& pref, const vector<int>& suf, const vector<int>& alive) {
        n = (int)pref.size() - 1; // 1-indexed
        int sz = 4 * n + 5;
        minPref.assign(sz, 0);
        maxSuf.assign(sz, 0);
        cntAlive.assign(sz, 0);
        sumPrefAlive.assign(sz, 0);
        sumSufAlive.assign(sz, 0);
        sumProdAlive.assign(sz, 0);
        lazyPref.assign(sz, 0);
        lazySuf.assign(sz, 0);
        build(1, 1, n, pref, suf, alive);
    }

    long long allBeauty() const { return sumProdAlive[1]; }

    void applyPref(int v, int idx) {
        minPref[idx] = v;
        lazyPref[idx] = v;
        sumPrefAlive[idx] = 1LL * v * cntAlive[idx];
        sumProdAlive[idx] = 1LL * v * sumSufAlive[idx];
    }

    void applySuf(int v, int idx) {
        maxSuf[idx] = v;
        lazySuf[idx] = v;
        sumSufAlive[idx] = 1LL * v * cntAlive[idx];
        sumProdAlive[idx] = 1LL * v * sumPrefAlive[idx];
    }

    void push(int idx) {
        if (lazyPref[idx] != 0) {
            int v = lazyPref[idx];
            applyPref(v, idx * 2);
            applyPref(v, idx * 2 + 1);
            lazyPref[idx] = 0;
        }
        if (lazySuf[idx] != 0) {
            int v = lazySuf[idx];
            applySuf(v, idx * 2);
            applySuf(v, idx * 2 + 1);
            lazySuf[idx] = 0;
        }
    }

    void pull(int idx) {
        int L = idx * 2, R = idx * 2 + 1;
        minPref[idx] = min(minPref[L], minPref[R]);
        maxSuf[idx] = max(maxSuf[L], maxSuf[R]);
        cntAlive[idx] = cntAlive[L] + cntAlive[R];
        sumPrefAlive[idx] = sumPrefAlive[L] + sumPrefAlive[R];
        sumSufAlive[idx] = sumSufAlive[L] + sumSufAlive[R];
        sumProdAlive[idx] = sumProdAlive[L] + sumProdAlive[R];
    }

    void build(int idx, int l, int r,
               const vector<int>& pref, const vector<int>& suf, const vector<int>& alive) {
        if (l == r) {
            minPref[idx] = pref[l];
            maxSuf[idx] = suf[l];
            cntAlive[idx] = alive[l];
            if (alive[l]) {
                sumPrefAlive[idx] = pref[l];
                sumSufAlive[idx] = suf[l];
                sumProdAlive[idx] = 1LL * pref[l] * suf[l];
            }
            return;
        }
        int m = (l + r) >> 1;
        build(idx * 2, l, m, pref, suf, alive);
        build(idx * 2 + 1, m + 1, r, pref, suf, alive);
        pull(idx);
    }

    // range assign pref
    void assignPref(int ql, int qr, int v) { assignPref(1, 1, n, ql, qr, v); }
    void assignPref(int idx, int l, int r, int ql, int qr, int v) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            applyPref(v, idx);
            return;
        }
        push(idx);
        int m = (l + r) >> 1;
        assignPref(idx * 2, l, m, ql, qr, v);
        assignPref(idx * 2 + 1, m + 1, r, ql, qr, v);
        pull(idx);
    }

    // range assign suf
    void assignSuf(int ql, int qr, int v) { assignSuf(1, 1, n, ql, qr, v); }
    void assignSuf(int idx, int l, int r, int ql, int qr, int v) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            applySuf(v, idx);
            return;
        }
        push(idx);
        int m = (l + r) >> 1;
        assignSuf(idx * 2, l, m, ql, qr, v);
        assignSuf(idx * 2 + 1, m + 1, r, ql, qr, v);
        pull(idx);
    }

    // point query pref[pos]
    int getPref(int pos) { return getPref(1, 1, n, pos); }
    int getPref(int idx, int l, int r, int pos) {
        if (l == r) return minPref[idx];
        push(idx);
        int m = (l + r) >> 1;
        if (pos <= m) return getPref(idx * 2, l, m, pos);
        return getPref(idx * 2 + 1, m + 1, r, pos);
    }

    // point query suf[pos]
    int getSuf(int pos) { return getSuf(1, 1, n, pos); }
    int getSuf(int idx, int l, int r, int pos) {
        if (l == r) return maxSuf[idx];
        push(idx);
        int m = (l + r) >> 1;
        if (pos <= m) return getSuf(idx * 2, l, m, pos);
        return getSuf(idx * 2 + 1, m + 1, r, pos);
    }

    // activate alive[pos] = 1
    void activate(int pos) { activate(1, 1, n, pos); }
    void activate(int idx, int l, int r, int pos) {
        if (l == r) {
            if (cntAlive[idx] == 1) return;
            cntAlive[idx] = 1;
            long long p = minPref[idx];
            long long s = maxSuf[idx];
            sumPrefAlive[idx] = p;
            sumSufAlive[idx] = s;
            sumProdAlive[idx] = p * s;
            return;
        }
        push(idx);
        int m = (l + r) >> 1;
        if (pos <= m) activate(idx * 2, l, m, pos);
        else activate(idx * 2 + 1, m + 1, r, pos);
        pull(idx);
    }

    // find first index in [ql..qr] with pref < v, return n+1 if none
    int findFirstPrefLess(int ql, int qr, int v) { return findFirstPrefLess(1, 1, n, ql, qr, v); }
    int findFirstPrefLess(int idx, int l, int r, int ql, int qr, int v) {
        if (qr < l || r < ql) return n + 1;
        if (minPref[idx] >= v) return n + 1;
        if (l == r) return l;
        push(idx);
        int m = (l + r) >> 1;
        int leftRes = findFirstPrefLess(idx * 2, l, m, ql, qr, v);
        if (leftRes != n + 1) return leftRes;
        return findFirstPrefLess(idx * 2 + 1, m + 1, r, ql, qr, v);
    }

    // find last index in [ql..qr] with suf > v, return 0 if none
    int findLastSufGreater(int ql, int qr, int v) { return findLastSufGreater(1, 1, n, ql, qr, v); }
    int findLastSufGreater(int idx, int l, int r, int ql, int qr, int v) {
        if (qr < l || r < ql) return 0;
        if (maxSuf[idx] <= v) return 0;
        if (l == r) return l;
        push(idx);
        int m = (l + r) >> 1;
        int rightRes = findLastSufGreater(idx * 2 + 1, m + 1, r, ql, qr, v);
        if (rightRes != 0) return rightRes;
        return findLastSufGreater(idx * 2, l, m, ql, qr, v);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> b(q + 1);
    for (int i = 1; i <= q; i++) cin >> b[i];

    // 1) Map deletions (b-th alive) -> original indices
    Fenwick fw(n);
    for (int i = 1; i <= n; i++) fw.add(i, 1);

    vector<int> order(q + 1);           // order[i] = original index removed at step i
    vector<char> removed(n + 1, 0);
    for (int i = 1; i <= q; i++) {
        int idx = fw.kth(b[i]);
        order[i] = idx;
        removed[idx] = 1;
        fw.add(idx, -1);
    }

    // 2) Build initial state = after all removals
    const int INF = 1'000'000 + 1;
    vector<int> alive(n + 1, 0);
    vector<int> pref(n + 1, INF);
    vector<int> suf(n + 2, 0);

    int curMin = INF;
    for (int i = 1; i <= n; i++) {
        if (!removed[i]) alive[i] = 1;
        int x = alive[i] ? a[i] : INF;
        curMin = min(curMin, x);
        pref[i] = curMin;
    }

    int curMax = 0;
    for (int i = n; i >= 1; i--) {
        int y = alive[i] ? a[i] : 0;
        curMax = max(curMax, y);
        suf[i] = curMax;
    }

    SegTree st(pref, suf, alive);

    // 3) Process backwards (add back removed athletes)
    vector<long long> ans(q + 1);
    ans[q] = st.allBeauty(); // after all removals

    for (int step = q; step >= 1; step--) {
        int j = order[step];
        int val = a[j];

        // update pref segment if needed
        int prefJ = st.getPref(j);
        if (val < prefJ) {
            int r = st.findFirstPrefLess(j, n, val); // first pref < val
            if (r == n + 1) r = n + 1;
            st.assignPref(j, r - 1, val);
        }

        // update suf segment if needed
        int sufJ = st.getSuf(j);
        if (val > sufJ) {
            int l = st.findLastSufGreater(1, j, val); // last suf > val
            // update [l+1 .. j]
            st.assignSuf(l + 1, j, val);
        }

        // activate position j
        st.activate(j);

        ans[step - 1] = st.allBeauty();
    }

    for (int i = 0; i <= q; i++) {
        cout << ans[i] << (i == q ? '\n' : ' ');
    }
    return 0;
}
