#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int> (m + 1));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int ii = i; ii <= n; ii++) {
                for (int jj = 0; jj <= m; jj++) {
                    if (ii == i && jj <= j) continue;
                    int x1 = i + ii + j -jj;
                    int y1 = j + ii -i + jj;
                    if (x1 & 1) continue;
                    if (y1 & 1) continue;
                    x1 /= 2;
                    y1 /= 2;
                    if (x1 < 0 || x1 > n || y1 < 0 || y1 > m) continue;
                    int x2 = i + ii - x1;
                    int y2 = j + jj - y1;
                    if (x2 < 0 || x2 > n || y2 < 0 || y2 > m) continue;
                    g[i][j]++;
                    g[ii][jj]++;
                }
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << g[i][j] << " \n"[j == m];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}