#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char> (m));
    vector<vector<int>> d(n, vector<int> (m, inf));
    int x, y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'E') {
                d[i][j] = 0;
                x = i;
                y = j;
            }
        }
    }

    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty()) {
        auto [p1, p2] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = p1 + dir[i][0];
            int ny = p2 + dir[i][1];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || g[nx][ny] == 'T' || d[nx][ny] != inf) continue;
            d[nx][ny] = d[p1][p2] + 1;
            q.push({nx, ny});
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'S') {
                x = i;
                y = j;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] >= '0' && g[i][j] <= '9' && d[i][j] <= d[x][y]) {
                ans += g[i][j] - '0';
            }
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