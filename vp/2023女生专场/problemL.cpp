#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m, K;
    cin >> n >> m >> K;
    vector<int> p(n);
    vector<vector<ll>> q(m, vector<ll> (7));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 7; j++) {
            cin >> q[i][j];
        }
        q[i][0]--;
        q[i][1]--;
    }
    ll ans = 0;

    auto dfs = [&](auto &&self, int now) -> void {
        if (now == n) {
            ll res = 0;
            for (int i = 0; i < m; i++) {
                ll o = q[i][3] * p[q[i][0]] + q[i][4] * p[q[i][1]];
                int ok = 0;
                if (q[i][2] == 1) {
                    if (o >= q[i][5]) ok = 1;
                } else {
                    if (o <= q[i][5]) ok = 1;
                }
                if (ok) res += q[i][6];
            }
            ans = max(ans, res);
            return;
        }
        for (int i = 0; i <= K; i++) {
            p[now] = i;
            self(self, now + 1);
        }
    };
    dfs(dfs, 0);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}