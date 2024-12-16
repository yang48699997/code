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

    int ans = 1;

    auto dfs = [&](auto &&self, int x, int fa) -> int {
        vector<int> p;
        int son = 0;

        for (int nxt : e[x]) {
            if (nxt == fa) continue;
            son++;
            p.push_back(self(self, nxt, x));
        }

        sort(p.rbegin(), p.rend());

        int res = 0;
        if (p.size() == 1) {
            res = max(1, p[0]);
            ans = max(ans, max(p[0], 1) + (x != 0));
        } else if (p.size() > 1) {
            ans = max(ans, max(p[0], 1) + max(p[1], 1) + son - 2 + (x != 0));
            ans = max(ans, max(p[0], 1) + son - 1 + (x != 0));
            res = son + max(1, p[0]) - 1;
        }

        return res;
    };

    dfs(dfs, 0, -1);

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