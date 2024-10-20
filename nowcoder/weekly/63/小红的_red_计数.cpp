#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    string s2 = s;
    reverse(s2.begin(), s2.end());

    map<string, int> mp = {
        {"", 0},
        {"r", 1},
        {"e", 2},
        {"d", 3},
        {"re", 4},
        {"ed", 5},
        {"red", 6},
    };

    auto cal = [&](string &s) -> vector<vector<ll>> {
        vector<vector<ll>> dp(n + 1, vector<ll> (7));
        for (int i = 0; i < n; i++) {
            dp[i + 1] = dp[i];
            if (s[i] == 'r') {
                dp[i + 1][1]++;
            } else if (s[i] == 'e') {
                dp[i + 1][2]++;
                dp[i + 1][4] += dp[i][1];
            } else if (s[i] == 'd') {
                dp[i + 1][3]++;
                dp[i + 1][5] += dp[i][2];
                dp[i + 1][6] += dp[i][4];
            }
        }
        return dp;
    };

    auto p1 = cal(s);
    auto p2 = cal(s2);

    auto cut = [](vector<vector<ll>> &p1, vector<vector<ll>> &p2, int l, int r) -> vector<ll> {
        vector<ll> ans(7);
        if (l > r) return ans;
        // cerr << l << " " << r << "\n";
        ans[1] = p1[r][1] - p1[l][1]; 
        ans[2] = p1[r][2] - p1[l][2]; 
        ans[3] = p1[r][3] - p1[l][3]; 
        ans[4] = p1[r][4] - p1[l][4];
        ans[4] -= (p1[r][2] - p1[l][2]) * p2[l][1];
        ans[5] = p1[r][5] - p1[l][5];
        ans[5] -= (p1[r][3] - p1[l][3]) * p2[l][2];
        ans[6] = p1[r][6] - p1[l][6];
        ans[6] -= ans[5] * p2[l][1];
        ans[6] -= ans[3] * p2[l][4];
        return ans;
    };

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;

        vector<ll> dp1 = cut(p2, p2, n - r, n - l);
        vector<ll> dp2 = cut(p1, p1, r, n);
        // cerr << l << " " << r << "\n--------------------\n";
        // for (int j = 1; j <= 6; j++) {
        //     cerr << j << ": " << dp1[j] << " " << dp2[j] << "\n";
        // }
        ll ans = p1[l][6] + dp1[6] + dp2[6];
        ans += p1[l][1] * (dp1[5] + dp2[5]);
        ans += dp1[1] * dp2[5];
        ans += p1[l][4] * (dp1[3] + dp2[3]);
        ans += dp1[4] * dp2[3];
        ans += p1[l][1] * dp1[2] * dp2[3];

        cout << ans << "\n"; 
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}