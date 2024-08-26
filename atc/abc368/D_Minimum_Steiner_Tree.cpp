#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> e(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    vector<int> p(k);
    vector<int> v(n);
    for (int i = 0; i < k; i++) {
        cin >> p[i];
        p[i]--;
        v[p[i]] = 1;
    }

    auto dfs = [&](auto &&self, int x, int fa) -> int {
        int res = 0;
        int ok = v[x];
        for (int nxt : e[x]) {
            if (nxt == fa) continue;
            int p = self(self, nxt, x);
            if (p) ok |= 1;
            res += p;
        }
        res += ok;
        return res;
    };

    int ans = dfs(dfs, p[0], -1);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}