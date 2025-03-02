#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    vector<vector<int>> dp(n, vector<int> (m + 1));
    vector<vector<int>> na(n, vector<int> (1 << m));

    for (int i = 0; i < n; i++) {
        na[i][0] = a[i];
        for (int j = 1; j < 1 << m; j++) {
            int k = __lg(j & -j);
            int c = __builtin_popcount(j);
            na[i][j] = (na[i][j - (1 << k)] & b[k]);
            dp[i][c] = max(dp[i][c], a[i] - na[i][j]);
        }
        for (int j = m; j > 0; j--) {
            dp[i][j] -= dp[i][j - 1];
        }
    }

    ll ans = accumulate(a.begin(), a.end(), 0LL);

    priority_queue<array<int, 3>> q;
    for (int i = 0; i < n; i++) {
        q.push({dp[i][1], 1, i});
    }

    while (k--) {
        auto [x, p, i] = q.top();
        q.pop();

        ans -= x;
        if (p == m) continue;
        q.push({dp[i][p + 1], p + 1, i});
    }

    cout << ans << "\n";
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