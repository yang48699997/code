#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> e(n, vector<int> (n, inf));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        int c;
        cin >> c;
        e[u][v] = e[v][u] = min(e[u][v], c);
    }    

    vector<vector<int>> dp(1 << n, vector<int> (n, inf));
    vector<vector<int>> f(1 << n, vector<int> (n, inf));
    for (int i = 0; i < n; i++) {
        dp[1 << i][i] = 0;
    }

    for (int i = 1; i < 1 << n; i++) {
        for (int j = 0; j < n; j++) {
            if (1 << j & i) {
                int mask = i ^ 1 << j;
                for (int p = mask; p; p = (p - 1) & mask) {
                    dp[i][j] = min(dp[i][j], dp[i ^ p][j] + f[p][j]);
                }
            }
        }
        for (int j = 0; j < n; j++) {
            if (1 << j & i) {
                for (int k = 0; k < n; k++) {
                    if (1 << k & i) continue;
                    if (e[j][k] == inf) continue;
                    f[i][k] = min(f[i][k], dp[i][j] + e[j][k] * __builtin_popcount(i) * (n - __builtin_popcount(i)));
                }
            }
        }
    }

    int ans = inf;
    for (int i = 0; i < n; i++) {
        ans = min(ans, dp[(1 << n) - 1][i]);
    }
    cout << (ans == inf ? -1 : ans) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}