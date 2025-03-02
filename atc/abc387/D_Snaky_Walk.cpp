#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int inf = 1e9;

void solve() {
    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    for (int i = 0; i < h; i++) cin >> s[i];

    vector<vector<int>> v1(h, vector<int> (w, inf));
    vector<vector<int>> v2(h, vector<int> (w, inf));

    queue<array<int, 2>> q1, q2;
    int tx, ty;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == 'S') {
                q1.push({i, j});
                q2.push({i, j});
                v1[i][j] = v2[i][j] = 0;
            } else if (s[i][j] == 'G') {
                tx = i;
                ty = j;
            }
        }
    }

    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    while (!q1.empty() || !q2.empty()) {
        queue<array<int, 2>> tq1, tq2;
        while (!q1.empty()) {
            auto [x, y] = q1.front();
            q1.pop();
            for (int i = 0; i < 4; i += 2) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];

                if (nx < 0 || nx >= h || ny < 0 || ny >= w || s[nx][ny] == '#' || v2[nx][ny] <= v1[x][y] + 1) continue;
                v2[nx][ny] = v1[x][y] + 1;
                tq2.push({nx, ny});
            }
        }
        while (!q2.empty()) {
            auto [x, y] = q2.front();
            q2.pop();
            for (int i = 1; i < 4; i += 2) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];

                if (nx < 0 || nx >= h || ny < 0 || ny >= w || s[nx][ny] == '#' || v1[nx][ny] <= v2[x][y] + 1) continue;
                v1[nx][ny] = v2[x][y] + 1;
                tq1.push({nx, ny});
            }
        }
        q1 = tq1;
        q2 = tq2;
    }
    
    int ans = min(v1[tx][ty], v2[tx][ty]);  

    cout << (ans == inf ? -1 : ans) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}