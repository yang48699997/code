#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 10;

ll dp[1 << N][N + 1];

void init() {
    for (int i = 0; i < 1 << N; i++) {
        for (int j = 0; j <= N; j++) {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1;
    for (int j = 1; j <= N; j++) {
        for (int i = 0; i < 1 << N; i++) {
            for (int k = 0; k < 10; k++) {
                dp[i | (1 << k)][j] += dp[i][j - 1];
            }
        }
    }
    
}

void solve() {
    ll x, k;
    cin >> x >> k;

    ll l = x - 1, r = x + k;
    string L = to_string(l);
    string R = to_string(r);

    auto dfs = [&](auto &&self, string &s, int limited, int mex, int mask, int pos, int zero = 1) -> ll {
        int p = (1 << mex) - 1;
        int n = s.size();

        if (pos == n) {
            return ((mask & p) == p);
        }

        if (!limited && !zero) {
            ll res = 0;
            for (int i = 0; i < 1 << N; i++) {
                if (((mask | i) & p) == p) res += dp[i][n - pos];
            }
            return res;
        }

        int mx = s[pos] - '0';
        if (!limited) mx = 9;

        ll res = 0;
        for (int j = 0; j <= mx; j++) {
            int nxt = mask;
            if (!zero || j) nxt = (mask | 1 << j);
            res += self(self, s, limited && (j == s[pos] - '0'), mex, nxt, pos + 1, (zero & (j == 0)));
        }


        return res;
    };

    for (int i = 10; i > 0; i--) {
        ll res = dfs(dfs, R, 1, i, 0, 0) - dfs(dfs, L, 1, i, 0, 0);
        if (res) {
            cout << i << " " << res << "\n";
            return;
        }
    }

    cout << 0 << " " << k + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    init();

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}