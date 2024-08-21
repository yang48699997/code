#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int T;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<ll>> dp(4,vector<ll> (2));
    dp[0][1] = dp[0][0] = 1;
    dp[1][0] = dp[0][0] * 2 + dp[0][1];
    dp[1][1] = dp[0][1];
    dp[2][0] = dp[1][0] + dp[1][1];
    dp[2][1] = dp[1][0] + dp[1][1];
    dp[3][0] = dp[2][0];
    dp[3][1] = dp[2][1] * 2 + dp[2][0];
    ll ans = 1;
    for (int i = 0; i < k; i++) {
        if (1 << i & n) ans *= dp[3][1];
        else ans *= dp[3][0];
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}