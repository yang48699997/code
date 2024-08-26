#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    int ans = 0;

    auto cal = [&](int p) -> int {
        vector<int> sum(m);
        for (int i = 0; i < n; i++) {
            if (1 << i & p) continue;
            for (int j = 0; j < m; j++) {
                sum[j] += g[i][j];
            }
        }
        sort(sum.rbegin(), sum.rend());
        int cnt = k - __builtin_popcount(p);
        int res = 0;
        for (int i = 0; i < min(cnt, m); i++) res += sum[i];
        return res;
    };

    for (int i = 0; i < 1 << n; i++) {
        if (__builtin_popcount(i) > k) continue;
        int res = cal(i);
        for (int j = 0; j < n; j++) {
            if (1 << j & i) {
                res += accumulate(g[j].begin(), g[j].end(), 0);
            }
        }
        ans = max(ans, res);
    }
    cout << ans << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}