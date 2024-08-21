#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    vector<vector<int>> res(n, vector<int>(m));
    int ok = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int p = b[i][j] - a[i][j] + 3;
            p %= 3;
            res[i][j] = p;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (res[i][j] == 0) continue;
            else if (res[i][j] == 1) {
                if (i == n - 1 || j == m - 1) {
                    cout << "NO\n";
                    return;
                }
                res[i + 1][j] -= 2;
                if (res[i + 1][j] < 0) res[i + 1][j] += 3;
                res[i + 1][j + 1] -= 1;
                if (res[i + 1][j + 1] < 0) res[i + 1][j + 1] += 3;
                res[i][j + 1] -= 2;
                if (res[i][j + 1] < 0) res[i][j + 1] += 3;
            } else {
                if (i == n - 1 || j == m - 1) {
                    cout << "NO\n";
                    return;
                }
                res[i + 1][j] -= 1;
                if (res[i + 1][j] < 0) res[i + 1][j] += 3;
                res[i + 1][j + 1] -= 2;
                if (res[i + 1][j + 1] < 0) res[i + 1][j + 1] += 3;
                res[i][j + 1] -= 1;
                if (res[i][j + 1] < 0) res[i][j + 1] += 3;
            }
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}