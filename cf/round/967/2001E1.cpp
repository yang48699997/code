#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int mod;

ll powMod(ll x, ll y) {
    ll res = 1;
    while (y) {
        if(y & 1) res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    };
    return res;
};

void solve() {
    int n, k;
    cin >> n >> k >> mod;

    vector<ll> power(n + 1);
    power[0] = 1;
    for (int i = 1; i <= n; i++) {
        power[i] = power[i - 1] * 2 % mod;
    }
    vector<vector<ll>> dp(n + 1, vector<ll> (k + 1));
    for (int i = 0; i <= k; i++) {
        dp[1][i] = 1;
    }
    vector<ll> fac(k + 1);
    fac[0] = 1;
    for (int i = 1; i <= k; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }
    vector<ll> faci(k + 1);
    for (int i = 0; i <= k; i++) {
        faci[i] = powMod(fac[i], mod - 2);
    }
    vector<ll> invv(k + 1);
    for (int i = 1; i <= k; i++) {
        invv[i] = powMod(i, mod - 2);
    }
    for (int i = 2; i <= n; i++) {
        ll cnt = power[i - 1] - 1;
        vector<ll> sum(k + 1);
        sum[0] = 1;
        for (int j = 1; j <= k / 2; j++) {
            ll res = 1;
            for (int p = 1; p <= j; p++) {
                res = res * (cnt - p + 1 + mod) % mod * invv[p] % mod;
                sum[j] = (sum[j] + res * fac[j - 1] % mod * faci[j - p] % mod * faci[p - 1]) % mod;
            }
        }
        for (int j = 1; j <= k; j++) {
            for (int p = j / 2 + 1; p <= j; p++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][p] * sum[j - p]) % mod;
            }
            dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
        }
    }
    ll ans = dp[n][k] * power[n - 1] % mod;

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