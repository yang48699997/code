#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> e(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    int root;
    cin >> root >> root;
    root--;

    vector<int> d(n);
    vector<int> v(n);
    d[root] = 0;
    v[root] = 1;
    vector<vector<int>> p(n);
    vector<int> point;
    auto dfs = [&](auto &&self, int x, int fa) -> void {
        for (int nxt : e[x]) {
            if (nxt == fa) continue;
            d[nxt] = d[x] + 1;
            self(self, nxt, x);
            v[x] |= v[nxt];
            p[x].push_back(d[nxt]);
        }
        if (v[x]) point.push_back(x);
        sort(p[x].begin(), p[x].end());
        if (p[x].size()) d[x] = p[x].back();
    };
    dfs(dfs, 0, -1);

    vector<int> dep(n);
    reverse(point.begin(), point.end());
    auto find = [&](auto &&self, int x, int fa) -> int {
        int mx = 0;
        for (int nxt : e[x]) {
            if (nxt == fa || v[nxt]) continue;
            mx = max(self(self, nxt, x) + 1, mx);
        }
        dep[x] = mx;
        return mx;
    };
    for (int i : point) {
        find(find, i, -1);
    }

    int ok = 0;
    auto check = [&](auto &&self, vector<int> point) -> void {
        int m = point.size();
        if (m == 1) {
            ok = 1;
            return;
        } else if (m == 2) {
            if (dep[point[0]] > dep[point[1]]) ok = 1;
            return;
        }
        int l = (m + 1) / 2;
        int r = m - l;
        vector<int> pre(m + 1);
        for (int i = 1; i <= m; i++) {
            pre[i] = max(pre[i - 1], i + dep[point[m - i]] - 1);
        }
        int mx = 0;
        int ddl = -1;
        for (int i = 0; i < m - 1; i++) {
            mx = max(dep[point[i]] + i, mx);
            if (mx > pre[m - i - 1]) {
                ddl = i + 1;
                break;
            }
        }
        if (ddl != -1 && ddl <= l) {
            ok = 1;
            return;
        }
        if (ddl != -1) {
            vector<int> point2;
            int pp = m - ddl + 1;
            for (int i = 0; i < pp; i++) {
                point.pop_back();
            }
            for (int i = pp; i < point.size(); i++) {
                point2.push_back(point[i]);
            }
            self(self, point2);
        }

    };

    check(check, point);
    if (ok) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
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