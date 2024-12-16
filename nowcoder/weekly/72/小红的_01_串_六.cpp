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

/* 
op:
0 nothing
1 all 1
2 all 0
3 reverse
 */
struct Tag {
    int op = 0;
    void apply(Tag t) {
        if (t.op == 1) op = 1;
        else if (t.op == 2) op = 2;
        else if (t.op == 3) {
            if (op == 0) op = 3;
            else if (op == 3) op = 0;
            else if (op == 1) op = 2;
            else op = 1;
        }
    }
};

struct Info {
    int l = 1e9 + 1;
    int r = -1;
    int c0 = 0;
    int c1 = 0;
    void apply(Tag t) {
        if (t.op == 0) return;
        else if (t.op == 1) {
            int len = (r - l + 1);
            c0 = len / 2;
            c1 = len / 2;
            if (l & 1) c1 += len % 2;
            else c0 += len % 2; 
            // cerr << l << " " << r << " " << c0 << " " << c1 << "\n";
        } else if (t.op == 2) {
            c0 = c1 = 0;
        } else {
            int len = (r - l + 1);
            int d0 = len / 2;
            int d1 = len / 2;
            if (l & 1) d1 += len % 2;
            else d0 += len % 2; 
            c0 = d0 - c0;
            c1 = d1 - c1;
        }
    }
};

Info operator+(const Info &a, const Info &b) {
    // cerr << a.l << " " << a.r << " " << a.c0 << " ";
    // cerr << b.l << " " << b.r << " " << b.c0 << "\n";
    int l = min(a.l, b.l);
    int r = max(a.r, b.r);
    int c0 = a.c0 + b.c0;
    int c1 = a.c1 + b.c1;
    return {l, r, c0, c1};
}

using S = SegmentTree<Info, Tag>;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<array<int, 3>> ask(q);
    vector<int> p(q * 4);
    for (int i = 0; i < q; i++) {
        cin >> ask[i][0] >> ask[i][1] >> ask[i][2];
        p[i * 4] = ask[i][2];
        p[i * 4 + 1] = ask[i][2] + 1;
        p[i * 4 + 2] = ask[i][1];
        p[i * 4 + 3] = ask[i][1] + 1;
    }    


    p.push_back(1);
    p.push_back(n + 1);
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    int N = p.size();

    S t(N - 1);
    map<int, int> ref;
    for (int i = 0; i < N; i++) {
        ref[p[i]] = i;
    }

    for (int i = 0; i < N - 1; i++) {
        int l = p[i];
        int r = p[i + 1] - 1;

        t.set(i, {l, r, 0, 0});
    }

    for (int i = 0; i < q; i++) {
        int op = ask[i][0];
        int l = ref[ask[i][1]];
        int r = ref[ask[i][2]] + 1;

        if (op == 1) {
            t.update(l, r, {1});
        } else if (op == 2) {
            t.update(l, r, {3});
        } else {
            int c0 = t.query(l, r).c0;
            int c1 = t.query(l, r).c1;
            // cerr << c0 << " " << c1 << "\n";
            int len = ask[i][2] - ask[i][1] + 1;
            int d0 = len / 2;
            int d1 = len / 2;
            if (len & 1) {
                if (ask[i][1] & 1) d1++;
                else d0++;
            }

            int ans = min(d0 - c0 + c1, d1 - c1 + c0);
            cout << ans << "\n";
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}   