#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template<class T>
struct SegmentTree {
    static int n;
    vector<T> a, tr, mark;
    SegmentTree(int x) {
        n = x;
        a.resize(x + 1);
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
        tr[p] = tr[p << 1] + tr[p << 1 | 1];
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
            int len = cr - cl + 1;
            tr[p] += len * x;
            mark[p] += x;
            return;
        }
        if (mark[p]) push_down(p, cl, cr);
        int mid = (cl + cr) / 2;
        if (l <= mid) update(l, r, x, p << 1, cl, mid);
        if (r > mid) update(l, r, x, p << 1 | 1, mid + 1, cr);
        tr[p] = tr[p << 1] + tr[p << 1 | 1];
        return;
    }
    T query(int l, int r, int p = 1, int cl = 1, int cr = n) {
        if (cl >= l && cr <= r) {
            return tr[p];
        }
        if (mark[p]) push_down(p, cl, cr);
        int mid = (cl + cr) / 2;
        T ans = 0;
        if (l <= mid) {
            ans += query(l, r, p << 1, cl, mid);
        }
        if (r > mid) {
            ans += query(l, r, p << 1 | 1, mid + 1, cr);
        }
        return ans;
    }
};

template<class T>
int SegmentTree<T>::n = 0;

using S = SegmentTree<ll>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> b = a;
    sort(b.begin(), b.end());
    int m = unique(b.begin(), b.end()) - b.begin();
    b.resize(m);
    vector<int> p(n + 1);
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
        p[a[i]] = i + 1;
    }

    S t1(n), t2(n);
    t1.build();
    t2.build();
    ll ans = 0;
    for (int i = n; i > 0; i--) {
        ll k = t1.query(1, p[i]);
        ans += t2.query(1, p[i]);
        t2.update(p[i], p[i], k);
        t1.update(p[i], p[i], 1);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}