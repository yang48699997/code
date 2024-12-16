#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m, q;
    cin >> n >> q;
    m = n;

    vector<vector<ll>> g(n + 1, vector<ll> (m + 1));
    vector<vector<ll>> pre(n + 1, vector<ll> (m + 1));
    vector<vector<ll>> row(n + 1, vector<ll> (m + 1));
    vector<vector<ll>> col(n + 1, vector<ll> (m + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] + g[i][j] - pre[i - 1][j - 1];
            row[i][j] = row[i - 1][j] + row[i][j - 1] + g[i][j] * i - row[i - 1][j - 1];
            col[i][j] = col[i - 1][j] + col[i][j - 1] + g[i][j] * j - col[i - 1][j - 1];
        }
    }

    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        ll p_sum = pre[x2][y2] + pre[x1 - 1][y1 - 1] - pre[x1 - 1][y2] - pre[x2][y1 - 1];
        ll c_sum = col[x2][y2] + col[x1 - 1][y1 - 1] - col[x1 - 1][y2] - col[x2][y1 - 1];
        ll r_sum = row[x2][y2] + row[x1 - 1][y1 - 1] - row[x1 - 1][y2] - row[x2][y1 - 1];

        ll ans = c_sum - p_sum * (y1 - 1) + (r_sum - p_sum * x1) * (y2 - y1 + 1); 

        cout << ans << " \n"[q == 0];
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