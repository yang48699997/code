#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll inf = 1e18;

void solve() {
    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<vector<ll>> g(n, vector<ll> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    vector<ll> dp(m, inf);
    dp[0] = 0; 

    for (int i = 0; i < n; i++) {
        vector<ll> res(m, inf);
        for (int p = 0; p < m; p++) {
            vector<ll> tmp(m, inf);
            for (int j = 0; j < m; j++) {
                tmp[j] = min(tmp[j], dp[j] + g[i][(j + p) % m] + p * k);
                if (j > 0) tmp[j] = min(tmp[j], tmp[j - 1] + g[i][(j + p) % m]);
                res[j] = min(res[j], tmp[j]);
            }
        }
        dp = res;
    }

    cout << dp[m - 1] << "\n";
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