#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> e(n);
    vector<int> deg(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        e[u].push_back(v);
        e[v].push_back(u);

        deg[u]++;
        deg[v]++;
    }

    int ans = 0;
    int mx = 0;

    auto dfs = [&](auto &&self, int x, int fa = -1) -> int {
        int p = 0;
        ans = max(ans, deg[x] + mx - 1);

        for (int nxt : e[x]) {
            if (nxt == fa) continue;
            int y = self(self, nxt, x);
            ans = max({ans, deg[x] + deg[nxt] - 2, deg[x] + y - 1});
            mx = max(mx, deg[nxt]);
            p = max({p, deg[nxt], y});
        }
        return p;
    };

    dfs(dfs, 0);

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