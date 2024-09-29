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

    int ans = n - 1;
    vector<int> d(n), dmx(n);
    vector<int> cnt(n), cnt2(n);
    auto dfs = [&](auto &&self, int x, int fa) -> void {
        for (int nxt : e[x]) {
            if (nxt == fa) continue;
            d[nxt] = d[x] + 1;
            dmx[nxt] = d[nxt];
            self(self, nxt, x);
            dmx[x] = max(dmx[nxt], dmx[x]);
        }
        cnt[d[x]]++;
        cnt2[dmx[x]]++;
    };
    dfs(dfs, 0, -1);

    int now = n - 1;
    for (int i = 1; i < n; i++) {
        now -= cnt[i];
        now += cnt2[i - 1];
        ans = min(ans, now);
    }
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