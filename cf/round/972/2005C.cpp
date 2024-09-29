#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    
    const int inf = 1e9;
    vector<vector<int>> dp(5, vector<int> (5, -inf));
    dp[0][0] = 0;
    string t = "narek";
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vector<vector<int>> dp2 = dp;
        for (int j = 0; j < 5; j++) {
            int cnt = 0;
            int now = j;
            int res = 0;
            for (char c : s) {
                if (c == t[now]) {
                    now++;
                    now %= 5;
                    res++;
                } else if (c == t[0] || c == t[1] || c == t[2] || c == t[3] || c == t[4]) cnt++;
            }
            for (int k = 0; k < 5; k++) {
                dp2[k][now] = max(dp2[k][now], dp[k][j] + res - cnt);
            }
        }
        dp = dp2;
    }
    int ans = 0;
    for (int i = 0; i < 5; i++) {
        ans = max(ans, dp[0][i] - i * 2);
    }
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