#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    const ll inf = 1e18;
    vector<ll> dp(n + 1, -inf);
    dp[0] = 0;

    int ok = 1;
    while (k--) {
        for (int i = n - 1; i >= 0; i--) {
            ll mx = -inf;
            if (i) mx = dp[i];
            if (ok && i <= 5) mx = max(mx, 0LL);
            for (int p = 1; p <= 6; p++) {
                if (i - p + 1 <= 0) break;
                mx = max(mx, dp[i - p + 1]);
            }
            dp[i + 1] = mx + a[i];
        }
        ok = 0;
    }

    cout << *max_element(dp.begin() + 1, dp.end()) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}