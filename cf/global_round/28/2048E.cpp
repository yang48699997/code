#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    if (m >= n * 2) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    vector<vector<int>> ans(n * 2, vector<int>(n * 2));
    for (int i = 0; i < n * 2; i++) {
        ans[0][i] = i / 2 + 1;
    }
    for (int i = 1; i < n * 2; i++) {
        for (int j = 0; j < n * 2; j++) {
            ans[i][j] = ans[0][(i + j) % (n * 2)];
        }
    }

    for (int i = 0; i < n * 2; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " \n"[j == m - 1];
        }
    }
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