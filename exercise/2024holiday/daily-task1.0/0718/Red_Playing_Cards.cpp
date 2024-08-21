#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n * 2);
    vector<vector<int>> pos(n);
    for (int i = 0; i < n * 2; i++) {
        cin >>  a[i];
        pos[a[i] - 1].push_back(i);
    }
    int ans = 0;
    vector<int> mx(n);
    for (int i = n - 1; i >= 0; i--) {
        int p1 = pos[i][0];
        int p2 = pos[i][1];
        int len = p2 - p1 + 1;
        vector<int> dp(len);       
        dp[0] = i + 1;
        int x = i + 1;
        for (int j = 1; j < len - 1; j++) {
            dp[j] = dp[j - 1];
            if (p1 + j != pos[a[p1 + j] - 1][1] || a[p1 + j] <= x || pos[a[p1 + j] - 1][0] < p1) dp[j] += x;
            else dp[j] = max(dp[j] + x, dp[pos[a[p1 + j] - 1][0] - p1 - 1] + mx[a[p1 + j] - 1]);
        } 
        mx[i] = dp[len - 2] + x;
        // cerr << mx[i] << "\n";
    }
    vector<int> dp(n * 2 + 1);
    for (int i = 0; i < n * 2; i++) {
        int x = a[i] - 1;
        dp[i + 1] = dp[i];
        if (i == pos[x][1]) dp[i + 1] = max(dp[i + 1], dp[pos[x][0]] + mx[x]);
    }
    cout << dp[n * 2] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}