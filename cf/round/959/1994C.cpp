#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int T;
void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i - 1];
    }
    vector<int> dp(n + 10);
    ll ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        ll cur = pre[i];
        auto it = upper_bound(pre.begin(), pre.end(), cur + x);
        int p = it - pre.begin();
        dp[i] = dp[p] + p - i - 1;
        ans += dp[i];
        // cerr << dp[i] << " \n"[i == 0]; 
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