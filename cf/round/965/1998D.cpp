#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template<class T>
struct SegmentTree {
    static int n;
    vector<T> a, tr, mark;
    SegmentTree(int x) {
        n = x;
        a.resize(x + 1, x);
        tr.resize((x + 1) << 2);
        mark.resize((x + 1) << 2);
    }

    void set(int i, T x) {
        a[i] = x;
    }
    void build(int p = 1, int l = 1, int r = n) {
        if (l == r) {
            tr[p] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        tr[p] = min(tr[p << 1], tr[p << 1 | 1]);
    }
    void push_down(int p, int l, int r) {
        int len = r - l + 1;
        tr[p << 1] += (len + 1) / 2 * mark[p];
        tr[p << 1 | 1] += len / 2 * mark[p];
        mark[p << 1] += mark[p];
        mark[p << 1 | 1] += mark[p];
        mark[p] = 0;
        return;
    }
    void update(int l, int r, T x, int p = 1, int cl = 1, int cr = n) {
        if (cl >= l && cr <= r) {
            tr[p] = min(x, tr[p]);
            return;
        }
        if (mark[p]) push_down(p, cl, cr);
        int mid = (cl + cr) / 2;
        if (l <= mid) update(l, r, x, p << 1, cl, mid);
        if (r > mid) update(l, r, x, p << 1 | 1, mid + 1, cr);
        tr[p] = min(tr[p << 1], tr[p << 1 | 1]);
        return;
    }
    T query(int l, int r, int p = 1, int cl = 1, int cr = n) {
        if (cl >= l && cr <= r) {
            return tr[p];
        }
        if (mark[p]) push_down(p, cl, cr);
        int mid = (cl + cr) / 2;
        T ans = n;
        if (l <= mid) {
            ans = min(ans, query(l, r, p << 1, cl, mid));
        }
        if (r > mid) {
            ans = min(ans, query(l, r, p << 1 | 1, mid + 1, cr));
        }
        return ans;
    }
};

template<class T>
int SegmentTree<T>::n = 0;

using S = SegmentTree<ll>;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> e(n);
    for (int i = 0; i < n - 1; i++) {
        e[i].push_back(i + 1);
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if (x < y) swap(x, y);
        e[y].push_back(x);
    }

    S t(n);
    t.set(1, 0);
    t.build();
    cout << 1;
    vector<int> d(n + 1, n);
    d[0] = 0;
    for (int i = 2; i < n; i++) {
        int ok = 0;
        for (int nxt : e[i - 2]) {
            if (d[nxt] > d[i - 2] + 1) {
                t.update(nxt + 1, nxt + 1, d[i - 2] + 1 - nxt);
                d[nxt] = d[i - 2] + 1;
            }
        }
        // cerr << i << "\n";
        int res = t.query(i + 1, n);
        // cerr << i << " " <<  res << "\n";
        if (res + i > 0) cout << 1;
        else cout << 0;
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}