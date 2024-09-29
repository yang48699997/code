#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int l, n, m;
    cin >> l >> n >> m;
    vector<int> a(l);
    for (int i = 0; i < l; i++) cin >> a[i];
    vector<vector<int>> g(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    vector<vector<int>> ok(n + 1, vector<int> (m + 1));
    vector<vector<int>> dp(n + 1, vector<int> (m + 1));
    for (int k = l - 1; k >= 0; k--) {
        if (k == l - 1) {
            for (int i = n - 1; i >= 0; i--) {
                for (int j = m - 1; j >= 0; j--) {
                    if (g[i][j] == a[k]) ok[i][j] = 1;
                    dp[i][j] = dp[i + 1][j] + dp[i][j + 1] - dp[i + 1][j + 1] + ok[i][j];
                }
            }
        } else {
            for (int i = n - 1; i >= 0; i--) {
                for (int j = m - 1; j >= 0; j--) {
                    if (g[i][j] != a[k]) ok[i][j] = 0;
                    else {
                        if (i == n - 1 || j == m - 1 || dp[i + 1][j + 1] == 0) ok[i][j] = 1;
                    }
                }
            }
            for (int i = n - 1; i >= 0; i--) {
                for (int j = m - 1; j >= 0; j--) {
                    dp[i][j] = dp[i + 1][j] + dp[i][j + 1] - dp[i + 1][j + 1] + ok[i][j];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ok[i][j]) {
                cout << "T\n";
                return;
            }
        }
    }
    cout << "N\n";
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