#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template<class T>
struct SegmentTree {
    static int n;
    int mod;
    vector<T> a, tr, mark, mark2;
    SegmentTree(int x, int m) {
        n = x;
        mod = m;
        a.resize(x + 1);
        tr.resize((x + 1) << 2);
        mark.resize((x + 1) << 2);
        mark2.resize((x + 1) << 2, 1);
    }

    void set(int i, T x) {
        a[i] = x;
    }
    void build(int p = 1, int l = 1, int r = n) {
        if (l == r) {
            tr[p] = a[l] % mod;
            return;
        }
        int mid = (l + r) / 2;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        tr[p] = (tr[p << 1] + tr[p << 1 | 1]) % mod;
    }
    void push_down(int p, int l, int r) {
        int len = r - l + 1;
        tr[p << 1] = tr[p << 1] * mark2[p] % mod;
        tr[p << 1 | 1] = tr[p << 1 | 1] * mark2[p] % mod;
        tr[p << 1] = (tr[p << 1] + (len + 1) / 2 * mark[p]) % mod;
        tr[p << 1 | 1] = (tr[p << 1 | 1] + len / 2 * mark[p]) % mod;
        mark2[p << 1] = mark2[p << 1] * mark2[p] % mod;
        mark[p << 1] = mark[p << 1] * mark2[p] % mod;
        mark2[p << 1 | 1] = mark2[p << 1 | 1] * mark2[p] % mod;
        mark[p << 1 | 1] = mark[p << 1 | 1] * mark2[p] % mod;
        mark[p << 1] = (mark[p << 1] + mark[p]) % mod;
        mark[p << 1 | 1] = (mark[p << 1 | 1] + mark[p]) % mod;
        mark[p] = 0;
        mark2[p] = 1;
        return;
    }
    void update(int l, int r, T x, int p = 1, int cl = 1, int cr = n) {
        if (cl >= l && cr <= r) {
            int len = cr - cl + 1;
            tr[p] = (tr[p] + len * x) % mod;
            mark[p] = (mark[p] + x) % mod;
            return;
        }
        push_down(p, cl, cr);
        int mid = (cl + cr) / 2;
        if (l <= mid) update(l, r, x, p << 1, cl, mid);
        if (r > mid) update(l, r, x, p << 1 | 1, mid + 1, cr);
        tr[p] = tr[p << 1] + tr[p << 1 | 1];
        tr[p] %= mod;
        return;
    }
    void update2(int l, int r, T x, int p = 1, int cl = 1, int cr = n) {
        if (cl >= l && cr <= r) {
            int len = cr - cl + 1;
            tr[p] = tr[p] * x % mod;
            mark2[p] = mark2[p] * x % mod;
            mark[p] = mark[p] * x % mod;
            return;
        }
        push_down(p, cl, cr);
        int mid = (cl + cr) / 2;
        if (l <= mid) update2(l, r, x, p << 1, cl, mid);
        if (r > mid) update2(l, r, x, p << 1 | 1, mid + 1, cr);
        tr[p] = tr[p << 1] + tr[p << 1 | 1];
        tr[p] %= mod;
        return;
    }
    T query(int l, int r, int p = 1, int cl = 1, int cr = n) {
        if (cl >= l && cr <= r) {
            return tr[p];
        }
        push_down(p, cl, cr);
        int mid = (cl + cr) / 2;
        T ans = 0;
        if (l <= mid) {
            ans += query(l, r, p << 1, cl, mid);
        }
        if (r > mid) {
            ans += query(l, r, p << 1 | 1, mid + 1, cr);
        }
        ans %= mod;
        return ans;
    }
};

template<class T>
int SegmentTree<T>::n = 0;

using S = SegmentTree<ll>;