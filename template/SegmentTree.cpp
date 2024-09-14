#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template<class T>
struct SegmentTree {
    static int n;
    vector<T> a, tr, mark, mi, mx;
    SegmentTree(int x) {
        n = x;
        a.resize(x + 1);
        tr.resize((x + 1) << 2);
        mark.resize((x + 1) << 2);
        mi.resize((x + 1) << 2);
        mx.resize((x + 1) << 2);
    }

    void set(int i, T x) {
        a[i] = x;
    }
    void build(int p = 1, int l = 1, int r = n) {
        if (l == r) {
            tr[p] = a[l];
            mi[p] = a[l];
            mx[p] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        tr[p] = tr[p << 1] + tr[p << 1 | 1];
        mi[p] = min(mi[p << 1], mi[p << 1 | 1]);
        mx[p] = max(mx[p << 1], mx[p << 1 | 1]);
    }
    void push_down(int p, int l, int r) {
        int len = r - l + 1;
        tr[p << 1] += (len + 1) / 2 * mark[p];
        mi[p << 1] += mark[p];
        mx[p << 1] += mark[p];
        tr[p << 1 | 1] += len / 2 * mark[p];
        mi[p << 1 | 1] += mark[p];
        mx[p << 1 | 1] += mark[p];
        mark[p << 1] += mark[p];
        mark[p << 1 | 1] += mark[p];
        mark[p] = 0;
        return;
    }
    void update(int l, int r, T x, int p = 1, int cl = 1, int cr = n) {
        if (cl >= l && cr <= r) {
            int len = cr - cl + 1;
            tr[p] += len * x;
            mi[p] += x;
            mx[p] += x;
            mark[p] += x;
            return;
        }
        if (mark[p]) push_down(p, cl, cr);
        int mid = (cl + cr) / 2;
        if (l <= mid) update(l, r, x, p << 1, cl, mid);
        if (r > mid) update(l, r, x, p << 1 | 1, mid + 1, cr);
        tr[p] = tr[p << 1] + tr[p << 1 | 1];
        mi[p] = min(mi[p << 1], mi[p << 1 | 1]);
        mx[p] = max(mx[p << 1], mx[p << 1 | 1]);
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
    T query_max(int l, int r, int p = 1, int cl = 1, int cr = n) {
        if (cl >= l && cr <= r) {
            return mx[p];
        }
        if (mark[p]) push_down(p, cl, cr);
        int mid = (cl + cr) / 2;
        T ans = numeric_limits<T>::min();
        if (l <= mid) {
            ans = max(ans, query_max(l, r, p << 1, cl, mid));
        }
        if (r > mid) {
            ans = max(ans, query_max(l, r, p << 1 | 1, mid + 1, cr));
        }
        return ans;
    }
    T query_min(int l, int r, int p = 1, int cl = 1, int cr = n) {
        if (cl >= l && cr <= r) {
            return mi[p];
        }
        if (mark[p]) push_down(p, cl, cr);
        int mid = (cl + cr) / 2;
        T ans = numeric_limits<T>::max();
        if (l <= mid) {
            ans = min(ans, query_min(l, r, p << 1, cl, mid));
        }
        if (r > mid) {
            ans = min(ans, query_min(l, r, p << 1 | 1, mid + 1, cr));
        }
        return ans;
    }
};

template<class T>
int SegmentTree<T>::n = 0;

using S = SegmentTree<ll>;