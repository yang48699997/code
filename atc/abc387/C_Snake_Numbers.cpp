#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll powMod(ll x, ll y) {
    ll res = 1;
    while (y) {
        if(y & 1)res = res * x;
        x = x * x;
        y >>= 1;
    };
    return res;
};

void solve() {
    ll l, r;
    cin >> l >> r;

    vector<ll> dp(20);
    for (int i = 2; i < 20; i++) {
        dp[i] = dp[i - 1];
        for (int j = 1; j < 10; j++) {
            dp[i] += powMod(0LL + j, i - 1);
        }
    }
    
    auto cal = [&](string x) -> ll {
        if (x == "9") return 0LL;

        int n = x.size();
        ll ans = dp[n - 1];

        for (int i = 1; i + '0' < x[0]; i++) {
            ans += powMod(0LL + i, n - 1);
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j + '0' < min(x[0], x[i]); j++) {
                ans += powMod(0LL + x[0] - '0', n - i - 1);
            }
            if (x[i] >= x[0]) break;
            if (i == n - 1) ans++;
        }
        return ans;
    };

    cout << cal(to_string(r)) - cal(to_string(l - 1)) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}