#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    ll c;
    cin >> c;
    vector<vector<ll>> dp(2, vector<ll> (n));
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> e(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    auto dfs = [&](auto &&self, int x, int fa) -> void {
        dp[1][x] = a[x];
        for (int nxt : e[x]) {
            if (nxt == fa) continue;
            self(self, nxt, x);
            dp[0][x] += max(dp[0][nxt], dp[1][nxt]);
            dp[1][x] = max(dp[1][x] + dp[0][nxt], dp[1][x] + dp[1][nxt] - 2 * c);
        }
    };

    dfs(dfs, 0, -1);

    cout << max(dp[0][0], dp[1][0]) << "\n";
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