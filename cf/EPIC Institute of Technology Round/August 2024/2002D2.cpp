#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template<class T>
struct SegmentTree {
    static int n;
    vector<T> a, tr1, tr2, mark;
    SegmentTree(int x) {
        n = x;
        a.resize(x + 1);
        tr1.resize((x + 1) << 2);
        tr2.resize((x + 1) << 2);
        mark.resize((x + 1) << 2);
    }

    void set(int i, T x) {
        a[i] = x;
    }
    void build(int p = 1, int l = 1, int r = n) {
        if (l == r) {
            tr1[p] = a[l];
            tr2[p] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        tr1[p] = min(tr1[p << 1], tr1[p << 1 | 1]);
        tr2[p] = max(tr2[p << 1], tr2[p << 1 | 1]);
    }
    void push_down(int p, int l, int r) {
        return;
    }
    void update(int l, int r, T x, int p = 1, int cl = 1, int cr = n) {
        if (cl >= l && cr <= r) {
            tr1[p] = tr2[p] = x;
            return;
        }
        if (mark[p]) push_down(p, cl, cr);
        int mid = (cl + cr) / 2;
        if (l <= mid) update(l, r, x, p << 1, cl, mid);
        if (r > mid) update(l, r, x, p << 1 | 1, mid + 1, cr);
        tr1[p] = min(tr1[p << 1], tr1[p << 1 | 1]);
        tr2[p] = max(tr2[p << 1], tr2[p << 1 | 1]);
        return;
    }
    T query1(int l, int r, int p = 1, int cl = 1, int cr = n) {
        if (cl >= l && cr <= r) {
            return tr1[p];
        }
        if (mark[p]) push_down(p, cl, cr);
        int mid = (cl + cr) / 2;
        T ans = n;
        if (l <= mid) {
            ans = min(ans, query1(l, r, p << 1, cl, mid));
        }
        if (r > mid) {
            ans = min(ans, query1(l, r, p << 1 | 1, mid + 1, cr));
        }
        return ans;
    }
    T query2(int l, int r, int p = 1, int cl = 1, int cr = n) {
        if (cl >= l && cr <= r) {
            return tr2[p];
        }
        if (mark[p]) push_down(p, cl, cr);
        int mid = (cl + cr) / 2;
        T ans = 0;
        if (l <= mid) {
            ans = max(ans, query2(l, r, p << 1, cl, mid));
        }
        if (r > mid) {
            ans = max(ans, query2(l, r, p << 1 | 1, mid + 1, cr));
        }
        return ans;
    }
};

template<class T>
int SegmentTree<T>::n = 0;

using S = SegmentTree<ll>;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> fa(n + 1, -1);
    for (int i = 2; i <= n; i++) cin >> fa[i];
    vector<vector<int>> e(n + 1);
    for (int i = 2; i <= n; i++) {
        e[fa[i]].push_back(i);
    }
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];
    vector<int> sz(n + 1, 1);
    vector<int> dfn(n + 1);
    vector<int> last(n + 1);
    int tot = 0;
    auto dfs = [&](auto &&self, int x) -> int {
        dfn[x] = ++tot;
        int l = tot;
        for (int nxt : e[x]) {
            if (nxt == fa[x]) continue;
            l = max(l, self(self, nxt));
            sz[x] += sz[nxt];
        }
        last[x] = l;
        return l;
    };

    dfs(dfs, 1);

    S t(n);
    for (int i = 1; i <= n; i++) {
        t.a[i] = dfn[p[i]];
    }
    t.build();
    vector<int> ok(n + 1);

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int s = sz[p[i]];
        int l = i, r = min(n, i + s - 1);
        int mi = t.query1(l, r);
        int mx = t.query2(l, r);
        if (mi == dfn[p[i]] && mx == last[p[i]] && i + s - 1<= n) {
            ok[p[i]] = 1;
            cnt++;
        }
    }

    auto dfs2 = [&](auto &&self, int x) -> int {
        int res = 1;
        for (int nxt : e[x]) {
            res &= self(self, nxt);
        }
        if (res) return ok[x];
        else {
            if (ok[x] == 0) {
                ok[x] = 1;
                cnt++;
            }
            return 0;
        }
    };
    dfs2(dfs2, 1);
    vector<int> re(n + 1);
    for (int i = 1; i <= n; i++) {
        re[p[i]] = i;
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        t.update(x, x, dfn[p[y]]);
        t.update(y, y, dfn[p[x]]);
        swap(p[x], p[y]);
        swap(re[p[x]], re[p[y]]);
        int c = 2;
        while (c--) {
            int s = sz[p[x]];
            int l = x, r = min(n, x + s - 1);
            int mi = t.query1(l, r);
            int mx = t.query2(l, r);
            if (mi == dfn[p[x]] && mx == last[p[x]] && x + s - 1<= n) {
                if (!ok[p[x]]) {
                    ok[p[x]] = 1;
                    cnt++;
                }
            } else {
                if (ok[p[x]]) {
                    ok[p[x]] = 0;
                    cnt--;
                }
            }
            if (fa[p[x]] == -1) break;
            x = re[fa[p[x]]];
        }
        x = y;
        c = 2;
        while (c--) {
            int s = sz[p[x]];
            int l = x, r = min(n, x + s - 1);
            int mi = t.query1(l, r);
            int mx = t.query2(l, r);
            if (mi == dfn[p[x]] && mx == last[p[x]] && x + s - 1<= n) {
                if (!ok[p[x]]) {
                    ok[p[x]] = 1;
                    cnt++;
                }
            } else {
                if (ok[p[x]]) {
                    ok[p[x]] = 0;
                    cnt--;
                }
            }
            if (fa[p[x]] == -1) break;
            x = re[fa[p[x]]];
        }
        if (cnt == n) cout << "YES\n";
        else cout << "NO\n";
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