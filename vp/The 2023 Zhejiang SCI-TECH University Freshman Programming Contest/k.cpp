#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, char>>> p(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        p[x].emplace_back(y, c);
    }
    for (int i = 1; i <= n; i++) {
        sort(p[i].begin(), p[i].end());
    }
    vector<int> v(2 * n, 0);
    vector<int> vis(2 * n, 0);
    vector<int> point(2 * n, 0);
    v[n] = 1;
    for (int i = n - 1; i > 0; i--) {
        vector<int> vv;
        auto dfs = [&](auto &&self, int x, int pre) -> void {
            vv.push_back(x);
            vis[x] = 1;
            if (point[x] == 0) {
                return;
            } else if (x + point[x] == pre) {
                v[x] = 0;
                return;
            } else {
                int nxt = x + point[x];
                if (vis[nxt]) {
                    v[x] = v[nxt];
                    return;
                } else {
                    self(self, nxt, x);
                    v[x] = v[nxt];
                }
            }
        };
        point[i] = 1;
        point[2 * n - i] = -1;
        for (int j = 0; j < p[i].size(); j++) {
            if (p[i][j].second == 'R') point[p[i][j].first + i - 1] = 1;
            else point[p[i][j].first + i - 1] = -1;
        }
        dfs(dfs, i, -1);
        if (!vis[2 * n - i]) dfs(dfs, 2 * n - i, -1);
        for (int j = 0; j < p[i].size(); j++) {
            if (vis[p[i][j].first + i - 1]) continue;
            dfs(dfs, p[i][j].first + i - 1, -1);
        }
        for (int j : vv) {
            point[j] = 0;
            vis[j] = 0;
        }
    }
    for (int i = 1; i < 2 * n; i++) {
        cout << v[i];
    }      
    cout << "\n";
    
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