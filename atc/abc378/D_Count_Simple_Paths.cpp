#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int ans = 0;

    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    auto dfs = [&](auto &&self, int x, int y, int p) -> void {
        if (x < 0 || x >= n || y < 0 || y >= m) return;
        if (s[x][y] == '#') return;
        if (p == k) {
            ans++;
            return;
        }
        s[x][y] = '#';

        for (int i = 0; i < 4; i++) {
            self(self, x + dir[i][0], y + dir[i][1], p + 1);
        }

        s[x][y] = '.';
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dfs(dfs, i, j, 0);
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}