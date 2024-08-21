#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int T;
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> dp(n + 1);
    for (int i = n - 2; i >= 0; i--) {
        dp[i] = dp[i + 1];
        if (a[i] >= a[i + 1]) dp[i]++;
    }
    int c = 1;
    int ans = dp[0];
    for (int i = 1; i < n; i++) {
        ans = min(ans, c + dp[i]);
        if (a[i] >= a[i - 1]) c++;  
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