#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template<class T> 
struct Fenwick {
    int n;
    vector<T> a;
    Fenwick(int x) : n(x), a(x + 1) {};
    void build() {
        for (int i = 1; i <= n; i++) {
            int nxt = i + (i & -i);
            if (nxt <= n) a[nxt] += a[i];
        }
    }
    T query(int x) {
        T res = 0;
        while (x) {
            res += a[x];
            x -= (x & -x);
        }
        return res;
    }
    T query(int l, int r) {
        return query(r) - query(l - 1);
    }
    void update(int x, T val) {
        while (x <= n) {
            a[x] += val;
            x += (x & -x);
        }
        return;
    }
};

using F = Fenwick<ll>;

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
        add = max(add, t.add);
    }
};

struct Info {
    int mx = 0;
    void apply(Tag t) {
        mx = max(mx, t.add);
    }
};

Info operator+(const Info &a, const Info &b) {
    return {max(a.mx, b.mx)};
}

using S = SegmentTree<Info, Tag>;


void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> p(n);
    vector<int> vis;

    vis.push_back(0);
    map<pair<int, int>, int> cnt;

    for (int i = 0; i < n; i++) {
        cin >> p[i][0] >> p[i][1];
        vis.push_back(p[i][0]);
        vis.push_back(p[i][1]);
        cnt[{p[i][0], p[i][1]}]++;
    }

    sort(vis.begin(), vis.end());
    vis.erase(unique(vis.begin(), vis.end()), vis.end());

    map<int, int> mp;
    int N = vis.size();
    vector<int> ref(N + 1);
    for (int i = 0; i < vis.size(); i++) {
        mp[vis[i]] = i + 1;
        ref[i + 1] = vis[i];
    }

    F f(N);
    S sgt(N);

    vector<int> nums(n);
    iota(nums.begin(), nums.end(), 0);
    sort(nums.begin(), nums.end(), [&](int x1, int x2){
        if (p[x1][0] != p[x2][0]) return p[x1][0] < p[x2][0];
        return p[x1][1] > p[x2][1];
    });

    vector<int> ans(n);

    int sum = 0;
    for (int i : nums) {
        int l = p[i][0], r = p[i][1];
        int cl = mp[r], cr = N;

        if (cnt[{l, r}] > 1) {
            f.update(mp[r], 1);
            sgt.update(mp[r] - 1, mp[r], {l});
            cnt[{l, r}] = 1;
        }

        int cnt = f.query(1, cl - 1);
        int L = -1, R = -1;
        while (cl <= cr) {
            int mid = (cl + cr) / 2;
            if (f.query(1, mid) == cnt) cl = mid + 1;
            else cr = mid - 1;
        }

        if (cl == N + 1) {
            R = r;
            L = l;
        } else {
            R = ref[cl];
            L = sgt.query(cl - 1, N).mx;
        }


        f.update(mp[r], 1);
        sgt.update(mp[r] - 1, mp[r], {l});

        ans[i] = (R - L) - (r - l);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << "\n";
    }
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