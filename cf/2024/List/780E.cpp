#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> te(n);
    vector<int> vis(1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        te[u].push_back(v);
        te[v].push_back(u);
    }

    vector<int> v(n);
    auto dfs1 = [&](auto &&self, int x) -> void {
        for (int nxt : te[x]) {
            if (v[nxt]) continue;
            vis.push_back(nxt);
            v[nxt] = 1;
            self(self, nxt);
            vis.push_back(x);
        }
    };

    v[0] = 1;
    dfs1(dfs1, 0);

    int p = (2 * n - 2) / k + 1;
    int l = 0;
    for (int i = 0; i < k; i++) {
        int m = min((int)vis.size() - l, p);
        cout << m << " ";
        for (int j = 0; j < m; j++) {
            cout << vis[j + l] + 1 << " \n"[j == m - 1];
        }
        l = min((int)vis.size() - 1, l + m);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}