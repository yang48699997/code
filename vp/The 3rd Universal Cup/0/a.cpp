#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mx = 1e5;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    int N = mx * n;
    vector<int> dp(N + 1);
    for (int i = 0; i < n; i++) {
        vector<int> tmp = dp;
        for (int j = 0; j <= N; j++) {
            if (j >= a[i]) {
                dp[j] = min(tmp[j] + b[i], tmp[j - a[i]]);
            } else {
                dp[j] = tmp[j] + b[i];
            }
        }
    }
    int ans = N;
    for (int i = 0; i <= N; i++) {
        ans = min(ans, max(i, dp[i]));
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}