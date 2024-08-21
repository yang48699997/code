#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    s = "L" + s;
    const int inf = 1e9;
    vector<int> dp(n + 2,inf);
    dp[0] = 0;
    for (int i = 0; i <= n; i++) {
        if (s[i] == 'C' || dp[i] == inf) continue;
        if (s[i] == 'W') dp[i]++;
        if (s[i] == 'W') {
            if (i == n || s[i + 1] != 'C') dp[i + 1] = min(dp[i + 1], dp[i]);
        } else {
            for (int j = 1; j <= m && i + j <= n + 1; j++) {
                if (i + j == n + 1 || s[i + j] != 'C') dp[i + j] = min(dp[i + j], dp[i]);
            }
        }
    }
    if (dp[n + 1] <= k) cout << "YES\n";
    else cout << "NO\n";
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