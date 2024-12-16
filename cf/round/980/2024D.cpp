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
    void set(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p);
        if (x < m) {
            set(2 * p, l, m, x, v);
        } else {
            set(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void set(int p, const Info &v) {
        set(1, 0, n, p, v);
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
    ll add = 1e18;
    void apply(Tag t) {
        add = min(add, t.add);
    }
};

struct Info {
    ll mi = 1e18;
    void apply(Tag t) {
        mi = min(mi, t.add);
    }
};

Info operator+(const Info &a, const Info &b) {
    return {min(a.mi, b.mi)};
}

using S = SegmentTree<Info, Tag>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i]--;
    }


    S t(n);
    ll now = 0, ans = 0;
    t.update(0, 1, {0});
    for (int i = 0; i < n; i++) {
        now += a[i];
        ll p = t.query(i, i + 1).mi;
        ans = max(ans, now - p);
        if (b[i] <= i) continue;
        else {
            t.update(i, b[i] + 1, {a[i] + p});
        }
    }

    cout << ans << "\n";
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