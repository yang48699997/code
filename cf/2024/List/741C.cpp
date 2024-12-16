#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> v(2 * n), ans(2 * n);
    vector<vector<int>> e(2 * n);
    vector<array<int, 2>> p;

    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        e[u].push_back(v);
        e[v].push_back(u);
        e[i * 2].push_back(i * 2 + 1);
        e[i * 2 + 1].push_back(i * 2);
        p.push_back({u, v});
    }

    auto dfs = [&](auto &&self, int x, int val) -> void {
        ans[x] = val + 1;
        v[x] = 1;
        for (int nxt : e[x]) {
            if (v[nxt]) continue;
            self(self, nxt, val ^ 1);
        }
    };

    for (int i = 0; i < n * 2; i++) {
        if (!v[i]) dfs(dfs, i, 0);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[p[i][0]] << " " << ans[p[i][1]] << "\n";
    } 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}