#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T>
struct SegmentTree {
    static int n;
    vector<T> a, tr, mark, mi, mx, mark2;
    SegmentTree(int x) {
        n = x;
        a.resize(x + 1);
        tr.resize((x + 1) << 2);
        mark.resize((x + 1) << 2);
        mark2.resize((x + 1) << 2, 1);
        mi.resize((x + 1) << 2);
        mx.resize((x + 1) << 2);
    }
    SegmentTree() {}
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
        tr[p << 1] *= mark2[p];
        mark2[p << 1] *= mark2[p];
        tr[p << 1] += (len + 1) / 2 * mark[p];
        mi[p << 1] *= mark2[p];
        mark[p << 1] *= mark2[p];
        mark[p << 1] += mark[p];
        mi[p << 1] *= mark2[p];
        mi[p << 1] += mark[p];
        mx[p << 1] *= mark2[p];
        mx[p << 1] += mark[p];
        tr[p << 1 | 1] *= mark2[p];
        mark2[p << 1 | 1] *= mark2[p];
        tr[p << 1 | 1] += len / 2 * mark[p];
        mark[p << 1 | 1] *= mark2[p];
        mark[p << 1 | 1] += mark[p];
        mi[p << 1 | 1] *= mark2[p];
        mi[p << 1 | 1] += mark[p];
        mx[p << 1 | 1] *= mark2[p];
        mx[p << 1 | 1] += mark[p];
        mark[p] = 0;
        mark2[p] = 1;
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
        if (mark[p] || mark2[p] != 1) push_down(p, cl, cr);
        int mid = (cl + cr) / 2;
        if (l <= mid) update(l, r, x, p << 1, cl, mid);
        if (r > mid) update(l, r, x, p << 1 | 1, mid + 1, cr);
        tr[p] = tr[p << 1] + tr[p << 1 | 1];
        mi[p] = min(mi[p << 1], mi[p << 1 | 1]);
        mx[p] = max(mx[p << 1], mx[p << 1 | 1]);
        return;
    }
    void update2(int l, int r, T x, int p = 1, int cl = 1, int cr = n) {
        if (cl >= l && cr <= r) {
            int len = cr - cl + 1;
            tr[p] = tr[p] * x;
            mark[p] *= x;
            mark2[p] *= x;
            mi[p] *= x;
            mx[p] *= x;
            return;
        }
        if (mark[p] || mark2[p] != 1) push_down(p, cl, cr);
        int mid = (cl + cr) / 2;
        if (l <= mid) update2(l, r, x, p << 1, cl, mid);
        if (r > mid) update2(l, r, x, p << 1 | 1, mid + 1, cr);
        tr[p] = tr[p << 1] + tr[p << 1 | 1];
        mi[p] = min(mi[p << 1], mi[p << 1 | 1]);
        mx[p] = max(mx[p << 1], mx[p << 1 | 1]);
        return;
    }
    T query(int l, int r, int p = 1, int cl = 1, int cr = n) {
        if (cl >= l && cr <= r) {
            return tr[p];
        }
        if (mark[p] || mark2[p] != 1) push_down(p, cl, cr);
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

template<class T, class S>
struct Tree{
    vector<vector<T>> e;
    vector<int> dep, siz, son, top, parent, dfn, ref, out;
    vector<T> val;
    int n, root, tot;
    S sgt;
    Tree(int n_) : n(n_), root(1), e(n_ + 1), dep(n_ + 1), siz(n_ + 1), son(n_ + 1), top(n_ + 1), parent(n_ + 1), dfn(n_ + 1), out(n_ + 1), val(n_ + 1), sgt(n_), ref(n_ + 1) {}
    void build() {
        tot = 0;
        parent[root] = 0;
        dfs1(root);
        dfs2(root, root);
        sgt.build();
    }
    void add(int u, int v) {
        e[u].push_back(v);
        e[v].push_back(u);
    }
    void set(int x, T v) {
        val[x] = v;
    }
    void set_root(int x) {
        root = x;
    }
    void dfs1(int x) {
        siz[x] = 1;
        dep[x] = dep[parent[x]] + 1;
        for (auto nxt : e[x]) {
            if (nxt == parent[x]) continue;
            parent[nxt] = x;
            dfs1(nxt);
            siz[x] += siz[nxt];
            if (siz[nxt] > siz[son[x]]) {
                son[x] = nxt;
            }
        }
        return;
    }
    void dfs2(int x, int up) {
        top[x] = up;
        dfn[x] = ++tot;
        ref[tot] = x;
        sgt.set(dfn[x], val[x]);
        if (son[x]) dfs2(son[x], up);
        for (auto nxt : e[x]) {
            if (nxt == parent[x] || nxt == son[x]) continue;
            dfs2(nxt, nxt);
        }
        out[x] = tot;
        return;
    }
    int lca(int x, int y) {
        while (top[x] != top[y]) {
            if (dep[top[x]] > dep[top[y]]) {
                x = parent[top[x]];
            } else {
                y = parent[top[y]];
            }
        }
        return dep[x] < dep[y] ? x : y;
    }
    int dis(int x, int y) {
        return dep[x] + dep[y] - 2 * dep[lca(x, y)];
    }
    T query(int x, int y) {
        int L = lca(x, y);
        T res = 0;
        while (top[x] != top[y]) {
            if (dep[top[x]] > dep[top[y]]) {
                res += sgt.query(dfn[top[x]], dfn[x]);
                x = parent[top[x]];
            } else {
                res += sgt.query(dfn[top[y]], dfn[y]);
                y = parent[top[y]];
            }
        }
        if (dep[x] > dep[y]) swap(x, y);
        res += sgt.query(dfn[x], dfn[y]);
        return res;
    }
    T querySon(int x) {
        return sgt.query(dfn[x], out[x]);
    }
    void updateSon(int x, T v) {
        sgt.update(dfn[x], out[x], v);
    }
    T query_max(int x, int y) {
        T res = numeric_limits<T>::min();
        while (top[x] != top[y]) {
            if (dep[top[x]] > dep[top[y]]) {
                res = max(res, sgt.query_max(dfn[top[x]], dfn[x]));
                x = parent[top[x]];
            } else {
                res = max(res, sgt.query_max(dfn[top[y]], dfn[y]));
                y = parent[top[y]];
            }
        }
        if (dep[x] > dep[y]) swap(x, y);
        res = max(res, sgt.query_max(dfn[x], dfn[y]));
        return res;
    }
    T query_min(int x, int y) {
        T res = numeric_limits<T>::max();
        while (top[x] != top[y]) {
            if (dep[top[x]] > dep[top[y]]) {
                res = min(res, sgt.query_min(dfn[top[x]], dfn[x]));
                x = parent[top[x]];
            } else {
                res = min(res, sgt.query_min(dfn[top[y]], dfn[y]));
                y = parent[top[y]];
            }
        }
        if (dep[x] > dep[y]) swap(x, y);
        res = min(res, sgt.query_min(dfn[x], dfn[y]));
        return res;
    }
    void update(int x, T v) {
        sgt.update(dfn[x], dfn[x], v);
    }
    void update(int x, int y, T v) {
        while (top[x] != top[y]) {
            if (dep[top[x]] > dep[top[y]]) {
                sgt.update(dfn[top[x]], dfn[x], v);
                x = parent[top[x]];
            } else {
                sgt.update(dfn[top[y]], dfn[y], v);
                y = parent[top[y]];
            }
        }
        if (dep[x] > dep[y]) swap(x, y);
        sgt.update(dfn[x], dfn[y], v);
        return;
    }
    int diameter() {
        vector<int> d(n + 1);
        queue<int> q;
        d[1] = 1;
        int p = 1;
        q.push(1);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int nxt : e[x]) {
                if (d[nxt]) continue;
                d[nxt] = d[x] + 1;
                p = nxt;
                q.push(nxt);
            }
        }
        int res = 0;
        d.assign(n + 1, 0);
        d[p] = 1;
        q.push(p);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int nxt : e[x]) {
                if (d[nxt]) continue;
                d[nxt] = d[x] + 1;
                res = d[nxt] - 1;
                q.push(nxt);
            }
        }
        return res;
    }
    int k_anc(int x, int k) {
        while (k) {
            int p = top[x];
            if (dep[x] - dep[p] < k) {
                k -= dep[x] - dep[p] + 1;
                x = parent[top[x]];
            } else {
                return ref[dfn[x] - k];
            }
        }
        return x;
    }
    bool isSon(int fa, int x) {
        if (dfn[x] < dfn[fa] && dfn[x] < out[fa]) return true;
        return false;
    }
    vector<T> centroid() {
        vector<T> ans;
        queue<T> q;
        q.push_back(root);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            int mx = n - siz[x];
            for (int nxt : e[x]) {
                if (dep[nxt] < dep[x]) continue;
                mx = max(mx, siz[nxt]);
                q.push(nxt);
            }
            if (mx <= n / 2) ans.push_back(x);
        }
        return ans;
    } 
};

using T = Tree<ll, S>;

void solve() {
    int n, q;
    cin >> n >> q;
    T t(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        t.add(u, v);
    }    
    t.build();

    ll ans = 0;
    while (q--) {
        int u, v;
        cin >> u >> v;
        t.update(u, v, 1);
    }
    for (int i = 1; i <= n; i++) {
        ans = max(ans, t.query(i, i));
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}