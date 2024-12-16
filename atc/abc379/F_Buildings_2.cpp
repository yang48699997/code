#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type, less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

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
        add += t.add;
    }
};

struct Info {
    int mx = 0;
    void apply(Tag t) {
    }
};

Info operator+(const Info &a, const Info &b) {
    return {max(a.mx, b.mx)};
}

using S = SegmentTree<Info, Tag>;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> h(n);
    S t(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        h[i]--;
        t.set(i, {h[i]});
    }

    vector<array<int, 2>> ask(q);
    for (int i = 0; i < q; i++) {
        cin >> ask[i][0] >> ask[i][1];
        ask[i][0]--;
        ask[i][1]--;
    }

    vector<int> nums(q);
    iota(nums.begin(), nums.end(), 0);
    sort(nums.begin(), nums.end(), [&](int x1, int x2) {
        return ask[x1][0] > ask[x2][0]; 
    });
    vector<int> ans(q);

    int now = n;
    ordered_set st;
    for (int i = 0; i < q; i++) {
        int l = ask[nums[i]][0];
        int r = ask[nums[i]][1];
        while (now > l + 1) {
            now--;
            while (!st.empty() && *st.begin() < h[now]) {
                st.erase(st.begin());
            }
            st.insert(h[now]);
        }
        int mx = t.query(l + 1, r + 1).mx;

        ans[nums[i]] = st.size() - st.order_of_key(mx);
        if (st.find(mx) != st.end()) ans[nums[i]]--;
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}