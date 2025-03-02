#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m, h;
    cin >> n >> m >> h;
    h++;

    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    int sx = -1, sy = -1;
    int tx = -1, ty = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '*') {
                sx = i;
                sy = j;
            } else if (s[i][j] == '%') {
                tx = i;
                ty = j;
            }
        }
    }

    s[tx][ty] = '.';

    priority_queue<array<int, 4>> q;
    q.push({0, sx, sy, 1});
    const int inf = 1e9;
    vector<vector<int>> p(n, vector<int> (m, inf));
    vector<vector<int>> v(n, vector<int> (m));

    p[sx][sy] = 0;

    while (!q.empty()) {
        auto cur = q.top();
        q.pop();
        int x = cur[1], y = cur[2];
        int now = -cur[0];
        if (v[x][y] == 3) continue;
        else if (v[x][y] & (1 << cur[3])) continue;
        else if (x == tx && y == ty) {
            cout << now << "\n";
            return;
        }

        v[x][y] |= (1 << cur[3]);
        s[x][y] = '.';
        // cerr << x << " " << y << " " << now << " " << d[x][y] << "\n";

        if (x + 1 < n && s[x + 1][y] == '.') {
            if (now + 1 < p[x + 1][y]) {
                p[x + 1][y] = now + 1;
                q.push({-now - 1, x + 1, y, 1});
            } else if (!(v[x + 1][y] & 2)) {
                q.push({-now - 1, x + 1, y, 1});
            }
        } else if (cur[3]) {
            if (x + 1 < n && now + h < p[x + 1][y]) {
                p[x + 1][y] = now + h;
                q.push({-now - h, x + 1, y, 1});
            } else if (x + 1 < n && !(v[x + 1][y] & 2)) {
                q.push({-now - h, x + 1, y, 1});
            }
            if (x == n - 1) continue;
            if (y + 1 < m) {
                if (s[x][y + 1] == '.' && now + 1 < p[x][y + 1]) {
                    p[x][y + 1] = now + 1;
                    q.push({-now - 1, x, y + 1, 0});
                } else if (s[x][y + 1] == '.' && !(v[x][y + 1] & 1)) {
                    q.push({-now - 1, x, y + 1, 0});
                }
            }
            if (y - 1 >= 0) {
                if (s[x][y - 1] == '.' && now + 1 < p[x][y - 1]) {
                    p[x][y - 1] = now + 1;
                    q.push({-now - 1, x, y - 1, 0});
                } else if (s[x][y - 1] == '.' && !(v[x][y - 1] & 1)) {
                    q.push({-now - 1, x, y - 1, 0});
                }
            }
        } else {
            if (y + 1 < m) {
                if (s[x][y + 1] == '.' && now + 1 < p[x][y + 1]) {
                    p[x][y + 1] = now + 1;
                    q.push({-now - 1, x, y + 1, 0});
                } else if (s[x][y + 1] == '.' && !(v[x][y + 1] & 1)) {
                    q.push({-now - 1, x, y + 1, 0});
                }
            }
            if (y - 1 >= 0) {
                if (s[x][y - 1] == '.' && now + 1 < p[x][y - 1]) {
                    p[x][y - 1] = now + 1;
                    q.push({-now - 1, x, y - 1, 0});
                } else if (s[x][y - 1] == '.' && !(v[x][y - 1] & 1)) {
                    q.push({-now - 1, x, y - 1, 0});
                }
            }
        }
    }
    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}