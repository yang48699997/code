#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> r(n);
    vector<int> f1(m + 1), f2(m + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        r[i] = x;
        if (x == 0) continue;
        else if (x > 0) f1[x]++;
        else f2[-x]++;;
    }

    const ll inf = 1e18;
    vector<ll> dp(m + 1, -inf);
    dp[0] = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (r[i] > 0) {
            f1[r[i]]--;
        } else if (r[i] < 0) {
            f2[-r[i]]--;
        } else {
            cnt++;
            vector<ll> tmp = dp;
            for (int j = m; j >= 0; j--) {
                if (cnt >= j) dp[j] = max(dp[j], tmp[j] + f2[cnt - j]);
                if (j < m) dp[j + 1] = max(dp[j + 1], tmp[j] + f1[j + 1]);
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i <= m; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}