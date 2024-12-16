#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> deg(n);
    vector<vector<int>> e(n);

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

    ll ans = 0;

    auto dfs = [&](auto &&self, int x, int fa = -1) -> ll {
        ll cnt = 0;
        int ok = 0;
        if (deg[x] == 3) ok = 1;
        else if (deg[x] == 2) cnt++;

        for (int nxt : e[x]) {
            if (nxt == fa) continue;
            ll res = self(self, nxt, x);
            ans += cnt * res * ok;
            cnt += res * ok;
            if (deg[x] == 2) ans += res;
            if (deg[nxt] == 2 && deg[x] == 2) ans--; 
        }

        return cnt;
    };

    dfs(dfs, 0);

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}