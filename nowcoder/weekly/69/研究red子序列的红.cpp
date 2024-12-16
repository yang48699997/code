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
    vector<long long> cnt = vector<ll> (6);
    void apply(Tag t) {
        // cnt = t.cnt;
    }
};

struct Info {
    vector<long long> cnt = vector<ll> (6);
    void apply(Tag t) {
        // cnt = t.cnt;
    }
};

Info operator+(const Info &a, const Info &b) {
    vector<long long> res = vector<ll> (6, 0);
    res[0] = a.cnt[0] + b.cnt[0];
    res[1] = a.cnt[1] + b.cnt[1];
    res[2] = a.cnt[2] + b.cnt[2];
    res[3] = a.cnt[0] * b.cnt[1] + a.cnt[3] + b.cnt[3];
    res[4] = a.cnt[1] * b.cnt[2] + a.cnt[4] + b.cnt[4];
    res[5] = a.cnt[0] * b.cnt[4] + a.cnt[3] * b.cnt[2] + a.cnt[5] + b.cnt[5];
    return {res};
}

using S = SegmentTree<Info, Tag>;

/* 
r  : 0
e  : 1
d  : 2
re : 3
ed : 4
red : 5

 */
void solve() {
    int n, q;
    cin >> n >> q;

    string s, t;
    cin >> s >> t;

    S t1(n), t2(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'r') {
            t1.set(i, {{1, 0, 0, 0, 0, 0}});
        } else if (s[i] == 'e') {
            t1.set(i, {{0, 1, 0, 0, 0, 0}});
        } else if (s[i] == 'd') {
            t1.set(i, {{0, 0, 1, 0, 0, 0}});
        }

        if (t[i] == 'r') {
            t2.set(i, {{1, 0, 0, 0, 0, 0}});
        } else if (t[i] == 'e') {
            t2.set(i, {{0, 1, 0, 0, 0, 0}});
        } else if (t[i] == 'd') {
            t2.set(i, {{0, 0, 1, 0, 0, 0}});
        }
    }
    

    while (q--) {
        int i;
        cin >> i;
        i--;

        swap(s[i], t[i]);

        if (s[i] == 'r') {
            t1.set(i, {{1, 0, 0, 0, 0, 0}});
        } else if (s[i] == 'e') {
            t1.set(i, {{0, 1, 0, 0, 0, 0}});
        } else if (s[i] == 'd') {
            t1.set(i, {{0, 0, 1, 0, 0, 0}});
        } else {
            t1.set(i, {{0, 0, 0, 0, 0, 0}});
        }

        if (t[i] == 'r') {
            t2.set(i, {{1, 0, 0, 0, 0, 0}});
        } else if (t[i] == 'e') {
            t2.set(i, {{0, 1, 0, 0, 0, 0}});
        } else if (t[i] == 'd') {
            t2.set(i, {{0, 0, 1, 0, 0, 0}});
        } else {
            t2.set(i, {{0, 0, 0, 0, 0, 0}});
        }

        cout << t1.query(0, n).cnt[5] - t2.query(0, n).cnt[5] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}