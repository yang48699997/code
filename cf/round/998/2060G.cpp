#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i][1];
    }
    
    sort(a.begin(), a.end(), [](auto &x1, auto &x2) {
        return x1[0] + x1[1] < x2[0] + x2[1];
    });

    vector<int> dp = {1, 0, 0, 1};

    for (int i = 1; i < n; i++) {
        vector<int> ndp(4);

        if (a[i][0] > a[i - 1][0] && a[i][1] > a[i - 1][1]) {
            ndp[0] |= dp[2];
            ndp[1] |= dp[1];
            ndp[2] |= dp[0];
            ndp[3] |= dp[3];
        }
        
        if (a[i][0] > a[i - 1][1] && a[i][1] > a[i - 1][0]) {
            ndp[0] |= dp[3];
            ndp[1] |= dp[0];
            ndp[2] |= dp[1];
            ndp[3] |= dp[2];
        }

        dp = ndp;
    }

    if (dp[2] || dp[3]) cout << "YES\n";
    else cout << "NO\n";
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