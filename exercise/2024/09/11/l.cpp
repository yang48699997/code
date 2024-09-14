#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> e(n);
    vector<int> op(n);
    vector<int> ok(n);
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        while (c--) {
            int x;
            cin >> x;
            x--;
            e[i].push_back(x);
        }
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        v--;
        op[v] = 1;
    }
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        x--;
        ok[x] = 1;
    }

    const int inf = 1e9;
    vector<int> p(n);
    auto dfs = [&](auto &&self, int x) -> int {
        if (ok[x]) return 0;
        p[x] = inf;
        int cnt = 0;
        if (e[x].size() == 0) return p[x];
        for (int nxt : e[x]) {
            if (e[x].size() == 1) op[nxt] = 1;
            p[nxt] = self(self, nxt);
            if (p[nxt] != inf) {
                cnt++;
            }
        }
        if (cnt == e[x].size()) {
            p[x] = 0;
            for (int nxt : e[x]) {
                p[x] += p[nxt];
            }
        }
        for (int nxt : e[x]) {
            if (op[nxt]) {
                p[x] = min(p[x], p[nxt] + 1);
            }
        }
        return p[x];
    };
    int ans = dfs(dfs, 0);
    cout << (ans == inf ? -1 : ans) << "\n";
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