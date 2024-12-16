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
    int add = 0;
    void apply(Tag t) {
    }
};

struct Info {
    ll mx = 0;
    void apply(Tag t) {
    }
};

Info operator+(const Info &a, const Info &b) {
    return {max(a.mx, b.mx)};
}

using S = SegmentTree<Info, Tag>;

void solve() {
    int n;
    cin >> n;
    vector<ll> val(n);
    vector<int> d(n);
    vector<vector<array<int, 2>>> e(n);
    d[0] = 1;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }

    vector<int> cnt(n + 1), in(n), out(n);
    int tot = 0;
    S t(n);
    vector<vector<int>> p(n + 1);
    auto dfs = [&](auto &&self, int x, int fa = -1) -> void {
        cnt[d[x]]++;
        in[x] = ++tot;
        p[d[x]].push_back(x);
        for (auto [nxt, w] : e[x]) {
            if (nxt == fa) continue;
            val[nxt] = val[x] + w;
            d[nxt] = d[x] + 1;
            self(self, nxt, x);
        }
        out[x] = ++tot;
    };

    dfs(dfs, 0);
    for (int i = 1; i <= n; i++) cnt[i] += cnt[i - 1];
    int now = 0;
    vector<int> ref(n);
    for (int i = 1; i <= n; i++) {
        for (int x : p[i]) {
            ref[now] = x;
            t.set(now++, {val[x]});
        }
    }

    int qq;
    cin >> qq;

    while (qq--) {
        int x, m;
        cin >> x >> m;
        x--;
        m = d[x] + m;

        if (m > n) {
            cout << "-1\n";
            continue;
        }
        int l = cnt[m - 1];
        int r = cnt[m] - 1;

        if (l > r) {
            cout << "-1\n";
            continue;
        }
        int cl = l, cr = r;
        while (cl <= cr) {
            int mid = (cl + cr) / 2;
            if (out[ref[mid]] < in[x]) cl = mid + 1;
            else cr = mid - 1;
        }
        l = cl;

        cl = l, cr = r;
        while (cl <= cr) {
            int mid = (cl + cr) / 2;
            if (in[ref[mid]] > out[x]) cr = mid - 1;
            else cl = mid + 1;
        }
        r = cr;

        if (l > r) {
            cout << "-1\n";
            continue;
        }

        cout << t.query(l, r + 1).mx - val[x] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}