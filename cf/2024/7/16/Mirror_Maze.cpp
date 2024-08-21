#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int>(4, -1)));
    vector<vector<vector<int>>> v(n, vector<vector<int>> (m, vector<int>(4)));
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    map<string,int> mp{{"above", 0}, {"below", 1}, {"left", 2}, {"right", 3}};
    auto dfs = [&](auto &&self, int x, int y, int dir, int cnt) -> int {
        if (x < 0 || x >= n || y < 0 || y >= m) return cnt;
        if (v[x][y][dir]) {
            return cnt;
        }
        v[x][y][dir] = 1;
        if (s[x][y] == '-') {
            if (dir == 1) {
                dp[x][y][dir] = self(self, x - 1, y, 0, cnt + 1);
            } else if (dir == 0) {
                dp[x][y][dir] = self(self, x + 1, y, 1, cnt + 1);
            } else if (dir == 2) {
                dp[x][y][dir] = self(self, x, y - 1, dir, cnt);
            } else {
                dp[x][y][dir] = self(self, x, y + 1, dir, cnt);
            }
        } else if (s[x][y] == '|') {
            if (dir == 0) {
                dp[x][y][dir] = self(self, x + 1, y, dir, cnt);
            } else if (dir == 1) {
                dp[x][y][dir] = self(self, x - 1, y, dir, cnt);
            } else if (dir == 2) {
                dp[x][y][dir] = self(self, x, y + 1, 3, cnt + 1);
            } else {
                dp[x][y][dir] = self(self, x, y - 1, 2, cnt + 1);
            }
        } else if (s[x][y] == '/') {
            if (dir == 0) {
                dp[x][y][dir] = self(self, x, y + 1, 3, cnt + 1);
            } else if (dir == 1) {
                dp[x][y][dir] = self(self, x, y - 1, 2, cnt + 1);
            } else if (dir == 2) {
                dp[x][y][dir] = self(self, x + 1, y, 1, cnt + 1);
            } else {
                dp[x][y][dir] = self(self, x - 1, y, 0, cnt + 1);
            }
        } else {
            if (dir == 0) {
                dp[x][y][dir] = self(self, x, y - 1, 2, cnt + 1);
            } else if (dir == 1) {
                dp[x][y][dir] = self(self, x, y + 1, 3, cnt + 1);
            } else if (dir == 2) {
                dp[x][y][dir] = self(self, x - 1, y, 0, cnt + 1);
            } else {
                dp[x][y][dir] = self(self, x + 1, y, 1, cnt + 1);
            }
        }
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                if (!v[i][j][k]) {
                    dfs(dfs, i, j, k, 0);
                }
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int i, j;
        cin >> i >> j;
        string str;
        cin >> str;
        i--;
        j--;
        int k = mp[str];
        int ans;
        if (k == 0) {
            ans = (i - 1 < 0) ? 0 :dp[i - 1][j][k];  
        } else if (k == 1) {
            ans = (i + 1 == n) ? 0 :dp[i + 1][j][k];
        } else if (k == 2) {
            ans = (j - 1 < 0) ? 0 :dp[i][j - 1][k];
        } else {
            ans = (j + 1 == m) ? 0 :dp[i][j + 1][k];
        }
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}