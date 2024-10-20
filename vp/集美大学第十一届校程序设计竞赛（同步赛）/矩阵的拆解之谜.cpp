#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }

    vector<vector<int>> ans(n, vector<int> (n));
    vector<vector<int>> ans2(n, vector<int> (n));
    for (int i = 0; i < n; i++) {
        ans[i][i] = g[i][i];
        for (int j = i + 1; j < n; j++) {
            int x = g[i][j];
            int y = g[j][i];
            if ((x + y) & 1) {
                cout << "NO\n";
                return;
            }
            ans[i][j] = ans[j][i] = (x + y) / 2;
            ans2[i][j] = g[i][j] - ans[i][j];
            ans2[j][i] = -ans2[i][j];
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " \n"[j == n - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans2[i][j] << " \n"[j == n - 1];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}