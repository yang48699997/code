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

    vector<int> ans(n);

    int now = 1;
    auto dfs = [&](auto &&self, int x, int fa) -> void {
        ans[x] = now++;
        for (int nxt : e[x]) {
            if (nxt == fa) continue;
            if (now - ans[x] == 1) {
                self(self, nxt, x);
            } else {
                while (now - ans[x] == 2 || (now - ans[x]) & 1) now++;
                self(self, nxt, x);
            }
        }
    }; 

    for (int i = 0; i < n; i++) {
        if (deg[i] == 1) {
            dfs(dfs, i, -1);
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
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