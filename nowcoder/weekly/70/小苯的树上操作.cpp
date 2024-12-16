#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<vector<int>> e(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    ll ans = 0;

    auto dfs = [&](auto &&self, int x, int fa) -> ll {
        ll res = a[x];

        array<ll, 2> mx = array<ll, 2> ();

        for (int nxt : e[x]) {
            if (nxt == fa) continue;
            ll p = self(self, nxt, x);
            res += p;

            if (p > mx[1]) {
                mx[1] = p;
            }
            if (mx[1] > mx[0]) {
                swap(mx[1], mx[0]);
            }
        }

        ans = max({ans, res, mx[0] + mx[1] + a[x], mx[0] + mx[1], mx[0]});
        res = max(res, mx[0]);

        return res;
    };

    dfs(dfs, 0, -1);

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}