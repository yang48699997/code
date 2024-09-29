#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template<class Info, class Tag>
struct SegmentTree {
    int n;
    vector<Info> info;
    vector<Tag> tag;
    SegmentTree() : n(0) {}
    SegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    SegmentTree(vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(vector<Info>(n_, v_));
    }
    template<class T>
    void init(vector<T> init_) {
        n = init_.size();
        info.assign(4 << __lg(n), Info());
        tag.assign(4 << __lg(n), Tag());
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void apply(int p, const Tag &v) {
        info[p].apply(v);
        tag[p].apply(v);
    }
    void push(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p);
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info query(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        push(p);
        return query(2 * p, l, m, x, y) + query(2 * p + 1, m, r, x, y);
    }
    Info query(int l, int r) {
        return query(1, 0, n, l, r);
    }
    void update(int p, int l, int r, int x, int y, const Tag &v) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            apply(p, v);
            return;
        }
        int m = (l + r) / 2;
        push(p);
        update(2 * p, l, m, x, y, v);
        update(2 * p + 1, m, r, x, y, v);
        pull(p);
    }
    void update(int l, int r, const Tag &v) {
        return update(1, 0, n, l, r, v);    
    }
};

struct Tag {
    int add = 0;
    void apply(Tag t) {
        add += t.add;
    }
};

struct Info {
    int mi = 0;
    int cnt = 0;
    void apply(Tag t) {
        mi += t.add;
    }
};

Info operator+(const Info &a, const Info &b) {
    if (a.mi < b.mi) {
        return a;
    } else if (a.mi > b.mi) {
        return b;
    } else {
        return {a.mi, a.cnt + b.cnt};
    }
}

using S = SegmentTree<Info, Tag>;


void solve() {
    int q, R;
    cin >> q >> R;
    vector<int> l(q), r(q);
    vector<int> x(q), y(q);
    vector<int> a{0, R};
    for (int i = 0; i < q; i++) {
        cin >> x[i] >> y[i];
        l[i] = x[i] - y[i];
        r[i] = x[i] + y[i];
        l[i] = max(0, l[i]);
        r[i] = min(r[i], R);
        a.emplace_back(l[i]);
        a.emplace_back(r[i]);
    }
    sort(a.begin(), a.end());
    int m = unique(a.begin(), a.end()) - a.begin();
    a.resize(m);

    S t(m);
    set<pair<int, int>> st;
    for (int i = 1; i < m; i++) {
        t.modify(i - 1, {0, a[i] - a[i - 1]});
    }

    for (int i = 0; i < q; i++) {
        int cl = lower_bound(a.begin(), a.end(), l[i]) - a.begin();
        int cr = lower_bound(a.begin(), a.end(), r[i]) - a.begin();
        if (st.count({x[i], y[i]})) {
            st.erase({x[i], y[i]});
            t.update(cl, cr, {-1});
        } else {
            st.emplace(x[i], y[i]);
            t.update(cl, cr, {1});
        }
        Info info = t.query(0, m);
        int res = R;
        // cerr << info.mi << " " << info.cnt << "\n";
        // cerr << a[cl] << " " << a[cr] << "\n";
        if (info.mi == 0) {
            res = R - info.cnt;
        }
        double t = sqrt(2);
        cout << fixed << setprecision(6) << res * t << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}