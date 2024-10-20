#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    int sum = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    int ans = sum;
    vector<int> dp(1 << n);
    for (int i = 1; i < 1 << n; i++) {
        for (int j = 0; j < n; j++) {
            if (1 << j & i) {
                dp[i] = dp[1 << j ^ i] + a[j];
                break;
            }
        }
        ans = min(ans, max(sum - dp[i], dp[i]));
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}