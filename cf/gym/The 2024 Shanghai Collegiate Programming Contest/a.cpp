#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> cnt(n + 1, vector<int> (m + 1));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int ii = 0; ii <= n; ii++) {
                for (int jj = 0; jj <= m; jj++) {
                    if (i > ii) continue;
                    if (i == ii && jj <= j) continue;
                    int x = ii - i + jj - j;
                    if (x & 1) continue;
                    x /= 2;
                    int y = ii - i - x;
                    int tx1 = j + x;
                    int ty1 = i + y;
                    if (tx1 < 0 || tx1 > m || ty1 < 0 || ty1 > n) continue;
                    int tx2 = j - y;
                    int ty2 = i + x;
                    if (tx2 < 0 || tx2 > m || ty2 < 0 || ty2 > n) continue;
                    cnt[i][j]++;
                    cnt[ii][jj]++;
                    cnt[ty1][tx1]++;
                    cnt[ty2][tx2]++;
                }
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << cnt[i][j] / 2 << " \n"[j == m];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}